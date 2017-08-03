#include "nvschedulesclass.h"


nvSchedulesClass::nvSchedulesClass(QObject * parent) : QObject(parent) {
	
}

nvSchedulesClass::~nvSchedulesClass() {
	
}

void nvSchedulesClass::initializeClass(const QString  stProfile, const QString  stTable, const QString stScheduleDate, const QString stScheduleTime, int bSelected, int uOperationType)
{
	m_strProfileName = stProfile; m_strTableName = stTable; 
	m_strScheduledDate = stScheduleDate; 
	m_strScheduledTime = stScheduleTime; 
	m_bSelected = bSelected; 
	m_uOperationType = uOperationType;
}

QString nvSchedulesClass::getUpdateSqlStatement()
{
	QString strSQL;
	strSQL = QString("update nvSchedules set ");
	strSQL.append(" profilename = '%1'").arg(m_strProfileName);
	strSQL.append(",tablename = '%1'").arg(m_strTableName);
	strSQL.append(",bSelected = %1").arg(m_bSelected);
	strSQL.append(",OperationType = %1").arg(m_uOperationType);
	strSQL.append(" where profileName = '%1' ").arg(m_strProfileName);
	return strSQL;
}

QString nvSchedulesClass::getInsertSqlStatement()
{
	QString strSQL;
	strSQL = QString("	INSERT INTO [dbo].[NVSchedules] ([ProfileName]	, [ScheduledDate]	, [ScheduledTime]	, [bSelected]	, [OperationType]) VALUES (");
	strSQL.append(" profilename = '%1'").arg(m_strProfileName);
	strSQL.append(",tablename = '%1'").arg(m_strTableName);
	strSQL.append(",bSelected = %1").arg(m_bSelected);
	strSQL.append(",OperationType = %1").arg(m_uOperationType);
	strSQL.append(" where profileName = '%1' ").arg(m_strProfileName);
	strSQL.append(")");
	return strSQL;
}
