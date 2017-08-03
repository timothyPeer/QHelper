#pragma once

#ifndef qRCEnumDef_h__
#define qRCEnumDef_h__

#include <QtCore/qglobal.h>

class enumerateClass
{
public:
	~enumerateClass() { instance = nullptr; }

	static enumerateClass* Get() 
	{
		if (instance == nullptr)
			instance = new enumerateClass;
		return instance;
	}
private:
	static enumerateClass* instance;
public:
// 	static const int COLNAMESIZE = 256;
// 	static const int MAX_CONNECT_LEN = 2048;
// 	static const int MAX_FNAME_LEN = 256;
// 	static const int READY = 0;
// 	static const int WAITING = 1;
// 	static const int INPROCESS = 2;
// 	static const int COMPLETE = 3;
// 	static const int ABORTING = -9;
	enum Location
	{
		BeforeFirstRow = -1,
		AfterLastRow = -2
	};

	enum ParamTypeFlag
	{
		In = 0x00000001,
		Out = 0x00000002,
		InOut = 0x00000003,
		Binary = 0x00000004
	};
	Q_DECLARE_FLAGS(ParamType, ParamTypeFlag)

		enum TableType
	{
		Tables = 0x01,
		SystemTables = 0x02,
		Views = 0x04,
		AllTables = 0xff
	};

	enum NumericalPrecisionPolicy
	{
		LowPrecisionInt32 = 0x01,
		LowPrecisionInt64 = 0x02,
		LowPrecisionDouble = 0x04,

		HighPrecision = 0
	};

	 enum nvTableStatusFlags
	{
		READY = 0, WAITING = 1, INPROCESS = 2, COMPLETE = 3, ABORTING = -9
	};
	enum validRCOperations						// Valid Operations
	{
		UNASSIGNED = -9,
		COPY_TABLE = 1,
		REPLICATE_TABLE = 2,
		BULK_COPY = 3
	};

	enum monitorStatus
	{
		Started,
		Running,
		Stopped,
		Aborted
	};
	/// <summary>
	/// The RDB
	/// </summary>
	enum DBMSType { UnknownDB, MSSqlServer, MySqlServer, PostgreSQL, Oracle, Sybase, SQLite, Interbase, DB2, RDB };

	/// <summary>
	/// The target
	/// </summary>
	enum ConnectionSource { Source, Target };
	/// <summary>
	/// The fatal level
	/// </summary>
	enum LoggerLevel {
		/// <summary>
		/// The none
		/// </summary>
		None = 0,
		/// <summary>
		/// The trace level
		/// </summary>
		TraceLevel = 1,
		/// <summary>
		/// The debug level
		/// </summary>
		DebugLevel,
		/// <summary>
		/// The information level
		/// </summary>
		InfoLevel,
		/// <summary>
		/// The warn level
		/// </summary>
		WarnLevel,
		/// <summary>
		/// The error level
		/// </summary>
		ErrorLevel,
		/// <summary>
		/// The fatal level
		/// </summary>
		FatalLevel
	};



	/// <summary>
	/// Enum TransferOperations
	/// </summary>
	enum TransferOperations
	{
		/// <summary>
		/// The start update
		/// </summary>
		START_UPDATE = 0,
		/// <summary>
		/// The end update
		/// </summary>
		END_UPDATE = 1
	};
};


	

#endif // qRCEnumDef_h__
