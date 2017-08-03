// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="qnvtables.h" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#ifndef QNVTABLES_HPP
#define QNVTABLES_HPP
#include <QObject>
#include <QPointer>
#include <QVector>
#include "qNvRepository.h"
#include "nvtablesclass.h"
#include "qRCEnumDef.h"
#include "qvtexecute.h"
#include "nvtable.h"
#include <QStringList>

/// <summary>
/// Class qNvTables.
/// </summary>
/// <seealso cref="qNvRepository" />
class qNvTables : public qNvRepository {
	Q_OBJECT

public:
	qNvTables(QObject * parent = Q_NULLPTR);
	/// <summary>
	/// Destructor for an instance of the <see cref="qNvTables"/> class.
	/// </summary>
	~qNvTables();

	/// <summary>
	/// Initializes the specified profile name.
	/// </summary>
	/// <param name="profileName">Name of the profile.</param>
	void initialize(const QString profileName);
	/// <summary>
	/// Initializes the specified profile name.
	/// </summary>
	/// <param name="profileName">Name of the profile.</param>
	/// <param name="tableName">Name of the table.</param>
	void initialize(const  QString profileName, const QString tableName);
	/// <summary>
	/// Updates the specified status flag.
	/// </summary>
	/// <param name="statusFlag">The status flag.</param>
	void update(enumerateClass::nvTableStatusFlags statusFlag);
	/// <summary>
	/// The m p nv tables class
	/// </summary>
	QPointer<nvTablesClass>  m_pNvTablesClass;
	/// <summary>
	/// Executes the SQL set class.
	/// </summary>
	void	ExecuteSQLSetClass();
	/// <summary>
	/// Sets the name of the table.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	void	setTableName(const QString tableName);
	/// <summary>
	/// Fetches the table.
	/// </summary>
	void    fetchTable();
	/// <summary>
	/// Sqltableses this instance.
	/// </summary>
	/// <returns>QStringList.</returns>
	QStringList     SQLTABLES();

	/// <summary>
	/// The table vector
	/// </summary>
	QVector<nvTable> tableVector;           // contains a sequential list of tables classes processed.
private:
	/// <summary>
	/// The m string table name
	/// </summary>
	QString		m_strTableName;
	/// <summary>
	/// The exists set
	/// </summary>
	bool        existsSet;
	/// <summary>
	/// The m sqltables
	/// </summary>
	QStringList m_SQLTABLES;

};

#endif // QNVTABLES_HPP
