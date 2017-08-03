// ***********************************************************************
// Assembly         : 
// Author           : Tim Peer
// Created          : 07-10-2017
//
// Last Modified By : Tim Peer
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="qclogobject.h" company="eNVy Systems, Inc.">
//     Copyright (c) eNVy Systems, Inc.. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#ifndef QCLOGOBJECT_HPP
#define QCLOGOBJECT_HPP
#include <QObject>
#include <QStringList>
#include "qRCEnumDef.h"

#include <QPointer>

/// <summary>
/// Class qCLogObject.
/// </summary>
/// <seealso cref="QObject" />
class qCLogObject : public QObject {
	Q_OBJECT

public:
	qCLogObject(QObject * parent = Q_NULLPTR);
	/// <summary>
	/// Finalizes an instance of the <see cref="qCLogObject"/> class.
	/// </summary>
	virtual ~qCLogObject() override;


	/// <summary>
	/// Gets the default name of the file.
	/// </summary>
	/// <returns>QString</returns>
	QString getDefaultFileName() { return m_DefaultFileName; }
	/// <summary>
	/// Gets the default name of the DSN.
	/// </summary>
	/// <returns>QString</returns>
	QString getDefaultDSNName() { return m_DefaultDSNName; }

	
	/// <summary>
	/// Sets the default target type.
	/// </summary>
	/// <param name="uTarget">The u target.</param>
	static void setDefaultTarget(int uTarget) { m_uDefaultTarget = uTarget; }
	/// <summary>
	/// Sets the default level.
	/// </summary>
	/// <param name="nLevel">The n level.</param>
	static void setDefaultLevel(enumerateClass::LoggerLevel nLevel) { m_nDefaultLevel = (enumerateClass::LoggerLevel)(nLevel); }

	/// <summary>
	/// Sets the default name of the database table.
	/// </summary>
	/// <param name="lpszTableName">Name of the LPSZ table.</param>
	void setDefaultDBTableName(const QString lpszTableName) { m_DefaultDBTableName = lpszTableName; }
	/// <summary>
	/// Sets the default name of the DSN.
	/// </summary>
	/// <param name="dsnName">Name of the DSN.</param>
	void setDefaultDSNName(const QString dsnName) { m_DefaultDSNName = dsnName; }
	/// <summary>
	/// Sets the default name of the file.
	/// </summary>
	/// <param name="lpszFilename">The LPSZ filename.</param>
	void setDefaultFileName(const QString lpszFilename) { m_DefaultFileName = lpszFilename; }
	/// <summary>
	/// Sets the default file ext.
	/// </summary>
	/// <param name="lpszFileExt">The LPSZ file ext.</param>
	void setDefaultFileExt(const QString lpszFileExt) { m_DefaultFileExt = lpszFileExt; }
	/// <summary>
	/// Sets the default HTML ext.
	/// </summary>
	/// <param name="lpszHtmlExt">The LPSZ HTML ext.</param>
	void setDefaultHtmlExt(const QString lpszHtmlExt) { m_DefaultHtmlExt = lpszHtmlExt; }
	
	/// <summary>
	/// Sets the target.
	/// </summary>
	/// <param name="uTarget">The u target.</param>
	void setTarget(int uTarget) { m_uTarget = uTarget; }
	/// <summary>
	/// Sets the level.
	/// </summary>
	/// <param name="nLevel">The n level.</param>
	void setLevel(enumerateClass::LoggerLevel nLevel) { m_nLevel = nLevel; }
	/// <summary>
	/// Sets the u target.
	/// </summary>
	/// <param name="target">The target.</param>
	void setUTarget(int target) { m_uTarget = target; }
	/// <summary>
	/// Sets the u default target.
	/// </summary>
	/// <param name="target">The target.</param>
	void setUDefaultTarget(int target) { m_uDefaultTarget = target; }
	/// <summary>
	/// Clears the attributes.
	/// </summary>
	void clearAttributes() { m_AttrArray.clear(); }
	/// <summary>
	/// Determines whether the specified LPSZ attribute name has attribute.
	/// </summary>
	/// <param name="lpszAttrName">Name of the LPSZ attribute.</param>
	/// <returns>bool.</returns>
	bool hasAttribute(const QString lpszAttrName);
	/// <summary>
	/// Sets the attribute.
	/// </summary>
	/// <param name="lpszAttrName">Name of the LPSZ attribute.</param>
	/// <param name="lpszAttrValue">The LPSZ attribute value.</param>
	/// <param name="bAutoCreate">The b automatic create.</param>
	/// <returns>bool.</returns>
	bool setAttribute(const QString lpszAttrName, const QString lpszAttrValue, bool bAutoCreate = true);
	
	/// <summary>
	/// Gets the attribute value.
	/// </summary>
	/// <param name="lpszAttrName">Name of the LPSZ attribute.</param>
	/// <returns>QString</returns>
	QString getAttributeValue(const QString lpszAttrName);

	/// <summary>
	/// Copies the attributes.
	/// </summary>
	/// <param name="obj">The object.</param>
	void copyAttributes(qCLogObject& obj);
	/// <summary>
	/// Copies the targets.
	/// </summary>
	/// <param name="obj">The object.</param>
	void copyTargets(qCLogObject& obj);
	/// <summary>
	/// Copies all settings.
	/// </summary>
	/// <param name="obj">The object.</param>
	void copyAllSettings(qCLogObject& obj);

