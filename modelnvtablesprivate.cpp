#include "modelnvtablesprivate.h"
#include <QScopedPointer>
#include "connectionstringbuilder.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QUuid>
#include "qclogobject.h"

modelNvTablesPrivate::modelNvTablesPrivate() 

{

    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
	// Pointer

	m_Log = new qCLogObject(nullptr);
	//m_pTableModel = new QSqlTableModel(nullptr,db);

}

modelNvTablesPrivate::~modelNvTablesPrivate() {
	
	
	//if (m_pTableModel)	delete m_pTableModel;
	if (m_Log) delete m_Log;
}

void modelNvTablesPrivate::beginTransaction()
{
// 	m_pTableModel->database().transaction();
// 	m_rowCursor = m_pTableModel->rowCount();
}

bool modelNvTablesPrivate::createTable(const QString createTableSQL)
{
	bool bValue = false;
	QUuid m_uid = QUuid::createUuid();
	QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setDatabaseName(builder->getEnvyConnectionString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);
	if (!db.open()) db.open();
	if (db.isOpen())
	{
		QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
		QString tSql("create table if not exists ");
		tSql.append(QString(createTableSQL));
		bValue = qry->exec(tSql);
		qry->finish();
		db.close();
	}
	QSqlDatabase::removeDatabase(m_uid.toString());

    return bValue;
}

void modelNvTablesPrivate::deleteRow(nvTablesClass * clsObj)
{
	QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
	QUuid m_uid = QUuid::createUuid();
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setDatabaseName(builder->getEnvyConnectionString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);
	if (!db.open()) db.open();
	if (db.isOpen())
	{
		QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
		QString td;
		td = QString("delete from nvTables where profilename = '%1' and tablename='%2'").arg(clsObj->m_strProfileName).arg(clsObj->getTableName());
		qry->prepare(td);
		if (!qry->exec())
		{
			QString tmp(qry->lastError().text());
			qDebug() << tmp;
			m_Log->log(enumerateClass::ErrorLevel, QString("Failed to delete rows - %1\n%2").arg("modelNvProfilesPrivate::deleteRow").arg(tmp));
			//m_Log->log(enumateClass::ErrorLevel, QString("Failed to delete row - %1").arg("modelNvTablesPrivate::deleteRow"));
		}
		QString t;
		t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
			.arg(clsObj->m_strProfileName)
			.arg(builder->getEnvyConnectionString())
			.arg(clsObj->m_strTableName)
			.arg(clsObj->m_uFieldCnt);
		m_Log->log(enumerateClass::InfoLevel, t);
		
		qry->finish();
		db.close();
		
	}
	refresh();
	QSqlDatabase::removeDatabase(m_uid.toString());
}

void modelNvTablesPrivate::endTransaction()
{
	//commit();
}

void modelNvTablesPrivate::fetch()
{
	refresh();
}

QList<nvTablesClass*> modelNvTablesPrivate::fetch_current(const QString profileName)
{
	QList<nvTablesClass*> pTableList;
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
	initialize(profileName);
	QUuid m_uid = QUuid::createUuid();
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setDatabaseName(builder->getEnvyConnectionString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);
	if (!db.open()) db.open();
	if (db.isOpen())
	{
		QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
		qry->prepare(QString("%1 where profilename = '%2'").arg(builder->getNvTablesSelect()).arg(profileName));
		if (!qry->exec())
		{
// 			qDebug() << qry->lastError().text();
// 			m_Log->log(enumateClass::ErrorLevel, QString("Failed to insert rows - %1").arg(qry->lastError().text()));
			QString tmp(qry->lastError().text());
			qDebug() << tmp;
			m_Log->log(enumerateClass::ErrorLevel, QString("Failed to fetch rows - %1\n%2").arg("modelNvProfilesPrivate::fetch_current").arg(tmp));

		}

		
		while (qry->next())
		{
			auto * clsObj = new nvTablesClass(nullptr);
			QSqlRecord rec = qry->record();
			clsObj->m_strProfileName = rec.value("profilename").toString();
			clsObj->m_strTableName = rec.value("tableName").toString();
			clsObj->m_uFieldCnt = rec.value("FieldCnt").toInt();
			clsObj->m_strPreferredSelect = rec.value("preferredSelectSQL").toString();
			clsObj->m_strPreferredInsert = rec.value("preferredInsertSQL").toString();
			clsObj->m_strPreferredUpdate = rec.value("preferredUpdateSQL").toString();
			clsObj->m_fetchSQL = rec.value("FetchSQL").toInt();
			clsObj->m_insertSQL = rec.value("InsertSQL").toInt();
			clsObj->m_updateSQL = rec.value("UpdateSQL").toInt();
			pTableList.append(clsObj);
		}
		qry->finish();
		db.close();
	}
	QSqlDatabase::removeDatabase(m_uid.toString());

	return pTableList;
}

