#include "clstablefields.h"
#include <QPointer>
#include <QUuid>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlRecord>
#include <QSqlField>
#include <vtifields.h>


clsTableFields::clsTableFields(QObject *parent) : QObject(parent)
{

}

clsTableFields::~clsTableFields()
{
    clear();
}

void clsTableFields::clear()
{

}

void clsTableFields::init(const QString connectionString)
{
	m_uid = QUuid::createUuid();
	stmt = QString("select f.rdb$relation_name,RDB$FIELD_NAME,f.RDB$FIELD_SOURCE from rdb$relations r,RDB$RELATION_FIELDS f where r.RDB$RELATION_NAME = f.RDB$RELATION_NAME and r.rdb$system_flag <> 1 order by f.RDB$RELATION_NAME, f.rdb$field_id;");
	dataSourceConnectionString = connectionString;
	db.setDatabaseName(dataSourceConnectionString);
	db.setConnectOptions(QString("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3"));
	db.database(m_uid.toString(), false);
}

void clsTableFields::close()
{
	db.close();
	QSqlDatabase::removeDatabase(m_uid.toString());
}


void clsTableFields::initialize(const QString DSN, const QString profile_Name, const QString table_Name)
{

    clear();
	
    setDataSourceConnectionString(DSN);
	init(DSN);
    setProfileName(profile_Name);
    setTableName(table_Name);
    loadFieldsToTable(DSN);

    QMultiHash<QString, vtiFields*>::iterator i = tableFields.find(table_Name);
        while (i != tableFields.end() && i.key() == table_Name) 
		{
            fieldInfo.append(i.value());
            ++i;
        }
        // populate the table columns
		QList<vtiFields*> myList = fieldInfo;
		fieldInfo = clsTableFields::reverseStringList(myList);
        buildString();
}


void clsTableFields::loadFieldsToTable(const QString connectionString)
{
            if (!db.isOpen()) db.open();

            QString tx = db.databaseName();
            QString errorOpen = db.lastError().text();
			if (db.isOpen())
			{
				QSqlQuery qry(db);
				qry.exec(stmt);
				while (qry.next())
				{
					QSqlRecord record = qry.record();
					QSqlField rdb$relation_name(record.field("RDB$RELATION_NAME"));
					QSqlField rdb$field_source(record.field("RDB$FIELD_SOURCE"));
					QSqlField rdb$field_name(record.field("RDB$FIELD_NAME"));
					QString tableName(rdb$relation_name.value().toString().trimmed());
					QString fieldName(rdb$field_name.value().toString().trimmed());
					QString fieldSource(rdb$field_source.value().toString().trimmed());

					vtiFields * vTableInfo = new vtiFields(this);
					vTableInfo->setFieldName(fieldName.trimmed());
					//vTableInfo->setFieldType(vtiFields::getVariantType(fieldSource));
					//vTableInfo->setTableName(this->tableName.trimmed());
					//tableFields.insert(tableName, vTableInfo);     // Add to the table hash... we use this collection to build the SQL Statements
				}
				qry.finish();
			}
    

   
}

QString clsTableFields::getPreferredSelectSQL()
{
    return preferredSelectSQL;
}

QString clsTableFields::getPreferredInsertSQL()
{
    return preferredInsertSQL;
}

QString clsTableFields::getPreferredUpdateSQL()
{
    return preferredUpdateSQL;
}


void clsTableFields::buildString()
{
    QString preferredSelect;
    QString preferredInsert;
    QString preferredUpdateParams;
    preferredInsert.append("insert into ^&*# (");
    preferredSelect.append("select ");
    preferredUpdateParams.append("update ^&*# ");
    vtiFields* item0 = nullptr;
    bool isSet = false;
	


    foreach(item0, fieldInfo)
    {

        // select

        preferredSelect.append(QString("%1,").arg(item0->getFieldName()));
        // preferredSelectParams.append("%1,").arg(item0->name());
        // insert

        // insert params
        preferredInsert.append(QString("%1,").arg(item0->getTargetFieldName()));
        if (!isSet) {
            preferredInsert.replace("^&*#",QString("%1").arg(item0->getTableName()));
            preferredUpdateParams.replace("^&*#",QString("%1").arg(item0->getTableName()));
        }
        isSet = true;
        // Update

        preferredUpdateParams.append(QString("set %1 = ?,").arg(item0->getTargetFieldName()));
        // update params
    }

    preferredSelect.append(",");
    // preferredSelectParams.append(",");
    preferredInsert.append(",");
    preferredUpdateParams.append(",");
    // remove ",,"
    preferredSelect.replace(",,"," from ");
	preferredSelect.append(QString(" %1").arg(tableName));
    //preferredSelectParams.replace(",,","");
    preferredInsert.replace(",,","");
    preferredUpdateParams.replace(",,","");


    // Add Insert - VALUES parameters
    preferredInsert.append(" ) values (");

    vtiFields* item1;
    item1 = nullptr;
    foreach(item1, fieldInfo)
    {

        // insert params
        preferredInsert.append("?,");
        // Update

        // update params
    }
    preferredInsert.append(",");
    preferredInsert.replace(",,",")");

    // Add the Where DBKEY Section

    preferredUpdateParams.append(" where area = ? and page = ? and line = ?");

    // Final Task... update the preferred SQL properties

    setFieldCnt(fieldInfo.count());
    setPreferredSelectSQL(preferredSelect);
    setPreferredInsertSQL(preferredInsert);
    setPreferredUpdateSQL(preferredUpdateParams);  // The count of fieldCnt is actual + 3 -- added a where area= and page = and line = predicate
}

void clsTableFields::commitToDatabase()
{
    QString nvtablesSQL;
    nvtablesSQL.append("insert into nvtables ('%1',"); // ProfileName
    nvtablesSQL.append(QString("'%1',").arg(tableName)); // TableName
    nvtablesSQL.append("0,"); // Status
    nvtablesSQL.append(QString("'%1',").arg(this->preferredSelectSQL)); // PreferredSelectSQL
    nvtablesSQL.append(QString("'%1',").arg(this->preferredInsertSQL)); // PreferredInsertSQL
    nvtablesSQL.append(QString("'%1',").arg(this->preferredUpdateSQL)); // PreferredUpdateSQL
    nvtablesSQL.append(QString("'%1',").arg(this->getFieldCnt())); // FieldCnt
    nvtablesSQL.append(",,"); // Terminate List
    nvtablesSQL.replace(",,",")"); // Finalize the Insert Statement

//    QScopedPointer< vtLExecute> vte;
//    vte.reset(new vtLExecute(this));
//    vte->setDefaultDSN();
//    vte->setSqlStatement(nvtablesSQL);
//    vte->process();

}
