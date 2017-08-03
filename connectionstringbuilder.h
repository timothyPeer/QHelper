// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="connectionStringBuilder.h" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#ifndef CONNECTIONSTRINGBUILDER_H
#define CONNECTIONSTRINGBUILDER_H

#include <QObject>
#include <QString>
#include <QLoggingCategory>
#include <QSettings>


/// <summary>
/// Class connectionStringBuilder.
/// </summary>
/// <seealso cref="QObject" />
class connectionStringBuilder : public QObject
{

    Q_OBJECT

public:
    explicit connectionStringBuilder(QObject * parent = Q_NULLPTR);
	/// <summary>
	/// Destructor for an instance of the <see cref="connectionStringBuilder"/> class.
	/// </summary>
	~connectionStringBuilder();
	/// <summary>
	/// The connection string base RDB
	/// </summary>
	QString connectionStringBaseRdb;
	/// <summary>
	/// The connection string base SQL
	/// </summary>
	QString connectionStringBaseSql;
	/// <summary>
	/// The connection string base envy
	/// </summary>
	QString connectionStringBaseEnvy;

	/// <summary>
	/// Gets the connection string source.
	/// </summary>
	/// <returns>QString</returns>
	QString getConnectionStringSource();
	/// <summary>
	/// Gets the connection string target.
	/// </summary>
	/// <returns>QString</returns>
	QString getConnectionStringTarget();
	/// <summary>
	/// Sets the RDB credentials.
	/// </summary>
	/// <param name="hostName">Name of the host.</param>
	/// <param name="databaseName">Name of the database.</param>
	/// <param name="uid">The uid.</param>
	/// <param name="pwd">The password.</param>
	void setRdbCredentials(QString hostName, QString databaseName, QString uid, QString pwd);
	/// <summary>
	/// Sets the SQL credentials.
	/// </summary>
	/// <param name="hostname">The hostname.</param>
	/// <param name="databaseName">Name of the database.</param>
	/// <param name="uid">The uid.</param>
	/// <param name="pwd">The password.</param>
	void setSqlCredentials(QString hostname, QString databaseName, QString uid, QString pwd);

	/// <summary>
	/// Sets the maximum replication threads.
	/// </summary>
	/// <param name="maxThreads">The maximum threads.</param>
	void setMaxReplicationThreads(int maxThreads) { this->iMaxReplicationThreads = maxThreads; }
	/// <summary>
	/// Sets the envy credentials.
	/// </summary>

	void setEnvyCredentials();
	/// <summary>
	/// Gets the RDB connection string double quote.
	/// </summary>
	/// <returns>QString</returns>
	QString getRdbConnectionString_dblQuote();
	/// <summary>
	/// Gets the RDB connection string.
	/// </summary>
	/// <returns>QString</returns>
	QString getRdbConnectionString();
	/// <summary>
	/// Gets the SQL connection string.
	/// </summary>
	/// <returns>QString</returns>
	QString getSqlConnectionString();
	/// <summary>
	/// Gets the envy connection string.
	/// </summary>
	/// <returns>QString</returns>
	QString getEnvyConnectionString();
	/// <summary>
	/// Gets the maximum replication threads.
	/// </summary>
	/// <returns>int.</returns>
	int getMaxReplicationThreads() { return iMaxReplicationThreads; }
	/// <summary>
	/// The q profile machine identifier
	/// </summary>
	int qProfileMachineID;