void modelNvTablesPrivate::initialize(const QString dsn, const QString tableName)
{
	m_StrConnect = dsn;
	initialize(tableName);
}

void modelNvTablesPrivate::initialize(const QString tableName)
{
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(nullptr));
    m_StrConnect = builder->getEnvyConnectionString ();
//     db.setDatabaseName(builder->getEnvyConnectionString ());
// 	db.open();
// 	qDebug() << db.lastError().text();
	m_strTableName = tableName;
    createTable(builder->getNvTablesCreate());
// 	m_pTableModel->setTable(tableName);
// 	m_pTableModel->select();
}

void modelNvTablesPrivate::insertRow(nvTablesClass *clsObj)
{
	//deleteRow(clsObj);
	{
		QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(nullptr));
		QUuid m_uid = QUuid::createUuid();
		QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
		db.setDatabaseName(builder->getEnvyConnectionString());
		db.setConnectOptions(builder->getOdbcAttributes());
		db.database(m_uid.toString(), false);
		{
			QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));

			if (!db.open()) db.open();
			if (db.isOpen())
			{
				QString tmp(clsObj->getInsertSqlStatement());
				qry->prepare(tmp);
				if (!qry->exec())
				{
					QString tmp(qry->lastError().text());
					qDebug() << tmp;
					m_Log->log(enumerateClass::ErrorLevel, QString("Failed to insert rows - %1\n%2").arg("modelNvProfilesPrivate::insert").arg(qry->lastError().text()));
				}
				QString t;
				t = QString("Profile: %1 \n Repository: %2\n TableName: %3\n FieldCnt: %4")
					.arg(clsObj->m_strProfileName)
					.arg(builder->getEnvyConnectionString())
					.arg(clsObj->m_strTableName)
					.arg(clsObj->m_uFieldCnt);
				m_Log->log(enumerateClass::InfoLevel, t);
				qry->finish();
				db.close();
			}
		}
		refresh();
		QSqlDatabase::removeDatabase(m_uid.toString());
	}
}

void modelNvTablesPrivate::refresh()
{
// 	if (m_pTableModel)
// 	{
//         m_pTableModel->submit();
// 		m_pTableModel->select();
// 		m_rowCursor = m_pTableModel->rowCount();
// 	}
}

void modelNvTablesPrivate::update(nvTablesClass * clsObj)
{
	QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(nullptr));
	QUuid m_uid = QUuid::createUuid();
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setDatabaseName(builder->getEnvyConnectionString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
	if (!db.open()) db.open();
	if (db.isOpen())
	{
		qry->prepare(clsObj->getUpdateSqlStatement());
		if (!qry->exec())
		{
			m_Log->log(enumerateClass::ErrorLevel, QString("Failed to Update rows - %1").arg("modelNvTablesPrivate::update"));
		}
		QString t;
		t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
			.arg(clsObj->m_strProfileName)
			.arg(builder->getEnvyConnectionString())
			.arg(clsObj->m_strTableName)
			.arg(clsObj->m_uFieldCnt);
		m_Log->log(enumerateClass::InfoLevel, t);
		delete clsObj;
		qry->finish();
		db.close();
	}
	QSqlDatabase::removeDatabase(m_uid.toString());
	refresh();
}

void modelNvTablesPrivate::close()
{

	//db.close();
}
