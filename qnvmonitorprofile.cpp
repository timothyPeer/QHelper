#include "qnvmonitorprofile.h"
#include "qNvRepository.h"
#include "nvmonitorclass.h"
#include "qvtexecute.h"

qnvMonitorProfile::qnvMonitorProfile(QObject * parent) : qNvRepository(parent) {
	
}

qnvMonitorProfile::~qnvMonitorProfile() {
	
}

//void qnvMonitorProfile::initialize(const QString strConnectionString)
//{
//    //setConnectionString(strConnectionString);
//}

bool qnvMonitorProfile::update(nvMonitorClass cls)
{
	QString sqlStatement = cls.getUpdateSqlStatement();
	QScopedPointer<qVtExecute> vExec(new qVtExecute(this));
	vExec->initialize(this->getConnectionString(), this->getSqlStatement(), true);
	return vExec->ExecuteDirect(sqlStatement);
}
bool qnvMonitorProfile::insert(nvMonitorClass cls)
{
	QString sqlStatement = cls.getInsertSqlStatement();
	QScopedPointer<qVtExecute> vExec(new qVtExecute(this));
	vExec->initialize(this->getConnectionString(), this->getSqlStatement(), true);
	return vExec->ExecuteDirect(sqlStatement);
}
