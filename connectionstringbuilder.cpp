
#include "connectionstringbuilder.h"
#include "qsettings.h"
#include <QDebug>
#include <QFile>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QDir>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QUuid>
#include "LogHeader.h"


/// <summary>
/// The settings default QMRC Initialization File.
/// </summary>
const QString settingsIni("C://envy//QMRC_settings.ini");

connectionStringBuilder::connectionStringBuilder(QObject *parent) : QObject(parent)
{
	//DRIVER=SQL Server;SERVER=INTREPID;UID=sa;PWD=system99;APP=Replicator Console;WSID=SCG1S006;DATABASE=EnvyRep06
    connectionStringBaseRdb = QString("DRIVER={Oracle RDB Driver};SERVER=10.1.4.40@generic@179152311@W;SERVER=10.1.4.40;UID=peer;PWD=timothye;TLO=0;SVR=10.1.4.40;CLS=generic;DATABASE=attach 'filename nv$disk:[envy.300]mandb';XPT=2=tcp/ip;CSO=1;");
//	connectionStringBaseRdb = QString("DRIVER={Oracle RDB Driver};SERVER=%1@generic@179144119@W;SERVER=%1;UID=%3;PWD=%4;TLO=O;DBA=W;SVR=%1;CLS=generic;DATABASE=attach %2;XPT=2=tcp/ip;CSO=1;MSE=0;DCG=;DSH=;PRT=;");
    connectionStringBaseSql = QString("DRIVER=SQL Server;UID=envymgr;PWD=dexter99;APP=Replicator Console ;WSID=SCG1S006;DATABASE=mandb300;");
    connectionStringBaseEnvy = QString("DRIVER=SQL Server;SERVER=%1;UID=%3;PWD=%4;APP=QMRC Console;WSID=ENVYRCQ;DATABASE=%2");


	iMaxReplicationThreads = 1;
	setEnvyCredentials();
    this->settingsLoaded = false;




}
/// <summary>
/// Destructor for an instance of the <see cref="connectionStringBuilder" /> class.
/// </summary>
connectionStringBuilder::~connectionStringBuilder()
{


}
/// <summary>
/// Gets the connection string source.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::getConnectionStringSource() {

    QString tmp(connectionStringBaseRdb);
    tmp.arg("<serverNameIp>").arg("Attach 'filename nv$disk:[envy.<nnn>]<xxx>db").arg("<Credential.UserName>").arg("<Credential.Password>");
    return tmp;

 }
