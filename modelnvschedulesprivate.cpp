#include "modelnvschedulesprivate.h"
#include "connectionstringbuilder.h"

modelNvSchedulesPrivate::modelNvSchedulesPrivate() : 
    m_pTableModel(new QSqlTableModel())
{
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder);
    m_StrConnect = builder->getEnvyConnectionString ();
	m_uid = QUuid::createUuid();
	db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);

	// Pointer

	m_Log = new qCLogObject(nullptr);

}

modelNvSchedulesPrivate::~modelNvSchedulesPrivate() {
	if (m_pTableModel)	delete m_pTableModel;

	close();
	QSqlDatabase::removeDatabase(m_uid.toString());
	if (m_Log) delete m_Log;
}

void modelNvSchedulesPrivate::beginTransaction()
{
	m_pTableModel->database().transaction();
	m_rowCursor = m_pTableModel->rowCount();
}

bool modelNvSchedulesPrivate::createTable(const QString createTableSQL)
{
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
	QString tSql("create table if not exists ");
	tSql.append(QString(createTableSQL));
    return qry->exec(tSql);
}

void modelNvSchedulesPrivate::deleteRow(nvSchedulesClass * clsObj)
{
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
	QString td;
    td = QString("delete from nvprofiles where profilename = '%1'").arg(clsObj->getProfileName ());
    qry->prepare(td);
    if (!qry->exec())
	{
		m_Log->log(enumerateClass::ErrorLevel, QString("Failed to delete row - %1").arg("modelNvProfilesPrivate::deleteRow"));
	}
    qry->finish ();
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
        .arg(clsObj->getProfileName ())
        .arg(m_StrConnect)
        .arg(clsObj->getScheduledDate ())
        .arg(clsObj->getScheduledTime());
	m_Log->log(enumerateClass::InfoLevel, t);
	delete clsObj;
}

void modelNvSchedulesPrivate::endTransaction()
{
	this->commit();
}

void modelNvSchedulesPrivate::fetch()
{
	refresh();
}

void modelNvSchedulesPrivate::initialize(const QString dsn, const QString tableName)
{
	m_StrConnect = dsn;
	initialize(tableName);
}

void modelNvSchedulesPrivate::initialize(const QString tableName)
{

    QScopedPointer<connectionStringBuilder> builder (new connectionStringBuilder);
    m_StrConnect = builder->getEnvyConnectionString ();
	db.open();

    createTable(builder->getNvSchedulesCreate());

	m_pTableModel->setTable(tableName);
	m_pTableModel->select();
}

void modelNvSchedulesPrivate::insertRow(nvSchedulesClass * clsObj)
{
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
    qry->prepare(clsObj->getInsertSqlStatement());
    if (!qry->exec())
	{
		m_Log->log(enumerateClass::ErrorLevel, QString("Failed to insert rows - %1").arg("modelNvProfilesPrivate::insert"));
	}
    qry->finish ();
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
        .arg(clsObj->getProfileName ())
        .arg(m_StrConnect)
        .arg(clsObj->getScheduledDate ())
        .arg(clsObj->getScheduledTime ());
	m_Log->log(enumerateClass::InfoLevel, t);
	delete clsObj;
}

void modelNvSchedulesPrivate::refresh()
{

	if (m_pTableModel)
	{
        m_pTableModel->submit();
		m_pTableModel->select();
		m_rowCursor = m_pTableModel->rowCount();
	}
}

void modelNvSchedulesPrivate::update(nvSchedulesClass * clsObj)
{
    QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
    qry->prepare(clsObj->getUpdateSqlStatement());
    if (!qry->exec())
	{
		m_Log->log(enumerateClass::ErrorLevel, QString("Failed to Update rows - %1").arg("modelNvProfilesPrivate::update"));
	}
    qry->finish ();
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
        .arg(clsObj->getProfileName ())
        .arg(m_StrConnect)
        .arg(clsObj->getScheduledDate ())
        .arg(clsObj->getScheduledTime ());
	m_Log->log(enumerateClass::InfoLevel, t);
	delete clsObj;
}

void modelNvSchedulesPrivate::close()
{
	db.close();
}
