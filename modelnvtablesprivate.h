#pragma once
#ifndef MODELNVTABLESPRIVATE_HPP
#define MODELNVTABLESPRIVATE_HPP
#include <QObject>
#include <QObject>
#include <QtCore>
#include <QtSql>
#include "qclsregister.h"
#include "nvTablesClass.h"
#include "qclogobject.h"

class modelNvTablesPrivate  {

	Q_DISABLE_COPY(modelNvTablesPrivate)

public:
	modelNvTablesPrivate();
	~modelNvTablesPrivate();

	void		beginTransaction();
// 	bool		commit() {
// 		if (m_pTableModel) return m_pTableModel->submitAll();
// 		return false;
// 	}
	bool		createTable(const QString createTableSQL);
	void		deleteRow(nvTablesClass *clsObj);
	void		endTransaction();
	void		fetch();

	QList<nvTablesClass*> fetch_current(const QString profileName);
	QString		getTableName()
	{
		return m_strTableName;
	}

	void		initialize(const QString dsn, const QString tableName);
	void		initialize(const QString tableName);
	void		insertRow(nvTablesClass *clsObj);

	void		refresh();
//	void		setCommitSubmitToUpdate() {

// 		if (m_pTableModel)
// 			m_pTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
// 
// 	}
// 	void		setCommitRowAutomatically() {
// 		if (m_pTableModel)
// 			m_pTableModel->setEditStrategy(QSqlTableModel::OnRowChange);
// 	}
	//************************************
	// Method:    setFilter
	// FullName:  qVtExecuteModel::setFilter
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const QString filter
	// Note: The filter is a SQL WHERE clause without the keyword WHERE (for example, name='Josephine')
	//************************************
	void		setFilter(const QString filter) { m_strFilter = filter; }
	void		update(nvTablesClass *clsObj);
	QString		m_profileName;
protected:


private:

	//modelNvProfiles	* const			q_ptr;
	//QPointer<QSqlTableModel>		m_pTableModel;
	QPointer<qCLogObject>			m_Log;

	QString					m_strTableName;
	QString					m_StrConnect;
	QString					m_strFilter;
	int						m_rowCursor;

	void					close();

};

#endif // MODELNVTABLESPRIVATE_HPP