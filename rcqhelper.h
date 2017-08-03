// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="rcqhelper.h" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#ifndef RCQHELPER_H
#define RCQHELPER_H

#include <QMainWindow>
#include "ui_rcqhelper.h"
#include <QtCore>
#include <QtGui>
#include <QSqlTableModel>
#include <QUuid>
#include "helperdelegate.hpp"
#include <QSqlDatabase>
#include "../NvLibQ/qnvtables.h"
#include "../NvLibQ/qnvprofiles.h"
#include "qsql_odbc.h"
#include "sqlucode.h"

class qNvTables;
class qNvProfiles;

/// <summary>
/// Class RcQHelper.
/// </summary>
/// <seealso cref="QMainWindow" />
class RcQHelper : public QMainWindow
{

    Q_OBJECT

public:
	RcQHelper(QWidget *parent = 0);
	/// <summary>
	/// Destructor for an instance of the <see cref="RcQHelper"/> class.
	/// </summary>
	~RcQHelper();

	/// <summary>
	/// Initializes the specified profile name.
	/// </summary>
	/// <param name="profileName">Name of the profile.</param>
	void initialize(const QString profileName);

private slots:
	void on_pushButton_clicked();
	/// <summary>
	/// Ons the push button ok clicked.
	/// </summary>
	void on_pushButton_ok_clicked();

	/// <summary>
	/// Ons the list view profiles current changed.
	/// </summary>
	/// <param name="current">The current.</param>
	/// <param name="previous">The previous.</param>
	void on_listView_Profiles_currentChanged(const QModelIndex & current, const QModelIndex & previous);
	/// <summary>
	/// Ons the ListView profiles cell clicked.
	/// </summary>
	/// <param name="index">The index.</param>
	void onListView_ProfilesCellClicked(const QModelIndex &index);
	
	/// <summary>
	/// Ons the push button cancelled clicked.
	/// </summary>
	void on_pushButton_cancelled_clicked();

	/// <summary>
	/// Ons the push button configure profiles clicked.
	/// </summary>
	void on_pushButton_configureProfiles_clicked();

	/// <summary>
	/// Ons the push button add profile clicked.
	/// </summary>
	void on_pushButton_AddProfile_clicked();

	/// <summary>
	/// Ons the list view profiles double clicked.
	/// </summary>
	/// <param name="index">The index.</param>
	void on_listView_Profiles_doubleClicked(const QModelIndex &index);
	/// <summary>
	/// Ons the push button load profiles clicked.
	/// </summary>
	void on_pushButton_loadProfiles_clicked();

	/// <summary>
	/// Ons the list widget double clicked.
	/// </summary>
	/// <param name="index">The index.</param>
	void on_listWidget_doubleClicked(const QModelIndex &index);

	/// <summary>
	/// Ons the list widget tables double clicked.
	/// </summary>
	/// <param name="index">The index.</param>
	void on_listWidget_tables_doubleClicked(const QModelIndex &index);

private:

	/// <summary>
	/// Prepares the table.
	/// </summary>
	/// <param name="connectionStringRdb">The connection string RDB.</param>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="profileName">Name of the profile.</param>
	void prepareTable(const QString connectionStringRdb, const QString tableName, const QString profileName);
	/// <summary>
	/// Loads the nv tables.
	/// </summary>
	/// <param name="connectionStringRdb">The connection string RDB.</param>
	/// <param name="profileName">Name of the profile.</param>
	void LoadNvTables(const QString connectionStringRdb, const QString profileName);
	/// <summary>
	/// Inserts the nv table.
	/// </summary>
	/// <param name="profileName">Name of the profile.</param>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="fetchSQL">The fetch SQL.</param>
	/// <param name="insertSQL">The insert SQL.</param>
	/// <param name="updateSQL">The update SQL.</param>
	/// <param name="fieldCnt">The field count.</param>
	void insertNvTable(const QString profileName, const QString tableName, const QString fetchSQL, const QString insertSQL, const QString updateSQL, int fieldCnt);
	/// <summary>
	/// The UI
	/// </summary>
	Ui::RcQHelperClass ui;

	/// <summary>
	/// The model
	/// </summary>
	QSqlQueryModel	*model;
	/// <summary>
	/// The m UUID
	/// </summary>
	QUuid m_uuid;
	/// <summary>
	/// The mydelegate
	/// </summary>
	helperDelegate  *mydelegate;
	/// <summary>
	/// The table list
	/// </summary>
	QStringList		tableList;
	/// <summary>
	/// The crud list
	/// </summary>
	QStringList		CrudList;

	/// <summary>
	/// Gets the safe field.
	/// </summary>
	/// <param name="fField">The f field.</param>
	/// <returns>QString</returns>
	QString getSafeField(QString fField);
	/// <summary>
	/// The DSN connection string
	/// </summary>
	QString dsnConnectionString;
	/// <summary>
	/// The profile name
	/// </summary>
	QString profileName;
	/// <summary>
	/// Refreshes the profile list.
	/// </summary>
	void	refreshProfileList();
};

#endif // RCQHELPER_H
