#pragma once
#ifndef NVSCHEDULESCLASS_HPP
#define NVSCHEDULESCLASS_HPP
#include <QObject>

class nvSchedulesClass : public QObject {
	Q_OBJECT


public:
	nvSchedulesClass(QObject * parent = Q_NULLPTR);
	~nvSchedulesClass();

    void initializeClass(const QString stProfile, const QString  stTable, const QString stScheduleDate, const QString stScheduleTime, int bSelected, int uOperationType);
	QString getUpdateSqlStatement();
	QString getInsertSqlStatement();

    QString getProfileName() { return m_strProfileName; }
    QString getTableName() { return m_strTableName; }
    QString getScheduledDate() { return m_strScheduledDate; }
    QString getScheduledTime() { return m_strScheduledTime; }
    int     getOperationType() { return m_uOperationType; }

    void setProfileName(const QString profileName){
        m_strProfileName = profileName;
    }
    void setTableName(const QString tableName) {
        m_strTableName = tableName;
    }
    void setScheduledDate(const QString schedDate) {
        m_strScheduledDate = schedDate;
    }
    void setScheduledTime(const QString schedTime) {
    m_strScheduledTime = schedTime;
    }

    void setOperationType(int opnType){
        m_uOperationType = opnType;
    }

private:

	QString m_strProfileName;
	QString m_strTableName;
	QString m_strScheduledDate;
	QString m_strScheduledTime;
	bool	m_bSelected;
	int		m_uOperationType;
	
};

#endif // NVSCHEDULESCLASS_HPP