/// <summary>
/// Gets the connection string target.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::getConnectionStringTarget() {

    QString tmp(connectionStringBaseSql);
    tmp.arg("<serverNameIp>").arg("<Database>").arg("<Credential.UserName>").arg("<Credential.Password>");
    return tmp;
}
/// <summary>
/// Sets the RDB credentials.
/// </summary>
/// <param name="hostName">Name of the host.</param>
/// <param name="databaseName">Name of the database.</param>
/// <param name="uid">The uid.</param>
/// <param name="pwd">The password.</param>
/// Rdb Database 'filename nv$disk:[envy.XXX]YYYdb';
void connectionStringBuilder::setRdbCredentials(QString hostName, QString databaseName, QString uid, QString pwd)
{
	QString tmpString(QString(connectionStringBaseRdb).arg(hostName).arg(databaseName).arg(uid).arg(pwd));
    connectionStringBaseRdb = tmpString;
}
/// <summary>
/// Sets the SQL credentials.
/// </summary>
/// <param name="hostName">Name of the host.</param>
/// <param name="databaseName">Name of the database.</param>
/// <param name="uid">The uid.</param>
/// <param name="pwd">The password.</param>
void connectionStringBuilder::setSqlCredentials(QString hostName, QString databaseName, QString uid, QString pwd)
{
	QString tmpString(QString(connectionStringBaseSql).arg(hostName).arg(databaseName).arg(uid).arg(pwd));
   // tmpString = QString(connectionStringBaseSql).arg(hostName).arg(databaseName).arg(uid).arg(pwd);
	connectionStringBaseSql = tmpString;
}
/// <summary>
/// Sets the envy credentials.
/// </summary>
void connectionStringBuilder::setEnvyCredentials()
{
    if (!settingsLoaded) return;


	QFile  ffile(settingsIni);
	//if (!ffile.exists())
	

            initSetting ("envyRepositoryDSN","DRIVER=SQL Server;SERVER=tim-hp;UID=sa;PWD=12345678;APP=Replicator Console;WSID=ITPC0003;DATABASE=envyrep;Network=DBMSSOCN", RcAttributes::eNVyRepositoryDSN);
            initSetting ("OdbcAttributes","SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3,SQL_ATTR_PACKET_SIZE=4096,SQL_ATTR_CONNECTION_POOLING=0,SQL_ATTR_LOGIN_TIMEOUT=0,SQL_ATTR_CONNECTION_TIMEOUT=0,SQL_ATTR_TRACE=0", RcAttributes::OdbcAttributes);
            initSetting ("MaxReplicationThreads","1", RcAttributes::MaxReplicationThreads);
            initSetting ("NVProfilesCreate","CREATE TABLE [dbo].[NVProfiles]( [ProfileName] [varchar](24),[ProfileDescription] [varchar](255) [ProfileEnabled] [int],[ProfileAutoCommitEnabled] [int],[ProfileTraceEnabled] [int],[ProfileSourceDSN] [varchar](4096),[ProfileTargetDSN] [varchar](4096),[ExecutionThreads] [int],[ScheduleIntervalEnabled] [int],[CommitThrottle] [int],[EnableAutoReset] [int],[NVLogFile] [varchar](1024),[TransactionLogging] [int],[TransactionLogLevel] [int],[ProfileTrgDropOption] [int],[ProfileCommitInterval] [int],[ProfileNetworkPacketSize] [int]) ON [PRIMARY]", RcAttributes::NvProfilesCreate);
            initSetting ("NvTablesCreate","CREATE TABLE [dbo].[NVTables]([ProfileName] [varchar](24),[TableName] [varchar](50),[Status] [int], [PreferredSelectSQL] [varchar](4096),[PreferredInsertSQL] [varchar](4096),[PreferredUpdateSQL] [varchar](4096),[FieldCnt] [smallint],[fetchSql] [varchar] 2048),[insertSql] [varchar](2048),[updateSql] [varchar](2048)) ON [PRIMARY]", RcAttributes::NvTablesCreate);
            initSetting ("NvSchedulesCreate","CREATE TABLE [dbo].[NVSchedules]([ProfileName] [varchar](24),[ScheduledDate] [varchar](8),[ScheduledTime] [varchar](5),[bSelected] [int],[OperationType] [int] ) ON [PRIMARY]", RcAttributes::NvSchedulesCreate);
            initSetting ("NvProfilesInsert","INSERT INTO [dbo].[NVProfiles] ([ProfileName],[ProfileDescription],[ProfileEnabled],ProfileAutoCommitEnabled],[ProfileTraceEnabled] ,[ProfileSourceDSN] ,[ProfileTargetDSN] ,[ExecutionThreads] ,[ScheduleIntervalEnabled] ,[CommitThrottle] ,[EnableAutoReset] ,[NVLogFile] ,[TransactionLogging] ,[TransactionLogLevel] ,[ProfileTrgDropOption] ,[ProfileCommitInterval] ,ProfileNetworkPacketSize]) VALUES ('%1','%2',%3,%4,%5,'%6','%7',%8,%9,%10,%11,%12,%13,%14,%15,%16,%17)", RcAttributes::NvProfilesInsert);
            initSetting ("NvTablesInsert","INSERT INTO [dbo].[NVTables] ([ProfileName],[TableName],[Status],[PreferredSelectSQL] ,[PreferredInsertSQL] ,[PreferredUpdateSQL] ,[FieldCnt] ,[fetchSql] ,[insertSql] ,[updateSql])  VALUES  ('%1','%2',%3,'%4','%5','%6',%7,'%8','%9','%10')", RcAttributes::NvTablesInsert);
            initSetting ("NvApplicationLogFile",	 QDir(QCoreApplication::applicationDirPath()).filePath("qMRCApp.log"), RcAttributes::NvApplicationLogFile);

            initSetting ("nvProfilesSelect","SELECT [ProfileName],[ProfileDescription],[ProfileEnabled],[ProfileAutoCommitEnabled],[ProfileTraceEnabled],[ProfileSourceDSN],[ProfileTargetDSN],[ExecutionThreads],[ScheduleIntervalEnabled],[CommitThrottle],[EnableAutoReset],[NVLogFile],[TransactionLogging],[TransactionLogLevel],[ProfileTrgDropOption],[ProfileCommitInterval],[ProfileNetworkPacketSize] FROM [dbo].[NVProfiles]", RcAttributes::NvProfilesSelect);
            initSetting ("NvTablesSelect","SELECT [ProfileName],[TableName],[Status],[PreferredSelectSQL],[PreferredInsertSQL],[PreferredUpdateSQL],[FieldCnt],[fetchSql],[insertSql],[updateSql] FROM [dbo].[NVTables]", RcAttributes::NvTablesSelect);
            initSetting ("NvSchedulesSelect","SELECT [ProfileName],[ScheduledDate],[ScheduledTime] ,[bSelected],[OperationType]   FROM [dbo].NVSchedules]", RcAttributes::NvSchedulesSelect);

	
}
/// <summary>
/// Gets the RDB connection string.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::getRdbConnectionString()
{
    return    connectionStringBaseRdb;
}
/// <summary>
/// Gets the RDB connection string double quote.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::getRdbConnectionString_dblQuote()
{
	QString tmpString(connectionStringBaseRdb);
	tmpString.replace("'fi","''fi");
	tmpString.replace("';X","'';X");
	return    tmpString;
}
/// <summary>
/// Gets the SQL connection string.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::getSqlConnectionString()
{
	   return    connectionStringBaseSql;
}
/// <summary>
/// Gets the envy connection string.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::getEnvyConnectionString()
{
	setEnvyCredentials();
	return    connectionStringBaseEnvy;
}
/// <summary>
/// Clears this instance.
/// </summary>
void connectionStringBuilder::clear()
{
	connectionStringBaseEnvy.clear();
	connectionStringBaseRdb.clear();
	connectionStringBaseSql.clear();
}
void connectionStringBuilder::parseEnvyConfigStatement(const QString str)
{
	QFile file(str);
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QStringList lst;
	//in.readLine();
	while (!in.atEnd())
	{
		QString line = in.readAll();   
		QRegExp rx("(\")");
		lst = line.split(rx);
	}
	file.close();
	bool nextItem = false;
	/// <summary>
	/// Foreaches the specified item.
	/// </summary>
	/// <param name="item">The item.</param>
	/// <param name="">The .</param>
	/// <returns>int.</returns>
	foreach(QString item, lst)
	{
		if (nextItem)
		{
			this->connectionStringBaseEnvy = item;
			nextItem = false;
		}
		if (item.contains("connectionString=")) nextItem=true;
    }
}
/// <summary>
/// Creates the envy RCQ.
/// </summary>
/// <returns>QString</returns>
QString connectionStringBuilder::createEnvyRcq()
{
    QString errorText;

    QUuid uuid = QUuid::createUuid();
    {
        QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));

        QString tmp(builder->getEnvyConnectionString());
        QString tmpAttribute(builder->getOdbcAttributes ());

        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", uuid.toString());
        db.setDatabaseName(builder->getEnvyConnectionString ());
        db.setConnectOptions(builder->getOdbcAttributes());
        db.database(uuid.toString(), false);

        db.open();
        if (!db.isOpen())
        {
            errorText = QString("Database Not Opened: %1").arg(builder->getEnvyConnectionString ());
			
            return errorText;
        }

        QScopedPointer<QSqlQuery> qry(new QSqlQuery(db));
        qry->exec(this->strProfilesCreate);
        if (qry->lastError ().text ().length ()> 3) errorText.append (QString("%1\n").arg(qry->lastError ().text ()));
        qry->exec(this->strTablesCreate);
        if (qry->lastError ().text ().length ()> 3) errorText.append (QString("%1\n").arg(qry->lastError ().text ()));
        qry->exec(this->strSchedulesCreate);
        if (qry->lastError ().text ().length ()> 3) errorText.append (QString("%1\n").arg(qry->lastError ().text ()));
        qry->finish();
        db.close();
        return errorText.trimmed ();
    }
    QSqlDatabase::removeDatabase(uuid.toString());
}