	/// <summary>
	/// Sets the file.
	/// </summary>
	/// <param name="lpszFilename">The LPSZ filename.</param>
	/// <param name="bAppend">The b append.</param>
	void setFile(const QString lpszFilename, bool bAppend = true);

	// Main logging method
/// <summary>
/// Logs the specified level.
/// </summary>
/// <param name="level">The level.</param>
/// <param name="format">The format.</param>
	void log(enumerateClass::LoggerLevel level, const QString format, ...);

	// overridable methods for string formatting
/// <summary>
/// Gets the time string.
/// </summary>
/// <returns>const QString.</returns>
	virtual const QString getTimeString();
	/// <summary>
	/// Gets the attribute string.
	/// </summary>
	/// <returns>const QString.</returns>
	virtual const QString getAttributeString();
	/// <summary>
	/// Formats the log string.
	/// </summary>
	/// <returns>const QString.</returns>
	virtual const QString formatLogString();
	/// <summary>
	/// Formats the HTML string.
	/// </summary>
	/// <returns>const QString.</returns>
	virtual const QString formatHtmlString();

	// overridable methods for logging operation
/// <summary>
/// Logs to debug.
/// </summary>
/// <returns>bool.</returns>
	virtual bool logToDebug();
	/// <summary>
	/// Logs to file.
	/// </summary>
	/// <returns>bool.</returns>
	virtual bool logToFile();
	/// <summary>
	/// Logs to console.
	/// </summary>
	/// <returns>bool.</returns>
	virtual bool logToConsole();
	/// <summary>
	/// Logs to database.
	/// </summary>
	/// <returns>bool.</returns>
	virtual bool logToDatabase();
	/// <summary>
	/// Logs to event log.
	/// </summary>
	/// <returns>bool.</returns>
	virtual bool logToEventLog();
	/// <summary>
	/// Logs to HTML.
	/// </summary>
	/// <returns>bool.</returns>
	virtual bool logToHtml();

private:
	/// <summary>
	/// The m u reference count
	/// </summary>
	static int    m_uRefCount;

	/// <summary>
	/// The m u default target
	/// </summary>
	static int    m_uDefaultTarget;
	/// <summary>
	/// The m n default level
	/// </summary>
	static enumerateClass::LoggerLevel     m_nDefaultLevel;

	/// <summary>
	/// The m default new line
	/// </summary>
	static const QString m_DefaultNewLine;

	/// <summary>
	/// The m default DSN name
	/// </summary>
	QString m_DefaultDSNName;
	/// <summary>
	/// The m default database table name
	/// </summary>
	QString m_DefaultDBTableName;

	 /// <summary>
	 /// The m default file name
	 /// </summary>
	 QString m_DefaultFileName;
	/// <summary>
	/// The m default file ext
	/// </summary>
	QString m_DefaultFileExt;
	/// <summary>
	/// The m default HTML ext
	/// </summary>
	QString m_DefaultHtmlExt;

	/// <summary>
	/// The m b database reference
	/// </summary>
	static bool    m_bDBRef;
	/// <summary>
	/// The m b event log reference
	/// </summary>
	static bool    m_bEventLogRef;
	/// <summary>
	/// The m b console reference
	/// </summary>
	static bool    m_bConsoleRef;

	// retrieve the setting for operation
	// if object setting doesn't exist, return global setting
/// <summary>
/// Gets the name of the DSN.
/// </summary>
/// <returns>QString</returns>
	QString getDSNName();
	/// <summary>
	/// Gets the name of the database table.
	/// </summary>
	/// <returns>QString</returns>
	QString getDBTableName();
	/// <summary>
	/// Gets the name of the file.
	/// </summary>
	/// <returns>QString</returns>
	QString getFileName();
	/// <summary>
	/// Gets the level.
	/// </summary>
	/// <returns>int.</returns>
	int     getLevel();


	/// <summary>
	/// Gets the file open flags.
	/// </summary>
	/// <returns>int.</returns>
	int     getFileOpenFlags();
	/// <summary>
	/// Logs to target.
	/// </summary>
	/// <param name="uTarget">The u target.</param>
	/// <returns>bool.</returns>
	bool    logToTarget(int uTarget);

	/// <summary>
	/// The m attribute array
	/// </summary>
	QStringList	 m_AttrArray;
	/// <summary>
	/// The m log MSG
	/// </summary>
	QString      m_LogMsg;
	/// <summary>
	/// The m u target
	/// </summary>
	int         m_uTarget;
	/// <summary>
	/// The m n level
	/// </summary>
	enumerateClass::LoggerLevel          m_nLevel;
	/// <summary>
	/// The m u current level
	/// </summary>
	enumerateClass::LoggerLevel         m_uCurrentLevel;
	/// <summary>
	/// The m DSN name
	/// </summary>
	QString      m_DSNName;
	/// <summary>
	/// The m database table name
	/// </summary>
	QString      m_DBTableName;
	/// <summary>
	/// The m file name
	/// </summary>
	QString      m_FileName;
	//QPointer<qNDatabase>     m_Database;
/// <summary>
/// The m b append
/// </summary>
	bool		    m_bAppend;
};

#endif // QCLOGOBJECT_HPP