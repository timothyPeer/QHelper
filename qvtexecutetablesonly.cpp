#include "qvtexecutetablesonly.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QScopedPointer>
#include "connectionstringbuilder.h"

qvtExecuteTablesOnly::qvtExecuteTablesOnly(QObject * parent) : QObject(parent) {
	
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
	m_uid = QUuid::createUuid();
	db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);
}

qvtExecuteTablesOnly::~qvtExecuteTablesOnly() {
	
	QSqlDatabase::removeDatabase(m_uid.toString());
}

void qvtExecuteTablesOnly::initialize(const QString & dataSource, const QString & sqlStatement, bool isSQL)
{
	this->m_StrConnect = dataSource;
	this->m_sqlStatement = sqlStatement;
	this->isSQL = isSQL;
	db.setDatabaseName(m_StrConnect);
}

bool qvtExecuteTablesOnly::process()
{
	bool ret = false;
	if (!db.isOpen()) db.open();
    //QString tx = db.databaseName();
	errorText = db.lastError().text();

	if (db.isOpen())
	{
		tables = db.tables();
		close();
        ret = true;
        return ret;
	}
    return ret;
}

void qvtExecuteTablesOnly::close()
{
	db.close();
}

void qvtExecuteTablesOnly::run()
{
	process();
}

