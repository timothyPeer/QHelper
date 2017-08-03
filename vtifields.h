// ***********************************************************************
// Assembly         : 
// Author           : Tim Peer
// Created          : 07-10-2017
//
// Last Modified By : Tim Peer
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="vtifields.h" company="eNVy Systems, Inc.">
//     Copyright (c) eNVy Systems, Inc.. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#ifndef VTIFIELDS_H
#define VTIFIELDS_H

#include <QObject>
#include <QString>
#include <QVariant>





/// <summary>
/// The myEnumerations namespace.
/// </summary>
namespace myEnumerations
{
	/// <summary>
	/// Enum RdbFieldEnums
	/// </summary>
	typedef  enum RdbFieldEnums
    {
		/// <summary>
		/// The Oracle Rdb column RDB$RELATION_NAME
		///
		/// Usage: When referencing field names in the following SQL query.
		/// select RDB$RELATION_NAME,RDB$FIELD_NAME,RDB$FIELD_SOURCE,RDB$FIELD_ID FROM RDB$RELATION_FIELDS WHERE RDB$RELATION_NAME = '{tablename}' ORDER BY  RDB$RELATION_NAME, RDB$FIELD_POSITION
		/// </summary>
		RDB$RELATION_NAME = 0,
		/// <summary>
		/// The Oracle Rdb column RDB$FIELD_NAME
		/// </summary>
		RDB$FIELD_NAME = 1,
		/// <summary>
		/// The Oracle Rdb column RDB$FIELD_SOURCE
		/// </summary>
		RDB$FIELD_SOURCE = 2
    } RdbFields;
}

/// <summary>
/// Class vtiFields.
/// </summary>
/// <seealso cref="QObject" />
class vtiFields : public QObject
{
    Q_OBJECT
public:
    explicit vtiFields(QObject *parent = nullptr);

	/// <summary>
	/// Destructor for an instance of the <see cref="vtiFields" /> class.
	/// </summary>
	~vtiFields();
	/// <summary>
	/// Sets the name of the field.
	/// </summary>
	/// <param name="field_Name">Name of the field.</param>
	void setFieldName(const QString field_Name) { fieldName = field_Name; }
	/// <summary>
	/// Sets the name of the table.
	/// </summary>
	/// <param name="table_Name">Name of the table.</param>
	void setTableName(const QString table_Name) { tableName = table_Name; }
	/// <summary>
	/// Gets the name of the table.
	/// </summary>
	/// <returns>QString</returns>
	QString getTableName() { return tableName; }
	/// <summary>
	/// Sets the field.
	/// </summary>
	/// <param name="field_Name">Name of the field.</param>
	/// <param name="field_Type">Type of the field.</param>
	void setField(const QString field_Name, const QString field_Type) { fieldName = field_Name; fieldType = field_Type; }
	/// <summary>
	/// Sets the type of the field.
	/// </summary>
	/// <param name="field_Type">Type of the field.</param>
	void setFieldType(const QString field_Type) { fieldType = field_Type; }
	/// <summary>
	/// Gets the name of the field.
	/// </summary>
	/// <returns>QString</returns>
	QString getFieldName() { return fieldName; }
	/// <summary>
	/// Gets the name of the target field.
	/// </summary>
	/// <returns>QString</returns>
	QString getTargetFieldName() {
		if (fieldName == "DB_ID") fieldName = "Plant_Code";
		return fieldName; 
	}
	/// <summary>
	/// Gets the type of the field.
	/// </summary>
	/// <returns>QString</returns>
	QString getFieldType() { return fieldType; }

	/// <summary>
	/// Gets the type of the variant.
	/// </summary>
	/// <param name="str">The string.</param>
	/// <returns>QString</returns>
	static QString getVariantType(QString str);
signals:

public slots:
private:
    QString fieldName;
	/// <summary>
	/// The field type
	/// </summary>
	QString fieldType;
	/// <summary>
	/// The table name
	/// </summary>
	QString tableName;
};

#endif // VTIFIELDS_H
