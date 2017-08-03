#include "qnvprofiles.h"
#include <QScopedPointer>
#include <QSqlField>
#include <QSqlRecord>
#include "qvtexecute.h"
#include "vtlexecute.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QUuid>

qNvProfiles::qNvProfiles(QObject * parent) : qNvRepository(parent) {
	
	m_pProfilesClass = new nvProfilesClass(this);
}

/// <summary>
/// Destructor for an instance of the <see cref="qNvProfiles"/> class.
/// </summary>
qNvProfiles::~qNvProfiles() {
	
	if (m_pProfilesClass) delete m_pProfilesClass;
}

/// <summary>
/// Initializes the specified profile name.
/// </summary>
/// <param name="profileName">Name of the profile.</param>
void qNvProfiles::initialize(const QString profileName)
{
    setProfileName(profileName);
	this->m_bExists = profileExists();
}

/*
 *  enum nvTableStatusFlags
    {
        READY = 0, WAITING = 1, INPROCESS = 2, COMPLETE = 3, ABORTING = -9
    };
 *
 *
 */

 /// <summary>
 /// Executes the SQL set class.
 /// </summary>
void qNvProfiles::ExecuteSQLSetClass()
{
	QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));

    QString strSql(builder->getNvProfilesCreate());
	strSql.append(QString(" where profilename = '%1'").arg(getProfileName()));
	QScopedPointer<qVtExecute> vte(new qVtExecute(this));
	vte->initialize(this->getConnectionString(), strSql, true);
	
    vte->ExecuteDirect(this->getSqlStatement());
}

//QStringList qNvProfiles::SQLTABLES(const QString dsn)
//{
//    QStringList tableList;
//    tableList.clear ();
//    QString m_StrConnect;
//    QUuid uuid = QUuid::createUuid();
//    {
//        //QObject *parent;
//        QScopedPointer<connectionStringBuilder> myReg(new connectionStringBuilder());
//        if (m_StrConnect.isEmpty())  m_StrConnect = dsn;
//        QSqlDatabase db;
//        db = QSqlDatabase::addDatabase("QODBC",uuid.toString());
//        db.setDatabaseName(dsn);
//        db.setConnectOptions(builder->getOdbcAttributes());
//        db.database(uuid.toString(),false);
//        if (!db.isOpen()) db.open();
//#ifdef _DEBUG
//        QString tx = db.databaseName();
//        QString errorOpen = db.lastError().text();
//#endif
//        if (db.isOpen())
//        {
//#ifdef _DEBUG
//            QLogger::QLog_Debug("vtExecuteSQL",QString("MSG_DBOpen: %1 \n %2")
//                .arg(m_sqlStatement)
//                .arg(db.lastError().text()));
//#endif
//            tableList = db.tables ();
//        }

//        db.close();
//    }
//    QSqlDatabase::removeDatabase(uuid.toString());
//    return tableList;
//}
/// <summary>
/// Profiles the exists.
/// </summary>
/// <returns>bool.</returns>
bool qNvProfiles::profileExists()
{
    QScopedPointer<vtlExecute> ptr (new vtlExecute(this));
    ptr->setSqlStatement(QString("select profileName from nvprofiles where profileName = '%1'").arg(getProfileName()));
    ptr->setScalarBool(true);
    ptr->process();
    return ptr->getScalarBoolResult();

}
