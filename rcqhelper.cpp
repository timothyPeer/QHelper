#include "rcqhelper.h"
#include <QScopedPointer>
#include <QDebug>
#include <QUuid>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QListWidgetItem>
#include "connectionstringbuilder.h"
#include "createnewprofile.h"
#include "../NvLibQ/qnvprofiles.h"
#include "../NvLibQ/modelnvprofiles.h"
#include "../NvLibQ/nvProfilesClass.h"
#include "dbcheckobj.h"



RcQHelper::RcQHelper(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mydelegate = new helperDelegate(this);
    m_uuid = QUuid::createUuid();

    ui.pushButton_configureProfiles->setEnabled (false);
	{
		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
		QString tmp = builder->createEnvyRcq();
		if (!tmp.isEmpty())
		{
			QString tmpX = "ctor.createEnvyRcq()";
			tmpX.append("connectionStringBuilder Error\n");
			tmpX.append("%1\n").arg(tmp);
			return;
		}
	}
}

RcQHelper::~RcQHelper()
{


	QSqlDatabase::removeDatabase(m_uuid.toString());


}

void RcQHelper::initialize(const QString profileName)
{
	{
		QScopedPointer<modelNvProfilesPrivate> modelProf(new modelNvProfilesPrivate());
		modelProf->initialize(profileName);
		auto * profClass = modelProf->fetch_current(profileName);
		QScopedPointer<CreateNewProfile> prof(new CreateNewProfile(this));
		prof->initialize(profClass);
		prof->exec();


	}
}

void RcQHelper::on_pushButton_ok_clicked()
{
	this->close();
}

void RcQHelper::on_pushButton_loadProfiles_clicked()
{
	refreshProfileList();   
}

void RcQHelper::on_listView_Profiles_currentChanged(const QModelIndex & current, const QModelIndex & previous)
{
	QString  profileName(current.data().toString());
}

void RcQHelper::onListView_ProfilesCellClicked(const QModelIndex &index)
{
	int row = index.row();
	QString  profileName = index.sibling(row,0).data().toString();
}



void RcQHelper::LoadNvTables(const QString connectionStringRdb, const QString profileName)
{
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
		QUuid uuid = QUuid::createUuid();
		{

			db = QSqlDatabase::addDatabase("QODBC", uuid.toString());
			db.setDatabaseName(connectionStringRdb);
			db.setConnectOptions(builder->getOdbcAttributes());
			db.database(m_uuid.toString(), false);
			db.open();
			if (!db.isOpen()) return;

			tableList = db.tables();
			{
				foreach(QString str, tableList)
				{
					prepareTable(connectionStringRdb, str, profileName);
				}
			}

			db.close();
		}
		QSqlDatabase::removeDatabase(uuid.toString());
	}



}



void RcQHelper::insertNvTable(const QString profileName, const QString tableName, const QString fetchSQL, const QString insertSQL, const QString updateSQL,int fieldCnt)
{
	{
		//QString		sourceDSN;
		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
		QUuid uuid = QUuid::createUuid();
		{

			QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", uuid.toString());
			db.setDatabaseName(builder->getEnvyConnectionString());
			db.setConnectOptions(builder->getOdbcAttributes());
			db.database(m_uuid.toString(), false);

			db.open();
			if (!db.isOpen()) return;

			QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
			QString tmp;
			tmp = QString("insert into nvtables(profileName, tableName, fetchSql,insertSql, updateSql, fieldCnt) values ('1%','2%','3%','4%','5%',6%)")
				.arg(profileName).arg(tableName).arg(fetchSQL).arg(insertSQL).arg(updateSQL).arg(fieldCnt);
			qry->prepare(tmp);
			qry->exec();
			qry->clear();
			db.close();
		}
		QSqlDatabase::removeDatabase(uuid.toString());
	}
}

QString RcQHelper::getSafeField(QString fField)
{
    QString tField;
    tField = QString (fField.trimmed());
    if (tField.contains ("db_id",Qt::CaseInsensitive))
	{
		return "Plant_Code";
	}
	return tField;
}

void RcQHelper::refreshProfileList()
{

	QApplication::setOverrideCursor(Qt::WaitCursor);
	ui.tabWidget->setCurrentIndex(0);
	ui.listWidget->show();
	{
		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
		QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_uuid.toString());
		{
			db.setDatabaseName(builder->getEnvyConnectionString());
			db.setConnectOptions(builder->getOdbcAttributes());
			db.database(m_uuid.toString(), false);
			db.open();
	
			if (db.isOpen())
			{
				QScopedPointer< QSqlQuery> qry(new QSqlQuery(db));
				qry->exec("select profilename from nvprofiles");
				while (qry->next())
				{
					QSqlRecord rec = qry->record();
					QSqlField field = rec.field(0);
					ui.listWidget->addItem(new QListWidgetItem(field.value().toString()));
				}
				qry->finish();
			}
			db.close();
		}
	}
	QSqlDatabase::removeDatabase(m_uuid.toString());
	QApplication::restoreOverrideCursor();
}

