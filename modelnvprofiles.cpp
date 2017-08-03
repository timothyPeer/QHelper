#include "modelnvprofiles.h"
#include "modelNvProfilesPrivate.h"
#include "nvprofilesclass.h"

modelNvProfiles::modelNvProfiles() : d_ptr(new modelNvProfilesPrivate) {
	
}



modelNvProfiles::~modelNvProfiles() {
	
}

void modelNvProfiles::commit()
{
	Q_D(modelNvProfiles);
	d->commit();
}
void modelNvProfiles::setEditOnly()
{
	Q_D(modelNvProfiles);
	d->setEditOnly(true);
}

void modelNvProfiles::initialize()
{
	Q_D(modelNvProfiles);
	d->initialize("nvprofiles"); // use the default DSN from the Registry
}

void modelNvProfiles::InsertRow(nvProfilesClass * cls)
{
	Q_D(modelNvProfiles);
	d->insertRow(cls);
}

void modelNvProfiles::deleteRow(nvProfilesClass * cls)
{
	Q_D(modelNvProfiles);
	d->deleteRow(cls);
}

void modelNvProfiles::updateRow(nvProfilesClass * cls)
{
	Q_D(modelNvProfiles);
	d->update(cls);
}


