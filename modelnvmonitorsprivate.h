#pragma once
#ifndef MODELNVMONITORSPRIVATE_HPP
#define MODELNVMONITORSPRIVATE_HPP
#include <QObject>
#include <QtCore>
#include <QtSql>
#include "nvMonitorClass.h"
#include "modelnvmonitorsprivate.h"
#include "modelnvmonitors.h"
#include "connectionstringbuilder.h"
#include "qclogobject.h"

class modelNvMonitorsPrivate  {
	Q_DISABLE_COPY(modelNvMonitorsPrivate)

public:
	modelNvMonitorsPrivate();
	~modelNvMonitorsPrivate();

	void		beginTransaction();
	bool		commit() {
		if (m_pTableModel) return 	m_pTableModel->submitAll();
		return false;
	}
	bool		createTable(const QString createTableSQL);
	void		deleteRow(nvMonitorClass *clsObj);
	void		endTransaction();
	void		fetch();
	QString		getTableName()
	{
		return m_pTableModel->tableName();
	}

	void		initialize(const QString dsn, const QString tableName);
	void		initialize(const QString tableName);
	void		insertRow(nvMonitorClass *clsObj);

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
	void		update(nvMonitorClass *clsObj);


protected:


private:


	QPointer<QSqlTableModel>		m_pTableModel;
	QPointer<qCLogObject>			m_Log;

	QSqlDatabase			db;
	QUuid					m_uid;
	QString					m_StrConnect;
	QString					m_strFilter;
    QString                 m_strEnvyDSN;
    int						m_rowCursor;

	void					close();
	
};

#endif // MODELNVMONITORSPRIVATE_HPP