void RcQHelper::prepareTable(QString connectionStringRdb,  const QString tableName, const QString profileName)
{
	{
		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
		QUuid uuid = QUuid::createUuid();
		{
			QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", uuid.toString());
			db.setDatabaseName(connectionStringRdb);
			db.setConnectOptions(builder->getOdbcAttributes());
			db.database(uuid.toString(), false);
			db.open();
			if (!db.isOpen()) return;

			QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));

			// we should extract for all tables here.

			QString stmt = "select RDB$RELATION_NAME,RDB$FIELD_NAME,";
			stmt.append("RDB$FIELD_SOURCE,");
			stmt.append("RDB$FIELD_ID FROM RDB$RELATION_FIELDS ");
			stmt.append(" WHERE RDB$RELATION_NAME = '");
			stmt.append(tableName.trimmed());
			stmt.append("' ");
			stmt.append(" ORDER BY ");
			stmt.append(" RDB$RELATION_NAME, RDB$FIELD_POSITION");

			qry->prepare(QString(stmt));
			qry->exec();

			int cnt = 0;
			QStringList lstNames;
			QStringList lstType;
			QStringList lstSize;
			QString fetchSql, insertSql, updateSql;
			QString insertParams;
			QString updateParams;
			fetchSql.append("select ");
			insertSql.append(QString("insert into %1 (").arg(tableName));
			updateSql.append(QString("update %1 set ").arg(tableName));

			while (qry->next())
			{
				QSqlRecord rec = qry->record();
				QString fTable = rec.value(0).toString(); //RDB$RELATION_NAME
				QString fField = rec.value(1).toString(); //RDB$FIELD_NAME
				QString fType = rec.value(2).toString();  //RDB$FIELD_SOURCE
				fetchSql.append(QString("%1,").arg(fField.trimmed()));
				insertSql.append(QString(" %1,").arg(getSafeField(fField)));
				insertParams.append("?,");
				updateParams.append(QString(" %1=?,").arg(getSafeField(fField)));
				cnt++;
			}
			qry->finish();
			insertSql.append(")");
			insertSql.replace(",)", ") values (");
			insertSql.append(QString("%1)").arg(insertParams));
			insertSql.replace(",)", ")");

			updateParams.append(",");
			updateSql.append(updateParams);

			updateSql.replace(",,", "");
			fetchSql.append(",");
			fetchSql.replace(",,", QString(" from %1").arg(tableName));
			//insertNvTable(profileName, tableName, fetchSql, insertSql, updateSql, cnt);
			QString tmp;
			tmp = QString("insert into nvtables(status,profileName, tableName, fetchSql,insertSql, updateSql, fieldCnt,preferredSelectSQL,preferredInsertSQL,preferredUpdateSQL) values (0,'%1','%2','%3','%4','%5',%6,'%7','%8','%9')")
				.arg(profileName)
				.arg(tableName)
				.arg(fetchSql)
				.arg(insertSql)
				.arg(updateSql)
				.arg(cnt)
				.arg(fetchSql)
				.arg(QString("insert into %1 ").arg(tableName))
				.arg(QString("update %1").arg(tableName));
			tmp.toUpper();
			CrudList.append(tmp);
			qDebug() << tmp;

			// store the SQL Statement in the nvtables table

			QScopedPointer<QSqlQuery> qryStore(new QSqlQuery(db));
			qryStore->exec(tmp);
			qryStore->finish();

			db.close();
		}
		QSqlDatabase::removeDatabase(uuid.toString());
	}
}

void RcQHelper::on_pushButton_clicked()
{
	this->close();
}



/// <summary>
/// Ons the push button cancelled clicked.
/// </summary>
void RcQHelper::on_pushButton_cancelled_clicked()
{
    this->close ();
}

/// <summary>
/// Ons the push button configure profiles clicked.
/// </summary>
void RcQHelper::on_pushButton_configureProfiles_clicked()
{

    // for each table in profile
    // Delete from nvtables where profileName = 'profile'
    // Statements
        // create table Statement
        // Insert into tablename where table = 'table'
        // update table

    int count = ui.listWidget_tables->count ();
    for (int index = 0; index < count; index++)
    {
        QListWidgetItem *item = ui.listWidget_tables->item(index);
         prepareTable(dsnConnectionString,item->data (0).toString (), profileName);
    }



}

/// <summary>
/// Ons the push button add profile clicked.
/// </summary>
void RcQHelper::on_pushButton_AddProfile_clicked()
{
	{
		QScopedPointer<CreateNewProfile> prof(new CreateNewProfile(this));
		prof->exec();
	}
  refreshProfileList();
}

/// <summary>
/// Ons the list view profiles double clicked.
/// </summary>
/// <param name="index">The index.</param>
void RcQHelper::on_listView_Profiles_doubleClicked(const QModelIndex &index)
{


	 QListWidgetItem * item = ui.listWidget->currentItem();
	 QString profileName = item->text();

}

/// <summary>
/// Ons the list widget double clicked.
/// </summary>
/// <param name="index">The index.</param>
void RcQHelper::on_listWidget_doubleClicked(const QModelIndex &index)
{
    //QScopedPointer<qNvProfiles> reg(new qNvProfiles(this));

	QListWidgetItem * item = ui.listWidget->currentItem();
	QString profileName = item->text();
    
    {
		QScopedPointer<modelNvProfilesPrivate> modelPtr(new modelNvProfilesPrivate());
	    nvProfilesClass *dataClass = modelPtr->fetch_current (profileName);
	    //reg->initialize(profileName);
		QScopedPointer<CreateNewProfile> profNew(new CreateNewProfile(this));
		profNew->initialize(dataClass);
		profNew->setEditEnabled();
		profNew->exec();
	
	    QString rdbDSN = dataClass->getProfileSourceDSN ();
	    dsnConnectionString = rdbDSN;
	}

    {
		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
	    QScopedPointer<dbCheckObj> dbObj(new dbCheckObj(this));
	    dbObj->initialize (builder->getEnvyConnectionString ());
	}
   // ui.listWidget_tables->addItems (dbObj->SQLTables());

    this->profileName = profileName;
    ui.pushButton_configureProfiles->setEnabled (true);
	qDebug() << index;
	

}

/// <summary>
/// Ons the list widget tables double clicked.
/// </summary>
/// <param name="index">The index.</param>
void RcQHelper::on_listWidget_tables_doubleClicked(const QModelIndex &index)
{

}
