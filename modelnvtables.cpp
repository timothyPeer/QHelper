

#include "modelnvtables.h"
#include "modelnvtablesprivate.h"
#include "nvtablesclass.h"

modelNvTables::modelNvTables() {

	d_ptr = new modelNvTablesPrivate();
}

modelNvTables::~modelNvTables() {
	if (d_ptr != nullptr) delete d_ptr;
}

void modelNvTables::commit()
{
	//Q_D(modelNvTables);
	//d->commit();
}

void modelNvTables::initialize()
{
	Q_D(modelNvTables);
	d->initialize("nvtable"); // use the default DSN from the Registry
}



void modelNvTables::InsertRow(nvTablesClass * cls)
{
	Q_D(modelNvTables);
	d->insertRow(cls);
}

void modelNvTables::deleteRow(nvTablesClass * cls)
{
	Q_D(modelNvTables);
	d->deleteRow(cls);
}

void modelNvTables::updateRow(nvTablesClass * cls)
{
	Q_D(modelNvTables);
	d->update(cls);
}

void modelNvTables::setProfileName(const QString profileName)
{
	Q_D(modelNvTables);
	d->m_profileName = profileName;
}

