#ifndef CLSTABLEFIELDS_H
#define CLSTABLEFIELDS_H

#include <QObject>
#include <QMultiHash>
#include <QString>
#include "vtifields.h"
#include <QStringList>
#include <QList>
#include <QUuid>
#include <QSqlDatabase>

class clsTableFields : public QObject
{
	Q_OBJECT
public:
	explicit clsTableFields(QObject *parent = 0);
	~clsTableFields();

	QMultiHash<QString, vtiFields*> tableFields;

	void initialize(const QString DSN, const QString profile_Name, const QString table_Name);
	void loadFieldsToTable(const QString connectionString);
	void setPreferredSelectSQL(const QString str) { preferredSelectSQL = str; }
	void setPreferredInsertSQL(const QString str) { preferredInsertSQL = str; }
	void setPreferredUpdateSQL(const QString str) { preferredUpdateSQL = str; }
	QString getPreferredSelectSQL();
	QString getPreferredInsertSQL(); //{ return preferredInsertSQL; }
	QString getPreferredUpdateSQL(); //{ return preferredUpdateSQL; }
	void setFieldCnt(int field_Cnt) { fieldCnt = field_Cnt; }
	void setTableName(QString table_Name) { tableName = table_Name; }
	void setProfileName(QString profile_Name) { profileName = profile_Name; }
	void setDataSourceConnectionString(QString str) { dataSourceConnectionString = QString(str); }
	void buildString();

	void commitToDatabase();
	int getFieldCnt() { return fieldCnt; }
	void clear();


signals:

	public slots :
private:
	QString preferredSelectSQL;
	QString preferredInsertSQL;
	QString preferredUpdateSQL;
	int fieldCnt;
	QString tableName;
	QString profileName;
	QString dataSourceConnectionString;
	QString stmt;
	QMultiHash<QString, vtiFields*> mapTableInfo;
	QList<vtiFields *> fieldInfo;
	QList<vtiFields*> reverseStringList(const QList<vtiFields*> &list)
	{
		QList<vtiFields*>	myList = list;
		std::reverse(myList.begin(), myList.end());
		return myList;
	}
	QUuid m_uid;
	QSqlDatabase db;
	void close();
	void init(const QString stmt);
}

#endif // CLSTABLEFIELDS_H