	/// <summary>
	/// The q profile automatic commit enabled
	/// </summary>
	int qProfileAutoCommitEnabled;
	//void setDefaultQSettings();
	
/// <summary>
/// Clears this instance.
/// </summary>
	void clear();
	/// <summary>
	/// Parses the envy configuration statement.
	/// </summary>
	/// <param name="str">The string.</param>
	void parseEnvyConfigStatement(const QString str);


/// <summary>
/// Creates the envy RCQ.
/// </summary>
/// <returns>QString</returns>
	QString createEnvyRcq();
	/// <summary>
	/// Gets the nv profiles create.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvProfilesCreate() { return strProfilesCreate; }
	/// <summary>
	/// Gets the nv tables create.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvTablesCreate() { return strTablesCreate; }
	/// <summary>
	/// Gets the nv schedules create.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvSchedulesCreate() { return strSchedulesCreate; }
	/// <summary>
	/// Gets the nv profiles insert.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvProfilesInsert() { return strProfilesInsert; }
	/// <summary>
	/// Gets the nv tables insert.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvTablesInsert() { return strTablesInsert; }
	/// <summary>
	/// Gets the ODBC attributes.
	/// </summary>
	/// <returns>QString</returns>
	QString getOdbcAttributes() { return strOdbcAttributes; }
	/// <summary>
	/// Gets the nv tables select.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvTablesSelect() { return strTablesSelect; }
	/// <summary>
	/// Gets the nv profiles select.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvProfilesSelect() { return strProfilesSelect; }
	/// <summary>
	/// Gets the nv schedules select.
	/// </summary>
	/// <returns>QString</returns>
	QString getNvSchedulesSelect() { return strSchedulesSelect; }
	/// <summary>
	/// Enum RcAttributes
	/// </summary>
	enum RcAttributes {
		/// <summary>
		/// The eNVy Repository Data Source Name - should contain the qualified - well formed, ODBC Data Source 
		/// <see href = "https://www.connectionstrings.com/"[target = "_blank | _self | _parent | _top"][alt = "alternate text"]>Connection String Examples< / see>
		/// </summary>
		eNVyRepositoryDSN = 0,
		/// <summary>
		/// The maximum number of replication threads that will execute simultaneously.
		/// </summary>
		MaxReplicationThreads = 1,
		/// <summary>
		/// A static assignment for the create statement for NvProfiles
		/// </summary>
		NvProfilesCreate = 2,
		/// <summary>
		/// A static assignment for the create statement for NvTables
		/// </summary>
		NvTablesCreate = 3,
		/// <summary>
		/// A static assignment for the create statement for NvSchedules
		/// </summary>
		NvSchedulesCreate = 4,
		/// <summary>
		/// A static assignment for the create statement ODBC Attributes
		/// Default Values: SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3,SQL_ATTR_PACKET_SIZE=4096,SQL_ATTR_CONNECTION_POOLING=0,SQL_ATTR_LOGIN_TIMEOUT=0,SQL_ATTR_CONNECTION_TIMEOUT=0,SQL_ATTR_TRACE=0

/// 		<list type = "table">
/// 		<listHeader>
/// 		<term>SQL_ATTR_ODBC_VERSION< / term>
/// 		<term>Should be configured to SQL_OV_ODBC3< / term>
/// 		...
/// 		< / listHeader>
/// 		<item>
/// 		<description>SQL_ATTR_ODBC_VERSION< / description>
/// 		<description>Should be configured to SQL_OV_ODBC3< / description>
/// 		< / item>
/// 		<item>
/// 		<description>SQL_ATTR_PACKET_SIZE< / description>
/// 		<description>The size of the Network Packet to be used by the ODBC driver. Value: 4096< / description>
/// 		< / item>
/// 		<item>
/// 		<description>SQL_ATTR_CONNECTION_POOLING< / description>
/// 		<description>The connection pooling support. Value: 0< / description>
/// 		< / item>
/// 		<item>
/// 		<description>SQL_ATTR_LOGIN_TIMEOUT< / description>
/// 		<description>The ODBC Login timeout used by when authenticating to a data source. Value: 0< / description>
/// 		< / item>
/// 		<item>
/// 		<description>SQL_ATTR_CONNECTION_TIMEOUT< / description>
/// 		<description>The ODBC timeout used by when connecting to a data source. A value of 0 = no timeout; otherwise > 0 = seconds.  Value: 0< / description>
/// 		< / item>
/// 		<item>
/// 		<description>SQL_ATTR_TRACE< / description>
/// 		<description>The ODBC Trace Flag (enable or disable). A value of 0 = no trace.  Value: 0< / description>
/// 		< / item>
/// 		< / list>
/// </summary>

	OdbcAttributes = 5,
		/// <summary>
		/// A static assignment for the Insert statement for NvProfiles
		/// </summary>
		NvProfilesInsert = 6,
		/// <summary>
		/// A static assignment for the Insert statement for NvTables
		/// </summary>
		NvTablesInsert = 7,
		/// <summary>
		/// <summary>
		/// A static assignment for the Application Log File.  Default application log.
		/// </summary>
		NvApplicationLogFile = 8,
		/// <summary>
		/// A static assignment for the SELECT statement for NvProfiles
		/// </summary>
		NvProfilesSelect = 9,
		/// <summary>
		/// A static assignment for the SELECT statement for NvTables
		/// </summary>
		NvTablesSelect = 10,
		/// <summary>
		/// A static assignment for the SELECT statement for NvSchedules
		/// </summary>
		NvSchedulesSelect = 11
	};

signals:

public slots:
private:
	QString configXMLFile;
	/// <summary>
	/// The settings loaded
	/// </summary>
	bool settingsLoaded;
	/// <summary>
	/// The STRNV profiles create
	/// </summary>
	QString strProfilesCreate;
	/// <summary>
	/// The STRNV tables create
	/// </summary>
	QString strTablesCreate;
	/// <summary>
	/// The STRNV schedules create
	/// </summary>
	QString strSchedulesCreate;
	/// <summary>
	/// The STRNV profiles insert
	/// </summary>
	QString strProfilesInsert;
	/// <summary>
	/// The STRNV tables insert
	/// </summary>
	QString strTablesInsert;
	/// <summary>
	/// The STRNV tables select
	/// </summary>
	QString strTablesSelect;
	/// <summary>
	/// The STRNV profiles select
	/// </summary>
	QString strProfilesSelect;
	/// <summary>
	/// The string nv schedules select
	/// </summary>
	QString strSchedulesSelect;
	/// <summary>
	/// The string ODBC attributes
	/// </summary>
	QString strOdbcAttributes;
	/// <summary>
	/// The string nv log file
	/// </summary>
	QString strNvLogFile;
	/// <summary>
	/// The maximum replication threads used by the profile.
	/// </summary>
	int     iMaxReplicationThreads;

	/// <summary>
	/// Determines whether the specified settng has setting.
	/// </summary>
	/// <param name="settng">Performs a lookup in the configuration file to determine if the setting exists.</param>
	/// <returns>bool.</returns>
	bool    hasSetting(const QString setting);
   
	/// <summary>
	/// Initializes the setting.
	/// </summary>
	/// <param name="settng">The setting key.</param>
	/// <param name="settngValue">The setting value.</param>
	/// <param name="mVariable">The class property to be updated.</param>
	void    initSetting(const QString setting, const QString settingValue, RcAttributes mVariable);


};

#endif // CONNECTIONSTRINGBUILDER_H
