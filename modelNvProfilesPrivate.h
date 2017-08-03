#pragma once
#ifndef modelNvRepostoryTableBase_HPP
#define modelNvRepostoryTableBase_HPP
#include <QObject>
#include <QtCore>
#include <QtSql>
#include "connectionstringbuilder.h"
#include "nvprofilesclass.h"
#include "qclogobject.h"
#include <QSqlDatabase>



class modelNvProfilesPrivate  {

	Q_DISABLE_COPY(modelNvProfilesPrivate)
	

public:
	modelNvProfilesPrivate();
	~modelNvProfilesPrivate();



	void		beginTransaction();
	bool		commit() {
		if (m_pTableModel) return 	m_pTableModel->submitAll();
		return false;
	}
	bool		createTable(const QString createTableSQL);
	void		deleteRow(nvProfilesClass *clsObj);
	void		endTransaction();
	void		fetch();
	QString		getTableName() 
	{
		return m_pTableModel->tableName(); 
	}

	nvProfilesClass* fetch_current(const QString profileName);

	void		initialize(const QString dsn, const QString tableName);
	void		initialize(const QString tableName);
	void		insertRow(nvProfilesClass *clsObj);

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
	void		update(nvProfilesClass *clsObj);
	void		setEditOnly(bool isEditOnlyRow) { bIsEditOnly = isEditOnlyRow; }
	
	
protected:



private:

    //connectionStringBuilder			*cls;
	//modelNvProfiles	* const			q_ptr;
	QPointer<QSqlTableModel>		m_pTableModel;
	QPointer<qCLogObject>			m_Log;

	
	QUuid					m_uid;
	QString					m_StrConnect;
	QString					m_strFilter;
	int						m_rowCursor;
	QString					m_lpszProfileName;
    QString                 m_strEnvyDSN;
	
	void					close();
	bool					bIsEditOnly;
};

#endif // MODELNVPROFILES_HPP
