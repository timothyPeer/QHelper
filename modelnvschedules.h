#pragma once
#ifndef MODELNVSCHEDULES_HPP
#define MODELNVSCHEDULES_HPP
#include <QObject>
#include <QtCore>
#include <QScopedPointer>

#include "modelnvschedulesprivate.h"
#include "nvSchedulesClass.h"

class modelnvschedulesPrivate;
class modelNvSchedules  {

	Q_DECLARE_PRIVATE(modelNvSchedules)
	modelNvSchedulesPrivate *d_ptr;

public:
			modelNvSchedules();
			~modelNvSchedules();
	
	void	commit();
	void	initialize();

	// custom Insert

	void	InsertRow(nvSchedulesClass * cls);
	// custom Delete

	void	deleteRow(nvSchedulesClass * cls);

	// custom Update
	void	updateRow(nvSchedulesClass * cls);

};

#endif // MODELNVSCHEDULES_HPP