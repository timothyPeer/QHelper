#include "nvprofilesclass.h"
#include <QDebug>

nvProfilesClass::nvProfilesClass(QObject * parent) : QObject(parent) {
	
}

nvProfilesClass::~nvProfilesClass() {
	
}

QString nvProfilesClass::getUpdateSqlStatement()
{
	QString sSQL;
	sSQL.append("UPDATE [dbo].[NVProfiles]");
    sSQL.append("	SET [ProfileName] = '%1'").arg(m_strProfileName);
    sSQL.append("	, [ProfileDescription] = '%1'").arg(m_strDescription);
    sSQL.append("	, [ProfileEnabled] = '%1'").arg(this->m_bProfileEnabled);
    sSQL.append("	, [ProfileSourceDSN] = '%1'").arg(m_strSourceDSN);
    sSQL.append("	, [ProfileTargetDSN] = '%1'").arg(m_strTargetDSN);
	sSQL.append("	, [NVLogFile] = '%1'").arg(m_strNvLogFile);

	sSQL.append("	, [CommitThrottle] = '%1' ").arg(m_iCommitThrottle);
	sSQL.append("	, [ExecutionThreads] = '%1' ").arg(m_iExecuteThreads);
	sSQL.append(" where profileName = '%1'").arg(m_strProfileName);
	return sSQL;
}

QString nvProfilesClass::getInsertSqlStatement()
{
	QString sSQL;
	if (m_strSourceDSN.contains("'"))m_strSourceDSN.replace("'", "''");

	sSQL.append("INSERT INTO [dbo].[NVProfiles]");
	sSQL.append("([ProfileName]");
    sSQL.append(",[ProfileDescription]");
	sSQL.append(",[ProfileEnabled]");
    sSQL.append(",[ProfileSourceDSN]");
    sSQL.append(",[ProfileTargetDSN]");
	sSQL.append(",[ExecutionThreads]");
	sSQL.append(",[CommitThrottle]");
	sSQL.append(",[NVLogFile]");
	sSQL.append(",[ProfileCommitInterval]");
	sSQL.append(",[TransactionLogging]");
	sSQL.append(",[EnableAutoReset]");
	sSQL.append(",[ProfileTrgDropOption]");
	sSQL.append(",[ProfileTraceEnabled]");
	sSQL.append(",[ProfileAutoCommitEnabled]");
	sSQL.append(",[ScheduleIntervalEnabled]");
	sSQL.append(",[TransactionLogLevel]");
	sSQL.append(",[ProfileNetworkPacketSize]");
	sSQL.append(")");
	sSQL.append("	VALUES");
	sSQL.append(QString("( '%1'").arg(m_strProfileName));
    sSQL.append(QString(" ,'%1'").arg(m_strDescription)); //, <ProfileDescription, varchar(255), >
	sSQL.append(",1"); // ProfileEnabled
	sSQL.append(QString(",'%1'").arg(m_strSourceDSN));
	sSQL.append(QString(",'%1'").arg(m_strTargetDSN));
	sSQL.append(QString(",%1").arg(m_iExecuteThreads));
	sSQL.append(QString(",%1").arg(m_iCommitThrottle));
	sSQL.append(QString(",'%1'").arg(m_strNvLogFile));
	sSQL.append(QString(",%1").arg(m_iCommitThrottle));
	sSQL.append(QString(",%1").arg(m_iTransactionLogLevel));
	sSQL.append(QString(",%1").arg("1"));// Enable Auto Reset
	sSQL.append(QString(",%1").arg(m_iProfileTrgDropOption));
	sSQL.append(QString(",%1").arg((int)m_bProfileTraceEnabled));//m_bProfileTraceEnabled
	sSQL.append(QString(",%1").arg("1")); // ProfileAutoCommitEnabled
	sSQL.append(QString(",%1").arg("1")); //ScheduleIntervalEnabled -- classic scheduler support
	sSQL.append(QString(",%1").arg(m_iTransactionLogLevel));
	sSQL.append(QString(",%1").arg(m_iNetworkPacketSize));
	sSQL.append(")"); 
	
	qDebug() << sSQL;
	return sSQL;
}

