#include "modelNvProfilesPrivate.h"
#include "qclogobject.h"
#include "connectionstringbuilder.h"
#include <QScopedPointer>

namespace { QSqlDatabase			db; }

modelNvProfilesPrivate::modelNvProfilesPrivate() :
	
    m_pTableModel(new QSqlTableModel()), bIsEditOnly(false)
   // cls(new connectionStringBuilder())
{
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
	m_uid = QUuid::createUuid();
	 db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());

    db.setDatabaseName(builder->getEnvyConnectionString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);

	// Pointer

	//cls = new qClsRegister(nullptr);
	m_Log = new qCLogObject(nullptr);
	//m_pTableModel = new QSqlTableModel();
    m_strEnvyDSN = builder->getEnvyConnectionString ();
}

modelNvProfilesPrivate::~modelNvProfilesPrivate() {
	
    //if (cls) delete cls;
	if (m_pTableModel)	delete m_pTableModel;

	close();
	QSqlDatabase::removeDatabase(m_uid.toString());
	if (m_Log) delete m_Log;

}

nvProfilesClass* modelNvProfilesPrivate::fetch_current(const QString profileName)
{
	nvProfilesClass *clsObj = new nvProfilesClass(nullptr);
	QUuid uuid = QUuid::createUuid();
	bool valid = false;
	QSqlDatabase db2 = QSqlDatabase::addDatabase("QODBC", uuid.toString());
	{
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
		db2.setConnectOptions(builder->getOdbcAttributes());
		db2.database(uuid.toString(), false);
        QString repoDsn(m_strEnvyDSN);
		db2.setDatabaseName(repoDsn);
		if (!db2.isOpen()) db2.open();
		QString err1 = db2.lastError().text();
        //QSqlQuery qry(db2);
        QScopedPointer<QSqlQuery> qry(new QSqlQuery(db2));

        QString strQ(QString("%1 where profilename = '%2'").arg(builder->getNvProfilesSelect ()).arg(profileName));
        qry->prepare(strQ);
        if (!qry->exec())
		{
            QString tmp(qry->lastError ().text ());
            m_Log->log(enumerateClass::ErrorLevel, QString("Failed to insert rows - %1\n%2").arg("modelNvProfilesPrivate::insert").arg(tmp));
		}
        err1 = qry->lastError().text();
        while (qry->next())
		{
            QSqlRecord rec = qry->record();
            clsObj->setProfileName (rec.value("ProfileName").toString());
            clsObj->setProfileSourceDSNString (rec.value("ProfileSourceDSN").toString());
            clsObj->setProfileTargetDSNString (rec.value("ProfileTargetDSN").toString());
            clsObj->setCommitThrottle (rec.value("CommitThrottle").toInt());
            clsObj->setExecutionThreads (rec.value("ExecutionThreads").toInt());
			clsObj->setProfileAutoCommitEnabled(rec.value("ProfileAutoCommitEnabled").toInt());
			clsObj->setProfileDescription(rec.value("ProfileDescription").toString());
			clsObj->setProfileEnabled(rec.value("ProfileEnabled").toInt());
			clsObj->setProfileTraceEnabled(rec.value("ProfileTraceEnabled").toInt());
			clsObj->setProfileLogFile(rec.value("NvLogFile").toString());
			clsObj->setProfileTraceEnabled(rec.value("ProfileTraceEnabled").toInt());
			clsObj->setProfileTransactionLogLevel(rec.value("TransactionLoglevel").toInt());
			clsObj->setProfileTrgDropOption(rec.value("ProfileTrgDropOption").toInt());


			qry->clear();
			valid=true;
		}
        qry->finish ();
		db2.close();
	}
	if (valid)
	{
			QSqlDatabase::removeDatabase(uuid.toString());
			return clsObj;
	}
	return nullptr;
}

void modelNvProfilesPrivate::initialize(const QString dsn, const QString tableName)
{
	m_StrConnect = dsn;
	initialize(tableName);
}

void modelNvProfilesPrivate::initialize(const QString profileName)
{

    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
	db.open();

    createTable(builder->getNvProfilesCreate());

	m_pTableModel->setTable(profileName);
	m_pTableModel->select();
	m_lpszProfileName = profileName;
}

