#pragma once
#ifndef MODELNVSCHEDULESPRIVATE_HPP
#define MODELNVSCHEDULESPRIVATE_HPP
#include <QObject>
#include <QtCore>
#include <QtSql>
#include <QString>
#include "qclsregister.h"
#include "nvschedulesclass.h"
#include "qclogobject.h"
#include <QSqlTableModel>

class modelNvSchedulesPrivate  {
	Q_DISABLE_COPY(modelNvSchedulesPrivate)

public:
	modelNvSchedulesPrivate();
	~modelNvSchedulesPrivate();

	void		beginTransaction();
	bool		commit() {
		if (m_pTableModel) return m_pTableModel->submitAll();
		return false;
	}
	bool		createTable(const QString createTableSQL);
	void		deleteRow(nvSchedulesClass *clsObj);
	void		endTransaction();
	void		fetch();
	QString		getTableName()
	{
		return m_pTableModel->tableName();
	}

	void		initialize(const QString dsn, const QString tableName);
	void		initialize(const QString tableName);
	void		insertRow(nvSchedulesClass *clsObj);

	void		refresh();
	void		setCommitSubmitToUpdate() {

		if (m_pTableModel)
			m_pTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

	}
	void		setCommitRowAutomatically() {
		if (m_pTableModel)
			m_pTableModel->setEditStrategy(QSqlTableModel::OnRowChange);
	}
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
	void		update(nvSchedulesClass *clsObj);


protected:


private:

	QPointer<qClsRegister>			cls;
	//modelNvProfiles	* const			q_ptr;
	QPointer<QSqlTableModel>		m_pTableModel;
	QPointer<qCLogObject>			m_Log;

	QSqlDatabase			db;
	QUuid					m_uid;
	QString					m_StrConnect;
	QString					m_strFilter;
	int						m_rowCursor;

	void					close();
	
};

#endif // MODELNVSCHEDULESPRIVATE_HPP