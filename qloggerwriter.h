// ***********************************************************************
// Assembly         : 
// Author           : Francesc Martinez <es.linkedin.com/in/cescmm/en>
//
// Last Modified By : Tim Peer
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="qloggerwriter.h" company="eNVy Systems, Inc.">
//    Copyright (C) 2013  Francesc Martinez <es.linkedin.com/in/cescmm/en>
// </copyright>
// <summary>
//** This library is free software; you can redistribute it and / or
//** modify it under the terms of the GNU Lesser General Public
//** License as published by the Free Software Foundation; either
//** version 2.1 of the License, or (at your option) any later version.
//**
//** This library is distributed in the hope that it will be useful,
//** but WITHOUT ANY WARRANTY; without even the implied warranty of
//** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU
//** Lesser General Public License for more details.
//**
//** You should have received a copy of the GNU Lesser General Public
//** License along with this library; if not, write to the Free Software
//** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110 - 1301  USA
//</summary>
// ***********************************************************************
#ifndef QLOGGERWRITER_H
#define QLOGGERWRITER_H



/****************************************************************************************
 ** QLogger is a library to register and print logs into a file.
 ** Copyright (C) 2013  Francesc Martinez <es.linkedin.com/in/cescmm/en>
 **
 ** This library is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public
 ** License as published by the Free Software Foundation; either
 ** version 2.1 of the License, or (at your option) any later version.
 **
 ** This library is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public
 ** License along with this library; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 ***************************************************************************************/

#include <QStringList>
#include <QObject>
#include <QMap>
#include <QThread>
#include <QMutex>

/**************************************************************************************************/
/***                                     GENERAL USAGE                                          ***/
/***                                                                                            ***/
/***  1. Create an instance: QLoggerManager *manager = QLoggerManager::getInstance();           ***/
/***  2. Add a destination:  manager->addDestination(filePathName, module, logLevel);           ***/
/***  3. Print the log in the file with: QLog_<Trace/Debug/Info/Warning/Error/Fatal>            ***/
/***                                                                                            ***/
/***  You can add as much destinations as you want. You also can add several modules for each   ***/
/***  log file.                                                                                 ***/
/**************************************************************************************************/

/// <summary>
/// The QLogger namespace.
/// </summary>
namespace QLogger
{

    /**
     * @brief The LogLevel enum defines the level of the log message.
     */
	 /// <summary>
	 /// Enum LogLevel
	 /// </summary>
	enum LogLevel {
		/// <summary>
		/// No Logging - Disabled
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

    /**
     * @brief Here is done the call to write the message in the module. First of all is confirmed
     * that the log level we want to write is less or equal to the level defined when we create the
     * destination.
     *
     * @param module The module that the message references.
     * @param level The level of the message.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="level">The level.</param>
	 /// <param name="message">The message.</param>
	void QLog_(const QString &module, LogLevel level, const QString &message);
    /**
     * @brief Used to store Trace level messages.
     * @param module The module that the message references.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log trace.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="message">The message.</param>
	void QLog_Trace(const QString &module, const QString &message);
    /**
     * @brief Used to store Debug level messages.
     * @param module The module that the message references.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log debug.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="message">The message.</param>
	void QLog_Debug(const QString &module, const QString &message);
    /**
     * @brief Used to store Info level messages.
     * @param module The module that the message references.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log information.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="message">The message.</param>
	void QLog_Info(const QString &module, const QString &message);
    /**
     * @brief Used to store Warning level messages.
     * @param module The module that the message references.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log warning.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="message">The message.</param>
	void QLog_Warning(const QString &module, const QString &message);
    /**
     * @brief Used to store Error level messages.
     * @param module The module that the message references.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log error.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="message">The message.</param>
	void QLog_Error(const QString &module, const QString &message);
    /**
     * @brief Used to store Fatal level messages.
     * @param module The module that the message references.
     * @param message The message.
     */
	 /// <summary>
	 /// qs the log fatal.
	 /// </summary>
	 /// <param name="module">The module.</param>
	 /// <param name="message">The message.</param>
	void QLog_Fatal(const QString &module, const QString &message);

    /**
     * @brief The QLoggerWriter class writes the message and manages the file where it is printed.
     */
	 /// <summary>
	 /// Class QLoggerWriter.
	 /// </summary>
	 /// <seealso cref="QObject" />
	class QLoggerWriter : public QObject
    {
        Q_OBJECT

