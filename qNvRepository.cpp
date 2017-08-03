#include "qNvRepository.h"
#include "qvtexecute.h"
#include <QScopedPointer>


qNvRepository::qNvRepository(QObject * parent) : QObject(parent) {
	
}

/// <summary>
/// Destructor for an instance of the <see cref="qNvRepository"/> class.
/// </summary>
qNvRepository::~qNvRepository() {
	
}



/// <summary>
/// Sets the SQL statement.
/// </summary>
/// <param name="sqlStatement">The SQL statement.</param>
void qNvRepository::setSqlStatement(const QString sqlStatement)
{
	m_strSqlStatement = sqlStatement;
}



/// <summary>
/// Executes this instance.
/// </summary>
void qNvRepository::execute()
{
	QScopedPointer<qVtExecute> vt(new qVtExecute(this));
    vt->initialize(this->m_strConnectionString, m_strSqlStatement, true);
	vt->ExecuteDirect(m_strSqlStatement);
}
