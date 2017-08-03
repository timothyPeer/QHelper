// ***********************************************************************
// Assembly         : 
// Author           : Tim Peer
// Created          : 07-10-2017
//
// Last Modified By : Tim Peer
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="nvprofilesclass.h" company="eNVy Systems, Inc.">
//     Copyright (c) eNVy Systems, Inc.. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#ifndef NVPROFILESCLASS_HPP
#define NVPROFILESCLASS_HPP
#include <QObject>

/// <summary>
/// Class nvProfilesClass.
/// </summary>
/// <seealso cref="QObject" />
class nvProfilesClass : public QObject {


	Q_OBJECT
public:



	nvProfilesClass(QObject * parent = Q_NULLPTR);
	/// <summary>
	/// Finalizes an instance of the <see cref="nvProfilesClass"/> class.
	/// </summary>
	virtual ~nvProfilesClass() override;
	/// <summary>
	/// Gets the update SQL statement.
	/// </summary>
	/// <returns>QString</returns>
	QString getUpdateSqlStatement();
	/// <summary>
	/// Gets the insert SQL statement.
	/// </summary>
	/// <returns>QString</returns>
	QString getInsertSqlStatement();
	/// <summary>
	/// Sets the name of the profile.
	/// </summary>
	/// <param name="str">The string.</param>
	void	setProfileName(const QString str) {
		str.toUpper();
		m_strProfileName = str;

	}
	/// <summary>
	/// Sets the profile'sdescription.
	/// </summary>
	/// <param name="str">The string.</param>
	void setProfileDescription(const QString str)
	{
		m_strDescription = str;
	}

	/// <summary>
	/// Sets the execution threads.
	/// </summary>
	/// <param name="threadCount">The thread count.</param>
	void setExecutionThreads(int threadCount)
	{
		m_iExecuteThreads = threadCount;
	}

	/// <summary>
	/// Sets the commit throttle.
	/// </summary>
	/// <param name="commitCount">The commit count.</param>
	void setCommitThrottle(int commitCount)
	{
		m_iCommitThrottle = commitCount;
	}

	/// <summary>
	/// Sets the profile'senabled.
	/// </summary>
	/// <param name="bEnabled">The b enabled.</param>
	void setProfileEnabled(bool bEnabled)
	{
		m_bProfileEnabled = bEnabled;
	}
	/// <summary>
	/// Sets the profile's trace enabled.
	/// </summary>
	/// <param name="bEnabled">The b enabled.</param>
	void setProfileTraceEnabled(bool bEnabled)
	{
		m_bProfileTraceEnabled = bEnabled;
	}

	/// <summary>
	/// Sets the profile's automatic commit enabled.
	/// </summary>
	/// <param name="bEnabled">True or False</param>
	void setProfileAutoCommitEnabled(bool bEnabled)
	{
		m_bAutoCommitEnabled = bEnabled;
	}

	/// <summary>
	/// Sets the profile's target DSN string.
	/// </summary>
	/// <param name="dsn">The DSN.</param>
	void setProfileTargetDSNString(const QString dsn)
	{
		m_strTargetDSN = dsn;
	}

	/// <summary>
	/// Sets the profile's source DSN string.
	/// </summary>
	/// <param name="dsn">The DSN.</param>
	void setProfileSourceDSNString(const QString dsn)
	{
		m_strSourceDSN = dsn;
	}

	/// <summary>
	/// Sets the profile's log file.
	/// </summary>
	/// <param name="logName">Name of the log.</param>
	void setProfileLogFile(const QString logName)
	{
		m_strNvLogFile = logName;
	}
	/// <summary>
	/// Sets the size of the profile network packet.
	/// </summary>
	/// <param name="packetSize">The network packet size in bytes.</param>
	void setProfileNetworkPacketSize(int packetSize)
	{
		m_iNetworkPacketSize = packetSize;
	}
	/// <summary>
	/// Sets the profile's TRG drop option.
	/// </summary>
	/// <param name="TrgOption">The TRG option.</param>
	void setProfileTrgDropOption(int TrgOption) { m_iProfileTrgDropOption = TrgOption; }
	/// <summary>
	/// Sets the transaction logging level for the profile.
	/// <p>
	/// <note>When configuring logging, logging level up to this level is logged.  
	///  example:  The Info level of logging enables Fatal, Error, Warning and Info
	/// </note>
	/// <list type = "bullet">Log Levels Supported======< / list>
	/// <item>
	/// <term>none< / term> <description>Logging is disabled.</description> </term>
	/// <term>TraceLevel< / term> <description>Trace Level Logging.</description> </term>
	/// <term>DebugLevel< / term> <description>Debug Level Logging.</description> </term>
	/// <term>InfoLevel< / term> <description>Info Level Logging.</description> </term>
	/// <term>WarnLevel< / term> <description>Warning Level Logging.</description> </term>
	/// <term>ErrorLevel< / term> <description>Error Level Logging.</description> </term>
	/// <term>FatalLevel< / term> <description>Fatal Level Logging.</description> </term>
	/// </p>
	/// </summary>
	/// <param name="logLevel">The log level used by the application.</param>
	void setProfileTransactionLogLevel(int logLevel) { m_iTransactionLogLevel = logLevel; }

