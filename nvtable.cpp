#include "nvtable.h"
#include <QScopedPointer>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlField>
#include <QUuid>
#include "qloggerwriter.h"
#include "connectionstringbuilder.h"


nvTable::nvTable(QObject *parent) : QObject(parent), commitOnly(false)
{

}

void nvTable::initialize(const QString tableName, const QString dsnString)
{
    this->tableName = tableName;
	this->setSourceDSN(dsnString);
    openDatabaseAndGetFieldList();
}

//************************************
// Method:    openDatabaseAndGetFieldList
// FullName:  nvTable::openDatabaseAndGetFieldList
// Access:    public 
// Returns:   void
// Qualifier:  Open and retrieve the field list from the source DSN.  
//************************************
void nvTable::openDatabaseAndGetFieldList()
{

    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
    QUuid m_uid = QUuid::createUuid();
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3", m_uid.toString());
        db.setDatabaseName(this->strDsnString);
        db.setConnectOptions(QString(builder->getOdbcAttributes()));
        db.database(m_uid.toString(), false);
        if (!db.isOpen()) db.open();

#ifdef _DEBUG
        QString tx = db.databaseName();
        QString errorOpen = db.lastError().text();
#endif

        if (db.isOpen())
        {
			QString stmt = QString("select f.rdb$relation_name,RDB$FIELD_NAME,f.RDB$FIELD_SOURCE from rdb$relations r,RDB$RELATION_FIELDS f ");
			stmt.append(" where r.RDB$RELATION_NAME = f.RDB$RELATION_NAME and r.rdb$system_flag <> 1  ");
            stmt.append(QString(" and f.rdb$relation_name = '%1'").arg(this->tableName.trimmed()));
			stmt.append(" order by f.RDB$RELATION_NAME, f.rdb$field_id");
            QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
            qry->exec(stmt);
            while (qry->next())
            {
                QSqlRecord record = qry->record();
#ifdef _DEBUG
                QSqlField rdb$relation_name(record.field("RDB$RELATION_NAME"));
#endif
                QSqlField rdb$field_source(record.field("RDB$FIELD_SOURCE"));
                QSqlField rdb$field_name(record.field("RDB$FIELD_NAME"));
                //QString tableName(rdb$relation_name.value().toString().trimmed());
                QString fieldName(rdb$field_name.value().toString().trimmed());
                QString fieldSource(rdb$field_source.value().toString().trimmed());

                updateCommands(fieldName,getFieldTypeSize(fieldSource));
            }
            qry->finish();

            //  Clean up the Sql Statements

           QString creStmt(QString("create table %1 ( %2)").arg(this->tableName.trimmed()).arg(createTableSQL));
		   creStmt.replace(",)", ")");
           this->createTableSQL = creStmt;
		   
		   insertValues.append(","); insertValues.replace(",,", "");
           QString insStmt(QString("Insert into %1 ( %2) values ( %3)").arg(tableName).arg(insertSQL).arg(insertValues));
           this->insertSQL = insStmt;
		   insertSQL.replace(",)", ")");
		   
           QString updStmt(QString("Update %1 set %2 where area=? and page=? and line=?").arg(tableName).arg(updateSQL));
           updateSQL = updStmt;
		   updateSQL.replace(", where", " where");
		   selectSQL.append(",");
		   QString selectStmt(QString("select %1 from %2").arg(selectSQL).arg(tableName));
		   selectSQL = selectStmt;
		   selectSQL.replace(",,", " ");

        }
        db.close();
    }
    QSqlDatabase::removeDatabase(m_uid.toString());
}

void nvTable::updateCommands(QString FieldName, QString FieldSource)
{

    // Create Statement

    this->createTableSQL.append(QString(" %1 %2,")
                                .arg(getSafeFieldName(FieldName))
                                .arg(FieldSource.toUpper()));

    // Insert Statement
    this->insertSQL.append(QString("%1,").arg(getSafeFieldName(FieldName)));
    this->insertValues.append("?,");

    // Update Statement
    this->updateSQL.append(QString("%1=?,").arg(getSafeFieldName(FieldName)));
	this->selectSQL.append(QString("%1,").arg(FieldName));
}

QString nvTable::getSafeFieldName(QString str)
{
    QString safeName = str;
    if (str.contains("DB_ID")) safeName="PlantCode";
    if (str.contains("DBID")) safeName="PlantCode";
    return safeName.trimmed().toUpper();
}

QString nvTable::getFieldTypeSize(const QString str)
{

    int savedValue = -1;
           QRegExp rx0(str.trimmed());
           QRegExp rx1("(\\d+)");
           int pos = 0;
           rx0.setPatternSyntax(QRegExp::Wildcard);
           // check if character
           if (
               (str.contains("SQL$")) &&
               (str.contains("CHR")))
           {
               while ((pos = rx1.indexIn(str,pos)) != -1)
               {
                   savedValue = rx1.cap(1).toInt();
                   pos += rx1.matchedLength();

               }
               return QString(" varchar(%1) ").arg(savedValue);
               //return savedValue;
           }
           if (rx0.exactMatch("SQL$INT"))
           {
               return QString(" int ");
           }
           if (rx0.exactMatch("SQL$FLT"))
           {
               return QString(" double precision ");
           }
           if (rx0.exactMatch("SQL$SML"))
           {
               return QString(" smallint ");
           }
           if (rx0.exactMatch("SQL$TSP2"))
           {
               return  QString(" datetime ");
           }
       #ifdef _DEBUG
    //       QLogger::QLog_Debug("createTableRdb",QString("Class_MSG: GetFieldTypeSize %1 ").arg(QString("field: %1 -> %2").arg(str).arg(normalField)));
       #endif
           return QString();
}

QVariant nvTable::getVariantType(const QString str)
{
   QRegExp rx0(str.trimmed());
   QRegExp rx1("(\\d+)");
   //int pos = 0;
   rx0.setPatternSyntax(QRegExp::Wildcard);
   // check if character
   if (
       (str.contains("SQL$")) &&
       (str.contains("CHR")))
   {
       return QVariant::String;
   }
   if (rx0.exactMatch("SQL$INT"))
   {
       return QVariant::Int;
   }
   if (rx0.exactMatch("SQL$FLT"))
   {
       return QVariant::Double;
   }
   if (rx0.exactMatch("SQL$SML"))
   {
       return QVariant::Int;
   }
   if (rx0.exactMatch("SQL$TSP2"))
   {
       return QVariant::DateTime;
   }
   return QVariant::String;
}