        public:
            /**
             * @brief Constructor that gets the complete path and filename to create the file. It also
             * configures the level of this file to filter the logs depending on the level.
             * @param fileDestination The complete path.
             * @param level The maximum level that is allowed.
             */
            explicit QLoggerWriter(const QString &fileDestination, LogLevel level);
            /**
             * @brief Gets the current maximum level.
             * @return The LogLevel.
             */
			 /// <summary>
			 /// Gets the level.
			 /// </summary>
			 /// <returns>QLogger.LogLevel.</returns>
			LogLevel getLevel() const { return m_level; }
            /**
             * @brief Within this method the message is written in the log file. If it would exceed
             * from 1 MByte, another file will be created and the log message will be stored in the
             * new one. The older file will be renamed with the date and time of this message to know
             * where it is updated.
             *
             * @param module The module that corresponds to the message.
             * @param message The message log.
             */
			 /// <summary>
			 /// Writes the specified module.
			 /// </summary>
			 /// <param name="module">The module.</param>
			 /// <param name="message">The message.</param>
			void write(const QString &module, const QString &message);

        private:
            /**
             * @brief Path and name of the file that will store the logs.
             */
			 /// <summary>
			 /// The m file destination
			 /// </summary>
			QString m_fileDestination;
            /**
             * @brief Maximum log level allowed for the file.
             */
			 /// <summary>
			 /// The m level
			 /// </summary>
			LogLevel m_level;
    };

    /**
     * @brief The QLoggerManager class manages the different destination files that we would like to have.
     */
	 /// <summary>
	 /// Class QLoggerManager.
	 /// </summary>
	 /// <seealso cref="QThread" />
	class QLoggerManager : public QThread
    {
        public:
            /**
             * @brief Gets an instance to the QLoggerManager.
             * @return A pointer to the instance.
             */
			 /// <summary>
			 /// Gets the instance.
			 /// </summary>
			 /// <returns>QLogger.QLoggerManager *.</returns>
			static QLoggerManager * getInstance();
            /**
             * @brief Converts the given level in a QString.
             * @param level The log level in LogLevel format.
             * @return The string with the name of the log level.
             */
			 /// <summary>
			 /// Levels to text.
			 /// </summary>
			 /// <param name="level">The level.</param>
			 /// <returns>QString.</returns>
			static QString levelToText(const LogLevel &level);
            /**
             * @brief This method creates a QLoggerWriter that stores the name of the file and the log
             * level assigned to it. Here is added to the map the different modules assigned to each
             * log file. The method returns <em>false</em> if a module is configured to be stored in
             * more than one file.
             *
             * @param fileDest The file name and path to print logs.
             * @param modules The modules that will be stored in the file.
             * @param level The maximum level allowed.
             * @return Returns true if any error have been done.
             *
             */
			 /// <summary>
			 /// Adds the destination.
			 /// </summary>
			 /// <param name="fileDest">The file dest.</param>
			 /// <param name="module">The module.</param>
			 /// <param name="level">The level.</param>
			 /// <returns>bool.</returns>
			bool addDestination(const QString &fileDest, const QString &module, LogLevel level);
			/// <summary>
			/// Adds the destination.
			/// </summary>
			/// <param name="fileDest">The file dest.</param>
			/// <param name="modules">The modules.</param>
			/// <param name="level">The level.</param>
			/// <returns>bool.</returns>
			bool addDestination(const QString &fileDest, const QStringList &modules, LogLevel level);
            /**
             * @brief Gets the QLoggerWriter instance corresponding to the module <em>module</em>.
             * @param module The module we look for.
             * @return Returns a pointer to the object.
             */

			 /// <summary>
			 /// Removes all destination.
			 /// </summary>
			void removeAllDestination();

			/// <summary>
			/// Gets the log writer.
			/// </summary>
			/// <param name="module">The module.</param>
			/// <returns>QLogger.QLoggerWriter *.</returns>
			QLoggerWriter * getLogWriter(const QString &module) { return moduleDest.value(module); }
            /**
             * @brief This method closes the logger and the thread it represents.
             */
			 /// <summary>
			 /// Closes the logger.
			 /// </summary>
			void closeLogger();
            /**
             * @brief Mutex to make the method thread-safe.
             */
			 /// <summary>
			 /// The mutex
			 /// </summary>
			QMutex mutex;

        private:
            /**
             * @brief Instance of the class.
             */
            static QLoggerManager *INSTANCE;
            /**
             * @brief Map that stores the module and the file it is assigned.
             */
			 /// <summary>
			 /// The module dest
			 /// </summary>
			QMap<QString, QLoggerWriter*> moduleDest;
            /**
             * @brief Default builder of the class. It starts the thread.
             */
			 /// <summary>
			 /// Prevents a default instance of the <see cref="QLoggerManager"/> class from being created.
			 /// </summary>
			QLoggerManager();


    };
}
#endif // QLOGGERWRITER_H



