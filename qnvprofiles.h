// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="qnvprofiles.h" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#ifndef QNVPROFILES_HPP
#define QNVPROFILES_HPP
#include <QObject>
#include <QPointer>
#include "qNvRepository.h"
#include "nvprofilesclass.h"
#include "qRCEnumDef.h"

/// <summary>
/// Class qNvProfiles.
/// </summary>
/// <seealso cref="qNvRepository" />
class qNvProfiles : public qNvRepository {
	Q_OBJECT

public:
	qNvProfiles(QObject * parent = Q_NULLPTR);
	/// <summary>
	/// Destructor for an instance of the <see cref="qNvProfiles"/> class.
	/// </summary>
	virtual ~qNvProfiles() override;
	/// <summary>
	/// Initializes the specified profile name.
	/// </summary>
	/// <param name="profileName">Name of the profile.</param>
	void initialize(const QString profileName);
	/// <summary>
	/// The m p profiles class
	/// </summary>
	QPointer<nvProfilesClass>  m_pProfilesClass;
	/// <summary>
	/// Executes the SQL set class.
	/// </summary>
	void	ExecuteSQLSetClass();
	/// <summary>
	/// The Profile Exists.
	/// </summary>
	/// <returns>bool.</returns>
	bool exists() { return m_bExists; }

/// <summary>
/// Profiles the exists.
/// </summary>
/// <returns>bool.</returns>
	bool profileExists();
private:
	/// <summary>
	/// The m b exists
	/// </summary>
	bool m_bExists;

};

#endif // QNVPROFILES_HPP
