#include <QScopedPointer>
#include "modelnvmonitorsprivate.h"
#include "connectionstringbuilder.h"
#include "qclogobject.h"

modelNvMonitorsPrivate::modelNvMonitorsPrivate() : 
    m_pTableModel(new QSqlTableModel())
{
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
	m_uid = QUuid::createUuid();
	db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);

	// Pointer

	//cls = new qClsRegister(nullptr);
	m_Log = new qCLogObject(nullptr);
	//m_pTableModel = new QSqlTableModel();
    m_strEnvyDSN = builder->getEnvyConnectionString ();
    m_StrConnect = builder->getEnvyConnectionString ();
}

/// <summary>
/// Destructor for an instance of the <see cref="modelNvMonitorsPrivate"/> class.
/// </summary>
modelNvMonitorsPrivate::~modelNvMonitorsPrivate() {
    //if (cls) delete cls;
	if (m_pTableModel)	delete m_pTableModel;

	close();
	QSqlDatabase::removeDatabase(m_uid.toString());
	if (m_Log) delete m_Log;
}

/// <summary>
/// Begins the transaction.
/// </summary>
void modelNvMonitorsPrivate::beginTransaction()
{
	m_pTableModel->database().transaction();
	m_rowCursor = m_pTableModel->rowCount();
}

/// <summary>
/// Creates the table.
/// </summary>
/// <param name="createTableSQL">The create table SQL.</param>
/// <returns>bool.</returns>
bool modelNvMonitorsPrivate::createTable(const QString createTableSQL)
{
	QSqlQuery qry(db);
	QString tSql("create table if not exists ");
	tSql.append(QString(createTableSQL));
	return qry.exec(tSql);
}

/// <summary>
/// Deletes the row.
/// </summary>
/// <param name="clsObj">The CLS object.</param>
void modelNvMonitorsPrivate::deleteRow(nvMonitorClass *clsObj)
{
	QSqlQuery qry(db);
	QString td;
    td = QString("delete from nvMonitors where profilename = '%1'").arg(clsObj->getProfileName ());
	qry.prepare(td);
	if (!qry.exec())
	{
		m_Log->log(enumerateClass::ErrorLevel, QString("Failed to delete row - %1").arg("modelNvMonitorsPrivate::deleteRow"));
	}
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
        .arg(clsObj->getProfileName ())
        .arg(m_strEnvyDSN)
        .arg(clsObj->getTableName ())
        .arg(clsObj->getStartTime ());
	m_Log->log(enumerateClass::InfoLevel, t);
	delete clsObj;

	refresh();
}

/// <summary>
/// Ends the transaction.
/// </summary>
void modelNvMonitorsPrivate::endTransaction()
{
	commit();
}

/// <summary>
/// Fetches this instance.
/// </summary>
void modelNvMonitorsPrivate::fetch()
{
	refresh();
}

/// <summary>
/// Initializes the specified DSN.
/// </summary>
/// <param name="dsn">The DSN.</param>
/// <param name="tableName">Name of the table.</param>
void modelNvMonitorsPrivate::initialize(const QString dsn, const QString tableName)
{
	m_StrConnect = dsn;
	initialize(tableName);
}

/// <summary>
/// Initializes the specified table name.
/// </summary>
/// <param name="tableName">Name of the table.</param>
void modelNvMonitorsPrivate::initialize(const QString tableName)
{
    //cls = new connectionStringBuilder();

	db.open();

	//createTable("CREATE TABLE [dbo].[NVProfiles](	[ProfileName][varchar](24) NULL, [ProfileDescription0][varchar](255) NULL, [ProfileDescription1][varchar](255) NULL,[ProfileEnabled][int] NULL,	[ProfileAutoCommitEnabled][int] NULL,	[ProfileTraceEnabled][int] NULL,	[ProfileSourceDSN0][varchar](255) NULL,	[ProfileSourceDSN1][varchar](255) NULL,	[ProfileSourceDSN2][varchar](255) NULL,	[ProfileSourceDSN3][varchar](255) NULL,	[ProfileTargetDSN0][varchar](255) NULL,	[ProfileTargetDSN1][varchar](255) NULL,	[ProfileTargetDSN2][varchar](255) NULL,	[ProfileTargetDSN3][varchar](255) NULL,	[ExecutionThreads][int] NULL,	[ScheduleIntervalEnabled][int] NULL,	[CommitThrottle][int] NULL,	[EnableAutoReset][int] NULL,	[NVLogFile][varchar](255) NULL,	[TransactionLogging][int] NULL,	[TransactionLogLevel][int] NULL ) ");

	m_pTableModel->setTable(tableName);
	m_pTableModel->select();
}

/// <summary>
/// Inserts the row.
/// </summary>
/// <param name="clsObj">The CLS object.</param>
void modelNvMonitorsPrivate::insertRow(nvMonitorClass *clsObj)
{
	QSqlQuery qry(db);
	qry.prepare(clsObj->getInsertSqlStatement());
	if (!qry.exec())
	{
		m_Log->log(enumerateClass::ErrorLevel, QString("Failed to insert rows - %1").arg("modelNvMonitorsPrivate::insert"));
	}
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n TableName: %3\n FieldCnt: %4")
        .arg(clsObj->getProfileName ())
                 .arg(m_strEnvyDSN)
        .arg(clsObj->getTableName ())
        .arg(clsObj->getStartTime ());
	m_Log->log(enumerateClass::InfoLevel, t);
    //delete clsObj;

	refresh();
}

/// <summary>
/// Refreshes this instance.
/// </summary>
void modelNvMonitorsPrivate::refresh()
{
	if (m_pTableModel)
	{
		m_pTableModel->select();
		m_rowCursor = m_pTableModel->rowCount();
	}
}

/// <summary>
/// Updates the specified CLS object.
/// </summary>
/// <param name="clsObj">The CLS object.</param>
void modelNvMonitorsPrivate::update(nvMonitorClass * clsObj)
{
	QSqlQuery qry(db);
	qry.prepare(clsObj->getUpdateSqlStatement());
	if (!qry.exec())
	{
		m_Log->log(enumerateClass::ErrorLevel, QString("Failed to Update rows - %1").arg("modelNvMonitorsPrivate::update"));
	}
	QString t;
	t = QString("Profile: %1 \n Repository: %2\n Source DSN: %3\n Target DSN: %4")
        .arg(clsObj->getProfileName ())
        .arg(m_strEnvyDSN)
        .arg(clsObj->getTableName ())
        .arg(clsObj->getStartTime ());
	m_Log->log(enumerateClass::InfoLevel, t);
    //delete clsObj;
	refresh();
}

/// <summary>
/// Closes this instance.
/// </summary>
void modelNvMonitorsPrivate::close()
{
	m_pTableModel->submit();
	db.close();
}
