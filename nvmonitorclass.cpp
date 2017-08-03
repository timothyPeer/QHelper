#include "nvmonitorclass.h"

nvMonitorClass::nvMonitorClass(QObject * parent) : QObject(parent) {
	
}

nvMonitorClass::~nvMonitorClass() {
	
}

void nvMonitorClass::initClass(const QString  stProfile, const QString stTable, const QString stTimestamp, const QString stStartTime, const QString stEndTime, int rowsProcess, double elapsedTime, int threadId, enumerateClass::monitorStatus mStatus)
{
	m_strProfileName = stProfile; m_strTableName = stTable; strNVTimestamp = stTimestamp; strStartTime = stStartTime; strEndTime = stEndTime; uRowsProcessed = rowsProcess; uElapsedTime = elapsedTime; uThreadId = threadId;
	uMStatus = (int)mStatus;
}

QString nvMonitorClass::getUpdateSqlStatement()
{
	QString strSQL;
	strSQL = QString("update nvmonitor set ");
	strSQL.append(" profilename = '%1'").arg(m_strProfileName);
	strSQL.append(",tablename = '%1'").arg(m_strTableName);
	strSQL.append(",threadid = '%1'").arg(uThreadId);
	strSQL.append(",starttime = '%1'").arg(strStartTime);
	strSQL.append(",endtime = '%1'").arg(strEndTime);
	strSQL.append(", nvtimestamp = '%1'").arg(strNVTimestamp);
	strSQL.append(", monstat = %1").arg(uMStatus);
	strSQL.append(", rowsprocessed = %1").arg(uRowsProcessed);
	strSQL.append(" where profileName = '%1' and tableName = '%2'").arg(m_strProfileName).arg(m_strTableName);
	return strSQL;
}

QString nvMonitorClass::getInsertSqlStatement()
{
	QString strSQL;
	strSQL = QString("	INSERT INTO [dbo].[NVMonitor] 	([ProfileName]		, [TableName]		, [ThreadId]		, [StartTime]		, [EndTime]		, [NvTimeStamp]		, [MonStat]		, [RowsProcessed]		, [ElapsedTime])		VALUES		(");
	strSQL.append(" profilename = '%1'").arg(m_strProfileName);
	strSQL.append(",tablename = '%1'").arg(m_strTableName);
	strSQL.append(",threadid = '%1'").arg(uThreadId);
	strSQL.append(",starttime = '%1'").arg(strStartTime);
	strSQL.append(",endtime = '%1'").arg(strEndTime);
	strSQL.append(", nvtimestamp = '%1'").arg(strNVTimestamp);
	strSQL.append(", monstat = %1").arg(uMStatus);
	strSQL.append(", rowsprocessed = %1").arg(uRowsProcessed);
	strSQL.append(")");
	return strSQL;
		
}
