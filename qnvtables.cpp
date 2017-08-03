#include "qnvtables.h"
#include "qNvRepository.h"
#include <QObject>
#include "qRCEnumDef.h"
#include "nvtablesclass.h"
#include <QScopedPointer>
#include "vtlExecute.h"


qNvTables::qNvTables(QObject * parent) :  qNvRepository(parent) {
	
	m_pNvTablesClass = new nvTablesClass(this);
}

/// <summary>
/// Destructor for an instance of the <see cref="qNvTables"/> class.
/// </summary>
qNvTables::~qNvTables() {
	
    if (m_pNvTablesClass) delete m_pNvTablesClass;
}

/// <summary>
/// Initializes the specified profile name.
/// </summary>
/// <param name="profileName">Name of the profile.</param>
void qNvTables::initialize(const QString profileName)
{
     setProfileName(profileName);
}


/// <summary>
/// Initializes the specified profile name.
/// </summary>
/// <param name="profileName">Name of the profile.</param>
/// <param name="tableName">Name of the table.</param>
void qNvTables::initialize(const QString profileName, const  QString tableName)
{
    m_strTableName = tableName;
    setProfileName(profileName);
}

 /// <summary>
 /// Updates the specified status flag.
 /// </summary>
 /// <param name="statusFlag">The status flag.</param>
 void qNvTables::update(enumerateClass::nvTableStatusFlags statusFlag)
{
	QString strSqlStatement;
    strSqlStatement = QString("Update NVTables set Status = %1 where Profilename = '%2' and tablename =  '%3'").arg((int)statusFlag).arg(getProfileName()).arg(m_strTableName);
	execute();
}


/// <summary>
/// Executes the SQL set class.
/// </summary>
void qNvTables::ExecuteSQLSetClass()
{
	QScopedPointer<qVtExecute> vte(new qVtExecute(this));
	vte->initialize(this->getConnectionString(),QString(), true);
	vte->ExecuteDirect(this->getSqlStatement());


}

/// <summary>
/// Sets the name of the table.
/// </summary>
/// <param name="tableName">Name of the table.</param>
void qNvTables::setTableName(const QString tableName)
{
    m_strTableName = tableName;
}

/// <summary>
/// Fetches the table.
/// </summary>
void qNvTables::fetchTable()
{
    if (m_strTableName.isEmpty())
    {
        qDebug() << "tablename is not set";
    }
    // We have a table set.
    //



}



// void qNvTables::update(const QString strPofileName, const QString strTableName, nvTableStatusFlags statusFlag)
// {
// 	setProfileName(strPofileName);
// 	QString strSqlStatement;
// 	strSqlStatement = QString("Update NVTables set Status = %1 where Profilename = '%2' and tablename = '%3'").arg((int) statusFlag).arg(strPofileName).arg(strTableName);
// 	execute();
// 
// }
