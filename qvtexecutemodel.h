#pragma once
#ifndef QVTEXECUTEMODEL_HPP
#define QVTEXECUTEMODEL_HPP
#include <QObject>
#include <QPointer>
#include <QtSql>
#include <QtCore>
#include <QUuid>
#include <QDebug>


#include "qclsregister.h"

class qVtExecuteModel : public QObject {
	Q_OBJECT
		


public:
	qVtExecuteModel(QObject * parent = Q_NULLPTR);
	~qVtExecuteModel();

	void initialize(const QString dsn, const QString tableName);
	void setCommitSubmitToUpdate() {

		if (m_pTableModel)
			m_pTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

	}
	void setCommitRowAutomatically() {
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
	void setFilter(const QString filter) { m_strFilter = filter; }
	void refresh() { 
		if (m_pTableModel) 
			m_pTableModel->select();
	}
	bool commit() {
		if (m_pTableModel)
            return m_pTableModel->submitAll();
	}
protected:
	QSqlTableModel			*m_pTableModel;

private:
	QPointer<qClsRegister>	cls;
	QSqlDatabase			db;
	QUuid					m_uid;
	QString					m_strTableName;
	QString					m_StrConnect;
	QString					m_strFilter;
	bool					m_bManualUpdates;


	
	
	void					close();

};

#endif // QVTEXECUTEMODEL_HPP