	/// <summary>
	/// Gets the profile enabled.
	/// </summary>
	/// <returns>bool.</returns>
	bool getProfileEnabled() { return m_bProfileEnabled; }
	/// <summary>
	/// Gets the profile trace enabled.
	/// </summary>
	/// <returns>bool.</returns>
	bool getProfileTraceEnabled() { return m_bProfileTraceEnabled; }
	/// <summary>
	/// Gets the profile automatic commit enabled.
	/// </summary>
	/// <returns>bool.</returns>
	bool getProfileAutoCommitEnabled() { return m_bAutoCommitEnabled; }
	/// <summary>
	/// Gets the name of the profile.
	/// </summary>
	/// <returns>QString</returns>
	QString getProfileName() { return m_strProfileName; }
	/// <summary>
	/// Gets the profile description.
	/// </summary>
	/// <returns>QString</returns>
	QString getProfileDescription() { return m_strDescription; }
	/// <summary>
	/// Gets the profile source DSN.
	/// </summary>
	/// <returns>QString</returns>
	QString getProfileSourceDSN() { return m_strSourceDSN; }
	/// <summary>
	/// Gets the profile target DSN.
	/// </summary>
	/// <returns>QString</returns>
	QString getProfileTargetDSN() { return m_strTargetDSN; }
	/// <summary>
	/// Gets the profile execution threads.
	/// </summary>
	/// <returns>int.</returns>
	int getProfileExecutionThreads() { return m_iExecuteThreads; }
	/// <summary>
	/// Gets the profile commit throttle.
	/// </summary>
	/// <returns>int.</returns>
	int getProfileCommitThrottle() { return m_iCommitThrottle; }
	/// <summary>
	/// Gets the profile TRG drop option.
	/// </summary>
	/// <returns>int.</returns>
	int getProfileTrgDropOption() { return m_iProfileTrgDropOption; }
	/// <summary>
	/// Gets the profile transaction log level.
	/// </summary>
	/// <returns>int.</returns>
	int getProfileTransactionLogLevel() { return m_iTransactionLogLevel; }
	/// <summary>
	/// Gets the name of the profile log file.
	/// </summary>
	/// <returns>QString</returns>
	QString getProfileLogFileName() { return m_strNvLogFile; }
	/// <summary>
	/// Gets the transaction logging enabled.
	/// </summary>
	/// <returns>int.</returns>
	int getTransactionLoggingEnabled() { return m_bTransactionLoggingEnabled; }
	/// <summary>
	/// Sets the transaction logging enabled.
	/// </summary>
	/// <param name="enabled">The enabled.</param>
	void setTransactionLoggingEnabled(int enabled) { m_bTransactionLoggingEnabled = enabled; }

private:

	/// <summary>
	/// The m b profile enabled
	/// </summary>
	bool m_bProfileEnabled;
	/// <summary>
	/// The m b profile trace enabled
	/// </summary>
	bool m_bProfileTraceEnabled;
	/// <summary>
	/// The m b automatic commit enabled
	/// </summary>
	bool m_bAutoCommitEnabled;
	/// <summary>
	/// The m b transaction logging enabled
	/// </summary>
	bool m_bTransactionLoggingEnabled;

	/// <summary>
	/// The m string profile name
	/// </summary>
	QString m_strProfileName;
	/// <summary>
	/// The m string description
	/// </summary>
	QString m_strDescription;
	/// <summary>
	/// The m string source DSN
	/// </summary>
	QString m_strSourceDSN;
	/// <summary>
	/// The m string target DSN
	/// </summary>
	QString m_strTargetDSN;
	/// <summary>
	/// The m i execute threads
	/// </summary>
	int		m_iExecuteThreads;
	/// <summary>
	/// The m i commit throttle
	/// </summary>
	int		m_iCommitThrottle;
	/// <summary>
	/// The m i profile TRG drop option
	/// </summary>
	int		m_iProfileTrgDropOption;
	/// <summary>
	/// The m i transaction log level
	/// </summary>
	int		m_iTransactionLogLevel;
	/// <summary>
	/// The m i network packet size
	/// </summary>
	int		m_iNetworkPacketSize;
	/// <summary>
	/// The m string nv log file
	/// </summary>
	QString	m_strNvLogFile;
   // int		m_uStatus;
	
};

#endif // NVPROFILESCLASS_HPP