/// <summary>
/// Determines whether the specified settng has setting.
/// </summary>
/// <param name="settng">The settng.</param>
/// <returns>bool.</returns>
bool connectionStringBuilder::hasSetting(const QString settng)
{
    QSettings settings(settingsIni,QSettings::IniFormat);
    QString settingX = settings.value (settng).toString ();
    if (settingX.isEmpty ()) return false;
    return true;
}

/// <summary>
/// Initializes the setting.
/// </summary>
/// <param name="settng">The settng.</param>
/// <param name="settngValue">The settng value.</param>
/// <param name="mVariable">The m variable.</param>
void connectionStringBuilder::initSetting(const QString settng, const QString settngValue, RcAttributes mVariable)
{
	QSettings settings(settingsIni, QSettings::IniFormat);
	QString savedSetting;
	if (!hasSetting (settng))
	{
		settings.setValue(settng, settngValue); // write the setting as it is missing in the ini file.
	}
	savedSetting = settings.value(settng).toString();
	switch (mVariable)
	{
	case connectionStringBuilder::eNVyRepositoryDSN:
		this->connectionStringBaseEnvy = savedSetting;
		break;
	case connectionStringBuilder::MaxReplicationThreads:
		this->iMaxReplicationThreads = QString(savedSetting).toInt();
		break;
	case connectionStringBuilder::NvProfilesCreate:
		this->strProfilesCreate = savedSetting;
		break;
	case connectionStringBuilder::NvTablesCreate:
		this->strTablesCreate = savedSetting;
		break;
	case connectionStringBuilder::NvSchedulesCreate:
		this->strSchedulesCreate = savedSetting;
		break;
	case connectionStringBuilder::OdbcAttributes:
		this->strOdbcAttributes = savedSetting;
		break;
	case connectionStringBuilder::NvProfilesInsert:
		this->strProfilesInsert = savedSetting;
		break;
	case connectionStringBuilder::NvTablesInsert:
		this->strTablesInsert = savedSetting;
		break;
	case connectionStringBuilder::NvApplicationLogFile:
		this->strNvLogFile = savedSetting;
		break;
	case connectionStringBuilder::NvProfilesSelect:
		this->strProfilesSelect = savedSetting;
		break;
	case connectionStringBuilder::NvTablesSelect:
		this->strTablesSelect = savedSetting;
		break;
	case connectionStringBuilder::NvSchedulesSelect:
		this->strSchedulesSelect = savedSetting;
		break;
	default:
		break;
	}

}