void modelNvProfilesPrivate::insertRow(nvProfilesClass *clsObj)
{
   // QString delProfile(QString("delete from nvprofiles where profilename = '%1'").arg(clsObj->getProfileName ()));
	{
		deleteRow(clsObj);
		if (!db.open()) db.open();
		if (db.open())
		{
			qDebug() << "1:" << db.lastError().text();


			QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
			qDebug() << "2:" << qry->lastError().text();
			QString tmpSql(clsObj->getInsertSqlStatement());

			qry->prepare(tmpSql);
			qry->exec();
			qDebug() << "3:" << qry->lastError().text();
			qry->finish();
			QString t;
			t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
				.arg(clsObj->getProfileName())
				.arg(m_strEnvyDSN)
				.arg(clsObj->getProfileSourceDSN())
				.arg(clsObj->getProfileTargetDSN());
			m_Log->log(enumerateClass::InfoLevel, t);
		}
	}
}

void modelNvProfilesPrivate::refresh()
{
	if (m_pTableModel)
	{
		m_pTableModel->select();
		m_rowCursor = m_pTableModel->rowCount();
	}
}

bool modelNvProfilesPrivate::createTable(const QString createTableSQL)
{
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
	QString tSql("create table if not exists ");
	tSql.append(QString(createTableSQL));
    bool bIsValid=qry->exec(tSql);
    qry->finish ();
    return bIsValid;
}

void modelNvProfilesPrivate::deleteRow(nvProfilesClass *clsObj)
{
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
	QString td;
    td = QString("delete from nvprofiles where profilename = '%1'").arg(clsObj->getProfileName ());
	if (!db.open()) db.open();
	if (db.open())
	{
		qry->prepare(td);
		if (!qry->exec())
		{
			QString tmp(qry->lastError().text());
			qDebug() << tmp;
			m_Log->log(enumerateClass::ErrorLevel, QString("Failed to delete NvProfile rows - %1\n%2").arg("modelNvProfilesPrivate::deleteRow").arg(tmp));
		}
		if (bIsEditOnly) return;
		td = QString("delete from nvtables where profilename = '%1'").arg(clsObj->getProfileName());
		qry->prepare(td);
		if (!qry->exec())
		{
			QString tmp(qry->lastError().text());
			qDebug() << tmp;
			m_Log->log(enumerateClass::ErrorLevel, QString("Failed to delete NvTable rows - %1\n%2").arg("modelNvProfilesPrivate::deleteRow").arg(tmp));
		}
		td = QString("delete from nvSchedules where profilename = '%1'").arg(clsObj->getProfileName());
		qry->prepare(td);
		if (!qry->exec())
		{
			QString tmp(qry->lastError().text());
			qDebug() << tmp;
			m_Log->log(enumerateClass::ErrorLevel, QString("Failed to delete NvSchedules rows - %1\n%2").arg("modelNvProfilesPrivate::deleteRow").arg(tmp));
		}
		qry->finish();
	}
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
        .arg(clsObj->getProfileName ())
        .arg(m_strEnvyDSN)
        .arg(clsObj->getProfileSourceDSN ())
        .arg(clsObj->getProfileTargetDSN ());
	m_Log->log(enumerateClass::InfoLevel, t);

	//delete clsObj;
}

void modelNvProfilesPrivate::beginTransaction()
{
	m_pTableModel->database().transaction();
	m_rowCursor = m_pTableModel->rowCount();
}

void modelNvProfilesPrivate::endTransaction()
{
	this->commit();
}

void modelNvProfilesPrivate::fetch()
{
	refresh();
}

void modelNvProfilesPrivate::update(nvProfilesClass *clsObj)
{
	{
		deleteRow(clsObj); // edit only mode
		if (!db.open()) db.open();
		if (db.open())
		{
			qDebug() << "1:" << db.lastError().text();


			QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
			qDebug() << "2:" << qry->lastError().text();
			QString tmpSql(clsObj->getInsertSqlStatement());

			qry->prepare(tmpSql);
			qry->exec();
			qDebug() << "3:" << qry->lastError().text();
			qry->finish();
			QString t;
			t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
				.arg(clsObj->getProfileName())
				.arg(m_strEnvyDSN)
				.arg(clsObj->getProfileSourceDSN())
				.arg(clsObj->getProfileTargetDSN());
			m_Log->log(enumerateClass::InfoLevel, t);
		}
	}
}

void modelNvProfilesPrivate::close()
{
	db.close();
}
