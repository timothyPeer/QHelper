#include "qclsregister.h"
#include "qnvstaticclass.h"
#include "qvtexecute.h"
#include "qnvStaticClass.h"


qClsRegister::qClsRegister(QObject * parent) : QObject(parent) {
	
	settings = new	QSettings(QString("eNVy Systems, Inc."),QString("ReplicatorConsoleQ"),this);

	QString repo = GetRepositoryDSN();
	if (repo.isEmpty())
	{
		QScopedPointer<qnvStaticClass> qnv(new qnvStaticClass(this));
		writeProfileString("configure",qnv->getNVMyEnvyDSN(),"DRIVER=SQL Server;SERVER=10.1.4.23;UID=sa;PWD=system99;APP=Replicator Console;WSID=SCG1S006;DATABASE=EnvyRCQ");
	}
}

qClsRegister::~qClsRegister() {
	
	if (!settings) delete settings;
}

bool qClsRegister::InitMySet(void)
{

	QString lpszSelectProfiles("Select * from nvprofiles");
	QString lpszSelectSchedules("Select * from nvschedules");
	QString lpszSelectTables("Select * from nvtables");
	QString lpszActiveThreads("Select * from nvActiveThreads");
	QString lpszDropProfile("drop table nvprofiles");
	QString lpszDropNvSchedules("drop table nvschedules");
	QString lpszDropNvTables("drop table nvTables");
	QString lpszDropActiveThreads("drop table nvActiveThreads");

	QScopedPointer<qVtExecute> qVt(new qVtExecute(this));
	qVt->initialize(GetRepositoryDSN(), lpszSelectProfiles);

	bool existsNVProfiles = qVt->ExecuteDirect(lpszSelectProfiles);
	bool existsNVTables = qVt->ExecuteDirect(lpszSelectTables);
	bool existsnvschedules = qVt->ExecuteDirect(lpszSelectSchedules);

// create the table if it doesn't exist
	QScopedPointer<qnvStaticClass> pNv(new qnvStaticClass(this));
	if (!existsNVTables) qVt->ExecuteDirect(pNv->getCreateTableNVT());

	if (!existsNVProfiles) qVt->ExecuteDirect(pNv->getNVProfiles_Create());

	if (!existsnvschedules) qVt->ExecuteDirect(pNv->getNVCreateSchedule());


	return true;
}

QString qClsRegister::GetErrorText(void)
{
	return this->m_ErrorText;
}

QString qClsRegister::GetErrorCode(void)
{
	return m_ErrorCode;
}

void qClsRegister::writeProfileString(const QString group, const QString key, const QString value)
{

	settings->beginGroup(group);
	settings->setValue(key,value);
	settings->endGroup();
	
}

void qClsRegister::writeProfileInt(const QString group, const QString key, const int value)
{

	settings->beginGroup(group);
	settings->setValue(key, value);
	settings->endGroup();

}
QString qClsRegister::getProfileString(const QString group, const QString key)
{
	QVariant mString;
	settings->beginGroup(group);
	mString = settings->value(key);
	settings->endGroup();
	return mString.toString();
}
int qClsRegister::getProfileInt(const QString group, const QString key)
{
	QVariant mInt;
	settings->beginGroup(group);
	mInt = settings->value(key);
	settings->endGroup();
	return mInt.toInt();

}

bool qClsRegister::InitializeTables()
{
//	QMessageBox msgBox;
//	msgBox.setWindowTitle("ReplicatorConsoleQ");
//	msgBox.setInformativeText("You are about to reset your registry settings.");
//	msgBox.setText("Do you want to continue?");
//	msgBox.setStandardButtons(QMessageBox::Yes);
//	msgBox.addButton(QMessageBox::No);
//	msgBox.setDefaultButton(QMessageBox::No);
//	if (msgBox.exec() == QMessageBox::Yes) {
//		// do something
//		InitMySet();
//		return getIsOpen();
//	}
//	else {
//		// do something else
		return false;
//	}
		
	
		

	
}

QString qClsRegister::GetRepositoryDSN()
{
	QScopedPointer<qnvStaticClass> qnv(new qnvStaticClass(this));
	return getProfileString("Configure", qnv->getNVMyEnvyDSN());
}

void qClsRegister::SetRepositoryDSN(const QString strValue)
{
	QScopedPointer<qnvStaticClass> qnv(new qnvStaticClass(this));
	writeProfileString("Configure", qnv->getNVMyEnvyDSN(), strValue);
	//WriteProfileInt("Configure", _NVEnableDSN, tmpEnabled);
	writeProfileInt("Configure", qnv->getNVOrdinalType(), this->GetOrdinal());
	// Update the variables so they can be passed back to the application
	m_RepositoryDSN = strValue;
	m_GotDSN = true;
}

void qClsRegister::setLogFileName(QString lpszFilename)
{
	QScopedPointer<qnvStaticClass> qnv(new qnvStaticClass(this));
	writeProfileString("Configure", qnv->getNVMyLog(), lpszFilename);
}

QString qClsRegister::getLogFileName()
{
	QString  strDSNItem = "EMPTY";
	QScopedPointer<qnvStaticClass> qnv(new qnvStaticClass(this));
	m_LogFileName = getProfileString("Configure", qnv->getNVMyLog());
	//this->SetLogFileName(myLog);
	if (m_LogFileName.isEmpty())
		return QString();
	return m_LogFileName;
}

int qClsRegister::GetOrdinal()
{
	return this->m_DBMSOrdinal;
}

void qClsRegister::SetOrdinal(int uOrdinal)
{
	this->m_DBMSOrdinal = uOrdinal;
}

//void qClsRegister::SetEnabled(bool isEnabled)
//{
//	
//}
