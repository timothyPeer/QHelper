// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 07-31-2017
// ***********************************************************************
// <copyright file="nvtable.h" company="eNVy Systems, Inc.">
//     Copyright (c) 2017. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#ifndef NVTABLE_H
#define NVTABLE_H

#include <QObject>
#include <QtCore>

/// <summary>
/// Class nvTable.
/// </summary>
/// <seealso cref="QObject" />
class nvTable : public QObject
{
    Q_OBJECT
public:
    explicit nvTable(QObject *parent = nullptr);

	/// <summary>
	/// Initializes the specified table name.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="dsnString">The DSN string.</param>
	void initialize(const QString tableName, const QString dsnString);
	/// <summary>
	/// Opens the database and get field list.
	/// </summary>
	void openDatabaseAndGetFieldList();
	/// <summary>
	/// Updates the commands.
	/// </summary>
	/// <param name="FieldName">Name of the field.</param>
	/// <param name="FieldSource">The field source.</param>
	void updateCommands(QString FieldName, QString FieldSource);
	/// <summary>
	/// Gets the type of the variant.
	/// </summary>
	/// <param name="str">The string.</param>
	/// <returns>QVariant.</returns>
	QVariant getVariantType(const QString str);
	/// <summary>
	/// Sets the commit only.
	/// </summary>
	/// <param name="commitMe">The commit me.</param>
	void    setCommitOnly(bool commitMe) { commitOnly = commitMe; }
	/// <summary>
	/// Gets the insert SQL.
	/// </summary>
	/// <returns>QString</returns>
	QString getInsertSQL() { return insertSQL; }
	/// <summary>
	/// Gets the update SQL.
	/// </summary>
	/// <returns>QString</returns>
	QString getUpdateSQL() { return updateSQL; }
	/// <summary>
	/// Gets the create table SQL.
	/// </summary>
	/// <returns>QString</returns>
	QString getCreateTableSQL() { return createTableSQL; }
	/// <summary>
	/// Sets the source DSN.
	/// </summary>
	/// <param name="dsnString">The DSN string.</param>
	void setSourceDSN(const QString dsnString) { strDsnString = dsnString; }

	/// <summary>
	/// Gets the select SQL.
	/// </summary>
	/// <returns>QString</returns>
	QString getSelectSQL()
	{
		return selectSQL;
	}
signals:

public slots:

private:
    QString     insertSQL;
	/// <summary>
	/// The update SQL
	/// </summary>
	QString     updateSQL;
	/// <summary>
	/// The delete from SQL
	/// </summary>
	QString     deleteFromSQL;
	/// <summary>
	/// The fetch SQL
	/// </summary>
	QString     fetchSQL;
	/// <summary>
	/// The select SQL
	/// </summary>
	QString     selectSQL;
	/// <summary>
	/// The create table SQL
	/// </summary>
	QString     createTableSQL;
	/// <summary>
	/// The table name
	/// </summary>
	QString     tableName;
	/// <summary>
	/// The insert values
	/// </summary>
	QString     insertValues;
	/// <summary>
	/// Gets the name of the safe field.
	/// </summary>
	/// <param name="str">The string.</param>
	/// <returns>QString</returns>
	QString     getSafeFieldName(QString str);
	/// <summary>
	/// The string DSN string
	/// </summary>
	QString	    strDsnString;
	/// <summary>
	/// The commit only
	/// </summary>
	bool        commitOnly;
	/// <summary>
	/// Commits the profile.
	/// </summary>
	void        commitProfile();
	/// <summary>
	/// Commits the table.
	/// </summary>
	/// <param name="table">The table.</param>
	void        commitTable(QString table);
	/// <summary>
	/// Gets the size of the field type.
	/// </summary>
	/// <param name="str">The string.</param>
	/// <returns>QString</returns>
	QString     getFieldTypeSize(const QString str);
};

#endif // NVTABLE_H
