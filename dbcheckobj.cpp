#include "dbcheckobj.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QScopedPointer>
#include <QUuid>
#include "connectionstringbuilder.h"

dbCheckObj::dbCheckObj(QObject *parent) : QObject(parent)
{

}

/// <summary>
/// Initializes the specified DSN connection string.
/// </summary>
/// <param name="dsnConnectionString">The DSN connection string.</param>
void dbCheckObj::initialize(const QString dsnConnectionString)
{
    m_DsnConnectionString = dsnConnectionString;
    QUuid uuid = QUuid::createUuid();
    {
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));


        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", uuid.toString());
        db.setDatabaseName(dsnConnectionString);
        db.setConnectOptions(builder->getOdbcAttributes());
        db.database(uuid.toString(), false);

        db.open();
        if (db.isOpen())
        {
           this->bIsValid = true;
        }
        db.close();
    }
    QSqlDatabase::removeDatabase(uuid.toString());
}

/// <summary>
/// SQLs the tables.
/// </summary>
/// <returns>QStringList.</returns>
QStringList dbCheckObj::sqlTables()
{
    if (!bIsValid) return QStringList();
    QUuid uuid = QUuid::createUuid();
    {
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));


        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", uuid.toString());
        db.setDatabaseName(m_DsnConnectionString);
        db.setConnectOptions(builder->getOdbcAttributes());
        db.database(uuid.toString(), false);

        db.open();
        if (db.isOpen())
        {
          m_SqlTables = db.tables ();
        }
        db.close();
    }
	QStringList lst = m_SqlTables;
    QSqlDatabase::removeDatabase(uuid.toString());
	return lst;
}
