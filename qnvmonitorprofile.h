#pragma once
#ifndef NVMONITORPROFILE_HPP
#define NVMONITORPROFILE_HPP
#include <QObject>
#include <QtCore>
#include "qNvRepository.h"
//#include <QScopedPointer>
#include "nvmonitorclass.h"

class qnvMonitorProfile : public qNvRepository {
	Q_OBJECT

public:
	qnvMonitorProfile(QObject * parent = Q_NULLPTR);
	~qnvMonitorProfile();

    //void initialize(const QString dsnConnectionString);
	bool update(nvMonitorClass cls);
	bool insert(nvMonitorClass cls);



private:
	
};

#endif // NVMONITORPROFILE_HPP
