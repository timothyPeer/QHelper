#include "qvtexecute.h"
#include <QSqlDatabase>
#include <QScopedPointer>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "nvtablesclass.h"
#include "nvprofilesclass.h"

qVtExecute::qVtExecute(QObject * parent) : QObject(parent) {

    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));

	m_uid = QUuid::createUuid();
	db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);
}

qVtExecute::~qVtExecute() {

	close();
	QSqlDatabase::removeDatabase(m_uid.toString());
}

void qVtExecute::initialize(const QString & dataSource, const QString & tableName)
{
	this->m_StrConnect = dataSource;
	this->m_sqlStatement = QString("select * from ").arg(tableName);
	this->isSQL = false;
}

void qVtExecute::initialize(const QString & dataSource, const QString & sqlStatement, bool isSQL)
{
	this->m_StrConnect = dataSource;
	this->m_sqlStatement = sqlStatement;
	this->isSQL = isSQL;
	db.setDatabaseName(m_StrConnect);
}

void qVtExecute::close()
{
	db.close();
}

void qVtExecute::run()
{
	process();
}

/// <summary>
/// Processes this instance.
/// </summary>
/// <returns>bool.</returns>
bool qVtExecute::process()
{
	bool ret = false;
	if (!db.isOpen()) db.open();
	QString tx = db.databaseName();
	errorText = db.lastError().text();

	if (db.isOpen())
	{
#ifdef _DEBUG
		//                QLogger::QLog_Debug("vtExecuteSQL",QString("MSG_DBOpen: %1 \n %2")
		//                    .arg(m_sqlStatement)
		//                    .arg(db.lastError().text()));
#endif
		QString sqlStatement = m_sqlStatement;
		QSqlQuery qry(db);
		qry.exec(sqlStatement);
		errorText = db.lastError().text();
		if (errorText.trimmed().isEmpty()) ret = true;
		
		//QLogger::QLog_Info("vtExecuteSQL",QString("Executed: %1 for \n %2").arg(sqlStatement).arg(m_StrConnect));
		qry.clear();
		qDebug() << QString("Executed: %1").arg(sqlStatement);
#ifdef _DEBUG
		//                QLogger::QLog_Debug("vtExecuteSQL",
		//                    QString("MSG_Query: %1 \n %2 \n%3")
		//                    .arg(m_StrConnect)
		//                    .arg(qry.lastError().text())
		//                    .arg(m_sqlStatement) );
#endif
		
	}
    return ret;
}
