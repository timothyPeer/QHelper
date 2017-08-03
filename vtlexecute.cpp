#include "vtlexecute.h"
#include <QSqlDatabase>
#include <QScopedPointer>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlField>
#include "connectionstringbuilder.h"
#include "qloggerwriter.h"

vtlExecute::vtlExecute(QObject *parent) : QObject(parent)
{
    m_uid = QUuid::createUuid();
}
/// <summary>
/// Destructor for an instance of the <see cref="vtlExecute"/> class.
/// </summary>
vtlExecute::~vtlExecute()
{
        QSqlDatabase::removeDatabase(m_uid.toString());
}

void vtlExecute::process()
{
    if (m_bSetScalarBool)
    {
        m_bScalarBoolResult =  executeScalarBool();
        return;

    }
    QUuid uuid = QUuid::createUuid();
    {
        //QObject *parent;
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
        if (m_StrConnect.isEmpty())  m_StrConnect = builder->getEnvyConnectionString();
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QODBC",uuid.toString());
        db.setDatabaseName(m_StrConnect);
        db.setConnectOptions(builder->getOdbcAttributes());
        db.database(uuid.toString(),false);
        if (!db.isOpen()) db.open();
#ifdef _DEBUG
        QString tx = db.databaseName();
        QString errorOpen = db.lastError().text();
#endif
        if (db.isOpen())
        {
#ifdef _DEBUG
            QLogger::QLog_Debug("vtExecuteSQL",QString("MSG_DBOpen: %1 \n %2")
                .arg(m_sqlStatement)
                .arg(db.lastError().text()));
#endif
            QString sqlStatement = m_sqlStatement;
            QSqlQuery qry(db);

            if (isBatch)
            {
                QString item;
				/// <summary>
				/// Foreaches the specified .
				/// </summary>
				/// <param name="">The .</param>
				/// <param name="">The .</param>
				/// <returns>int.</returns>
				foreach(item, batchList)
                {
                    qry.exec(sqlStatement);
                }
            }
            else
            {
                qry.exec(sqlStatement);
            }
            QLogger::QLog_Info("vtExecuteSQL",QString("Executed: %1 for \n %2").arg(sqlStatement).arg(m_StrConnect));

#ifdef _DEBUG
            QLogger::QLog_Debug("vtExecuteSQL",
                QString("MSG_Query: %1 \n %2 \n%3")
                .arg(m_StrConnect)
                .arg(qry.lastError().text())
                .arg(m_sqlStatement) );
#endif
            qry.clear();
        }

        db.close();
    }
    QSqlDatabase::removeDatabase(uuid.toString());
}

/// <summary>
/// Executes the scalar bool.
/// </summary>
/// <returns>bool.</returns>
bool vtlExecute::executeScalarBool()
{
    bool ret =false;
    QUuid uuid = QUuid::createUuid();
    {
        //QObject *parent;
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
        if (m_StrConnect.isEmpty())  m_StrConnect = builder->getEnvyConnectionString();
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QODBC",uuid.toString());
        db.setDatabaseName(m_StrConnect);
        db.setConnectOptions(builder->getOdbcAttributes());
        db.database(uuid.toString(),false);
        if (!db.isOpen()) db.open();
#ifdef _DEBUG
        QString tx = db.databaseName();
        QString errorOpen = db.lastError().text();
#endif

        if (db.isOpen())
        {
#ifdef _DEBUG
            QLogger::QLog_Debug("vtExecuteSQL",QString("MSG_DBOpen: %1 \n %2")
                .arg(m_sqlStatement)
                .arg(db.lastError().text()));
#endif
           QString sqlStatement = m_sqlStatement;
           QSqlQuery qry(db);

           qry.exec(sqlStatement);
           while(qry.next())
           {
               ret = true;
           }
            QLogger::QLog_Info("vtExecuteSQL",QString("Executed: %1 for \n %2\n returned: %3").arg(sqlStatement).arg(m_StrConnect).arg(ret));

#ifdef _DEBUG
            QLogger::QLog_Debug("vtExecuteSQL",
                QString("MSG_Query: %1 \n %2 \n%3")
                .arg(m_StrConnect)
                .arg(qry.lastError().text())
                .arg(m_sqlStatement) );
#endif
            qry.clear();
        }

        db.close();
    }
    QSqlDatabase::removeDatabase(uuid.toString());
    return ret;
}

/// <summary>
/// Initializes the specified data source.
/// </summary>
/// <param name="dataSource">The data source.</param>
/// <param name="sqlStatement">The SQL statement.</param>
void vtlExecute::initialize(const QString &dataSource, const QString &sqlStatement)
{
    this->m_StrConnect = dataSource;
    this->m_sqlStatement = sqlStatement;
}

/// <summary>
/// Runs this instance.
/// </summary>
void vtlExecute::run()
{
    process();
}

/// <summary>
/// Sets the default DSN.
/// </summary>
void vtlExecute::setDefaultDSN()
{

    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
    setDSNToDefault(builder->getEnvyConnectionString());
}
