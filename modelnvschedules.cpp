#include "modelnvschedulesprivate.h"
#include "modelnvschedules.h"
#include "nvschedulesclass.h"
#include <Qtcore>


modelNvSchedules::modelNvSchedules()  {
	d_ptr = new modelNvSchedulesPrivate();
}

modelNvSchedules::~modelNvSchedules() {
	//if (d_ptr) delete d_ptr;
}

void modelNvSchedules::commit()
{
	Q_D(modelNvSchedules);
	d->commit();
}

void modelNvSchedules::initialize()
{
	Q_D(modelNvSchedules);
	d->initialize("nvschedules"); // use the default DSN from the Registry
}

void modelNvSchedules::InsertRow(nvSchedulesClass * cls)
{
	Q_D(modelNvSchedules);
	d->insertRow(cls);
}

void modelNvSchedules::deleteRow(nvSchedulesClass * cls)
{
	Q_D(modelNvSchedules);
	d->deleteRow(cls);
}

void modelNvSchedules::updateRow(nvSchedulesClass * cls)
{
	Q_D(modelNvSchedules);
	d->update(cls);
}