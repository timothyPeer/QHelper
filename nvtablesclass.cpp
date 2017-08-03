#include "nvtablesclass.h"

QString nvTablesClass::getTableName()
{
	return m_strTableName;
}

nvTablesClass::nvTablesClass(QObject * parent) : QObject(parent) {
	m_uStatus = 1;
}

nvTablesClass::~nvTablesClass() {

}

void nvTablesClass::initialize(const QString  stProfile, const QString stTable, int iStatus, const QString stPreferredSelect, const QString stPreferredInsert, const QString stPreferredUpdate, int iFieldCnt)
{
	m_strProfileName = stProfile;
	m_strTableName = stTable;
	m_strPreferredSelect = stPreferredSelect;
	m_strPreferredInsert = stPreferredInsert;
	m_strPreferredUpdate = stPreferredUpdate;
	m_uFieldCnt = iFieldCnt;
	m_uStatus = iStatus;
}

QString nvTablesClass::getUpdateSqlStatement()
{
	QString sSQL;
	sSQL.append("UPDATE [dbo].[NVTables]");
	sSQL.append("	SET[ProfileName] = '%1'").arg(m_strProfileName);
	sSQL.append("	, [TableName] = '%1'").arg(m_strTableName);
	sSQL.append("	, [Status] = '%1'").arg(m_uStatus);
	sSQL.append("	, [PreferredSelectSQL] = '%1'").arg(m_strPreferredSelect);
	sSQL.append("	, [PreferredInsertSQL] = '%1'").arg(m_strPreferredInsert);
	sSQL.append("	, [PreferredUpdateSQL] = '%1'").arg(m_strPreferredUpdate);

	sSQL.append("	, [FieldCnt] = '%1' ").arg(m_uFieldCnt);
	sSQL.append(" where profileName = '%1' and tableName = '%2'").arg(m_strProfileName).arg(m_strTableName);
	return sSQL;
}

QString nvTablesClass::getInsertSqlStatement()
{
	QString sSQL;
	sSQL.append("INSERT INTO [dbo].[NVTables] (");
	sSQL.append(" [ProfileName] ");
	sSQL.append(",[TableName] ");
	sSQL.append(",[Status] ");
	sSQL.append(",[PreferredSelectSQL]");
	sSQL.append(",[PreferredInsertSQL]");
	sSQL.append(",[PreferredUpdateSQL]");
	sSQL.append(",[FieldCnt]");
	sSQL.append(",[fetchSQL]");
	sSQL.append(",[insertSql]");
	sSQL.append(",[updateSql]");
	sSQL.append(" ) VALUES (");
	sSQL.append(QString("'%1'").arg(m_strProfileName));
	sSQL.append(QString(",'%1'").arg(m_strTableName.trimmed()));
	sSQL.append(QString(",%1").arg(m_uStatus));
	sSQL.append(QString(",'%1'").arg(m_strPreferredSelect));
	sSQL.append(QString(",'%1'").arg(m_strPreferredInsert));
	sSQL.append(QString(",'%1'").arg(m_strPreferredUpdate));

	sSQL.append(QString(",%1 ").arg(m_uFieldCnt));
	sSQL.append(QString(",'%1'").arg(m_strPreferredSelect));
	sSQL.append(QString(",'%1'").arg(m_strPreferredInsert));
	sSQL.append(QString(",'%1'").arg(m_strPreferredUpdate));

	sSQL.append(")");
	return sSQL;
}
