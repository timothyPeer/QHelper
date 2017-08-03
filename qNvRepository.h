// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="qNvRepository.h" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#ifndef qNvRepository_HPP
#define QqNvRepository_HPP
#include <QObject>
#include <QScopedPointer>
#include "connectionstringbuilder.h"


/// <summary>
/// Class qNvRepository.
/// </summary>
/// <seealso cref="QObject" />
class qNvRepository : public QObject {
	Q_OBJECT

public:
	qNvRepository(QObject * parent = Q_NULLPTR);
	/// <summary>
	/// Destructor for an instance of the <see cref="qNvRepository"/> class.
	/// </summary>
	~qNvRepository();

	/// <summary>
	/// Executes this instance.
	/// </summary>
	void execute();
    //QString getProfileName() { return m_strProfileName; }


protected:
	/// <summary>
	/// Sets the SQL statement.
	/// </summary>
	/// <param name="sqlStatement">The SQL statement.</param>
	void setSqlStatement(const QString sqlStatement);
  /// <summary>
/// Sets the name of the profile.
/// </summary>
/// <param name="profileName">Name of the profile.</param>
	void    setProfileName(const QString profileName) { m_strProfileName = profileName; }
	/// <summary>
	/// Initializes this instance.
	/// </summary>
	void initialize() {
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
        m_strConnectionString = builder->getEnvyConnectionString();
    }
	/// <summary>
	/// Gets the connection string.
	/// </summary>
	/// <returns>QString</returns>
	QString getConnectionString() { return m_strConnectionString; }
	/// <summary>
	/// Gets the SQL statement.
	/// </summary>
	/// <returns>QString</returns>
	QString getSqlStatement() { return m_strSqlStatement; }
	/// <summary>
	/// Gets the name of the profile.
	/// </summary>
	/// <returns>QString</returns>
	QString getProfileName() { return m_strProfileName; }


	/// <summary>
	/// The m string connection string
	/// </summary>
	QString		m_strConnectionString;

	/// <summary>
	/// The m string SQL statement
	/// </summary>
	QString		m_strSqlStatement;
private:
	/// <summary>
	/// The m string profile name
	/// </summary>
	QString		m_strProfileName;

};

#endif // QNVTABLES_HPP
