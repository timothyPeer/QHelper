#pragma once
#ifndef QNVSTATICCLASS_HPP
#define QNVSTATICCLASS_HPP

#if defined (Q_OS_WIN32)
#include <qt_windows.h>
#endif

#include <QtSql>
#include <QObject>
#include <QString>
#include "qsql_odbc.h"
#include <QException>
#include <QDebug>
#include <QVarLengthArray>
//#include "qODBCDriverPrivate.hpp"
//#include "qOdbcDriver.hpp"

class qnvStaticClass : public QObject {
	Q_OBJECT

public:
	qnvStaticClass(QObject * parent = Q_NULLPTR);
	~qnvStaticClass();

	const QString & getCreateTableNVT()
	{
		static const QString constant("Create Table nv_transfers (table_name <%^VARCHAR^%>(32), Status SMALLINT, last_attempted <%^TIMESTAMPMASK^%>,last_completed <%^TIMESTAMPMASK^%>, auto_updated smallint)");
		return constant;
	}
	const QString & getUpdateEndNVT()
	{
		static const QString constant("update nv_transfers set auto_updated = 1,Status = 1,last_completed = last_attempted where table_name = '<%^TABLENAME^%>'");
		return constant;
	}
	const QString & getUpdateStartNVT()
	{
		static const QString constant("update nv_transfers set auto_updated = 1,Status = 0,last_attempted =   TIMESTAMP '<%^LASTUPDATEDATEMASK^%>' where table_name = '<%^TABLENAME^%>' and Status = 1");
		return constant;
	}
	const QString & getInsertNVT()
	{
		static const QString constant("insert into nv_transfers(auto_updated, Status, last_attempted, table_name) values(1, 1, TIMESTAMP '<%^LASTUPDATEDATEMASK^%>', '<%^TABLENAME^%>')");
		return constant;
	}
	const QString & getNVCreateTables()
	{
		static const QString constant("CREATE TABLE NVTables(ProfileName <%^VARCHAR^%>(24), TableName <%^VARCHAR^%>(50), Status <%^INT^%>, PreferredSelectSQL  <%^VARCHAR^%>(255), PreferredInsertSQL  <%^VARCHAR^%>(255), PreferredUpdateSQL <%^VARCHAR^%>(255), EnablePreferredSelect smallint, EnablePreferredInsert smallint, EnablePreferredUpdate smallint, FieldCnt smallint, RowsProcessed numeric, AvgRowsSecond float)");
		return constant;
	}
	const QString & getNVCreateSchedule()
	{
		static const QString constant("CREATE TABLE NVSchedules (ProfileName <%^VARCHAR^%>(24), ScheduledDate <%^VARCHAR^%> (8),  ScheduledTime <%^VARCHAR^%> (5), bSelected <%^INT^%>, OperationType <%^INT^%>)");
		return constant;
	}
// 	const QString & getNVProfiles_Create()
// 	{
// 		static const QString constant("CREATE TABLE NVProfiles (ProfileName <%^VARCHAR^%>(24),ProfileDescription0 <%^VARCHAR^%>(255),ProfileDescription1 <%^VARCHAR^%>(255),ProfileEnabled <%^INT^%>,ProfileAutoCommitEnabled <%^INT^%>,ProfileTraceEnabled <%^INT^%>,ProfileSourceDSN0  <%^VARCHAR^%>(255),ProfileSourceDSN1  <%^VARCHAR^%>(255),ProfileSourceDSN2  <%^VARCHAR^%>(255),ProfileSourceDSN3  <%^VARCHAR^%>(255),ProfileTargetDSN0 <%^VARCHAR^%>(255),ProfileTargetDSN1 <%^VARCHAR^%>(255),ProfileTargetDSN2 <%^VARCHAR^%>(255),ProfileTargetDSN3 <%^VARCHAR^%>(255),ExecutionThreads <%^INT^%>,ExecutionStatus <%^INT^%>,ScheduleIntervalEnabled <%^INT^%>, CommitThrottle <%^INT^%>, EnableAutoReset <%^INT^%>,NVLogFile <%^VARCHAR^%>(255), TransactionLogging <%^INT^%>, TransactionLogLevel <%^INT^%>)");
// 		return constant;
// 	}

	const QString & getNVThreadsCreate()
	{
		static const QString constant("CREATE TABLE NVActiveThreads (ThreadHandle numeric(18, 0),ThreadStarted <%^VARCHAR^%> (8),ThreadStatus <%^INT^%>,ProfileName <%^VARCHAR^%> (24))");
		return constant;
	}

