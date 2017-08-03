#pragma once
#ifndef NVMONITORCLASS_HPP
#define NVMONITORCLASS_HPP
#include <QObject>
#include "qRCEnumDef.h"

class nvMonitorClass : public QObject {
	Q_OBJECT

public:
	nvMonitorClass(QObject * parent = Q_NULLPTR);
	~nvMonitorClass();

    void initClass(const QString stProfile, const QString stTable, const QString stTimestamp, const QString stStartTime, const QString stEndTime, int rowsProcess, double elapsedTime,int threadId, enumerateClass::monitorStatus mStatus);
	QString getUpdateSqlStatement();
	QString getInsertSqlStatement();

    QString getProfileName() { return m_strProfileName; }
    QString getTableName() { return m_strTableName; }
    void setProfileName(const QString profileName) {
        m_strProfileName = profileName;
    }
    void setTableName(const QString tableName)
    {
        m_strTableName = tableName;
    }
    void setNVTimestamp(const QString timestamp)
    {
        strNVTimestamp = timestamp;
    }
    void setRowsProcessed(int rowsProcessed) {
        uRowsProcessed = rowsProcessed;
    }
    void setStartTime(const QString startTime)
    {
        strStartTime = startTime;
    }
    void setEndTime(const QString endTime)
    {
        strEndTime = endTime;
    }

    QString getEndTime() { return strEndTime; }
    QString getStartTime() { return strStartTime; }
    int     getRowsProcessed() { return uRowsProcessed; }
    double  getElapsedTime() { return uElapsedTime; }
    void    setElapsedTime(double elapsedTime) {
        uElapsedTime   = elapsedTime;
    }
    void setThreadId(int threadId) {
        uThreadId = threadId;
    }
    int getThreadId() { return uThreadId; }
    void setMStatus(int statusVal) {
        uMStatus = statusVal;
    }
    int getMStatus() { return uMStatus; }

private:
    QString m_strProfileName;
    QString m_strTableName;
    QString strNVTimestamp;
    int uRowsProcessed;
    QString strStartTime;
    QString strEndTime;
    double uElapsedTime;
    int uThreadId;
    int uMStatus;

};

#endif // NVMONITORCLASS_HPP
