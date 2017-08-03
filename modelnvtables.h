#pragma once
#ifndef MODELNVTABLES_HPP
#define MODELNVTABLES_HPP
#include <QObject>
#include <QtCore>
#include "modelNvTablesPrivate.h"
#include "nvtablesclass.h"

class modelNvTablesPrivate;
class modelNvTables   {
	Q_DECLARE_PRIVATE(modelNvTables)
	modelNvTablesPrivate *d_ptr;
public:
	modelNvTables();
	~modelNvTables();

	void	commit();
	void initialize();
	

	// custom Insert

	void InsertRow(nvTablesClass * cls);
	// custom Delete

	void deleteRow(nvTablesClass * cls);

	// custom Update
	void updateRow(nvTablesClass * cls);

	QList<nvTablesClass*>  fetch()
	{
		Q_D(modelNvTables);
		return d->fetch_current(d->m_profileName);
	}

	void	setProfileName(const QString profileName);



};

#endif // MODELNVTABLES_HPP