	const QString & getNVMonitorCreate()
	{
		static const QString constant("CREATE TABLE NVMonitor (ThreadID <%^INT^%>, ProfileName <%^VARCHAR^%>(24),NVTimestamp <%^VARCHAR^%>(32) ,	TableName <%^VARCHAR^%> (32),	StartTime <%^VARCHAR^%>(11),EndTime <%^VARCHAR^%>(11),	ElapsedTime <%^VARCHAR^%> (6)  ,	RowsProcessed numeric(18, 0)  ,	AveragePerSecond <%^INT^%>  ,	MonStat <%^INT^%> )");
		return constant;
	}

	const QString & getNVMyEnvyDSN()
	{
		static const QString constant("Replicator DSN");
		return constant;
	}
	const QString & getNVOrdinalType()
	{
		static const QString constant("Repository Ordinal Type");
		return constant;
	}

	const QString & getNVMyLog()
	{
		static const QString constant("Log File");
		return constant;
	}
	const QString & getEnvySelect()
	{
		static const QString constant("SELECT * FROM <%^TableName^%>");
		return constant;
	}
private:
};

inline static QString fromSQLTCHAR(const QVarLengthArray<SQLTCHAR>& input, int size = -1)
{
	QString result;

	int realsize = qMin(size, input.size());
	if (realsize > 0 && input[realsize - 1] == 0)
		realsize--;
	switch (sizeof(SQLTCHAR)) {
	case 1:
		result = QString::fromUtf8((const char *)input.constData(), realsize);
		break;
	case 2:
		result = QString::fromUtf16((const ushort *)input.constData(), realsize);
		break;
	case 4:
		result = QString::fromUcs4((const uint *)input.constData(), realsize);
		break;
	default:
		qCritical("sizeof(SQLTCHAR) is %d. Don't know how to handle this.", int(sizeof(SQLTCHAR)));
	}
	return result;
}

inline static QVarLengthArray<SQLTCHAR> toSQLTCHAR(const QString &input)
{
	QVarLengthArray<SQLTCHAR> result;
	result.resize(input.size());
	switch (sizeof(SQLTCHAR)) {
	case 1:
		memcpy(result.data(), input.toUtf8().data(), input.size());
		break;
	case 2:
		memcpy(result.data(), input.unicode(), input.size() * 2);
		break;
	case 4:
		memcpy(result.data(), input.toUcs4().data(), input.size() * 4);
		break;
	default:
		qCritical("sizeof(SQLTCHAR) is %d. Don't know how to handle this.", int(sizeof(SQLTCHAR)));
	}
	result.append(0); // make sure it's null terminated, doesn't matter if it already is, it does if it isn't.
	return result;
}
inline static void ShowError(QString FileName, int LineNum, QString szExtraMsg = NULL)
{
	TCHAR szErr[512];
	QString s;
	//e->(szErr, sizeof(szErr) - 1);
	QString qszErr = (LPSTR)szErr;
	if (!szExtraMsg.isEmpty())
		s = QString("[%1:%2] %3\n%4").arg(FileName).arg(LineNum).arg(qszErr).arg(szExtraMsg);
	else
		s = QString("[%s:%d] %s").arg(FileName).arg(LineNum).arg(qszErr);
}



static QString qWarnODBCHandle(int handleType, SQLHANDLE handle, int *nativeCode = 0)
{
	SQLINTEGER nativeCode_ = 0;
	SQLSMALLINT msgLen = 0;
	SQLRETURN r = SQL_NO_DATA;
	SQLTCHAR state_[SQL_SQLSTATE_SIZE + 1];
	QVarLengthArray<SQLTCHAR> description_(SQL_MAX_MESSAGE_LENGTH);
	QString result;
	int i = 1;

	description_[0] = 0;
	do {
		r = SQLGetDiagRec(handleType,
			handle,
			i,
			state_,
			&nativeCode_,
			0,
			0,
			&msgLen);
		if ((r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO) && msgLen > 0)
			description_.resize(msgLen + 1);
		r = SQLGetDiagRec(handleType,
			handle,
			i,
			state_,
			&nativeCode_,
			description_.data(),
			description_.size(),
			&msgLen);
		if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO) {
			if (nativeCode)
				*nativeCode = nativeCode_;
			QString tmpstore;
#ifdef UNICODE
			tmpstore = fromSQLTCHAR(description_, msgLen);
#else
			tmpstore = QString::fromUtf8((const char*)description_.constData(), msgLen);
#endif
			if (result != tmpstore) {
				if (!result.isEmpty())
					result += QLatin1Char(' ');
				result += tmpstore;
			}
		}
		else if (r == SQL_ERROR || r == SQL_INVALID_HANDLE) {
			return result;
		}
		++i;
	} while (r != SQL_NO_DATA);
	return result;
}

#endif // QNVSTATICCLASS_HPP