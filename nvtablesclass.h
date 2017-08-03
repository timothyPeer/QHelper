#pragma once
#ifndef NVTABLESCLASS_HPP
#define NVTABLESCLASS_HPP
#include <QObject>
#include "qNvRepository.h"

class nvTablesClass : public QObject {
	Q_OBJECT

public:
	QString getTableName();
	nvTablesClass(QObject * parent = Q_NULLPTR);
	~nvTablesClass();
	void initialize(const QString stProfile, const QString stTable, int iStatus, const QString stPreferredSelect, const QString stPreferredInsert, const QString stPreferredUpdate, int iFieldCnt);

	QString getUpdateSqlStatement();
	QString getInsertSqlStatement();
	void setProfileName(const QString profileName) { m_strProfileName = profileName; }
	void setTableName(const QString tableName) { m_strTableName = tableName;  }
	void setPreferredSelect(const QString stmt) { m_strPreferredSelect = stmt;  }
	void setPreferredInsert(const QString stmt) { m_strPreferredInsert = stmt;  }
	void setPreferredUpdate(const QString stmt) { m_strPreferredUpdate = stmt;  }
	void setFetchSql(const QString stmt) { m_fetchSQL = stmt; }
	void setInsertSql(const QString stmt) { m_insertSQL = stmt; }
	void setUpdateSql(const QString stmt) { m_updateSQL = stmt;  }
	void setFieldCnt(int fieldCnt) { m_uFieldCnt = fieldCnt; }

	QString m_strProfileName;
	QString m_strTableName;
	QString m_strPreferredSelect;
	QString m_strPreferredInsert;
	QString m_strPreferredUpdate;
	QString m_fetchSQL;
	QString m_insertSQL;
	QString m_updateSQL;
	int		m_uFieldCnt;
	int		m_uStatus;
	
};

#endif // NVTABLESCLASS_HPP