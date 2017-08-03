// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 05-23-2017
// ***********************************************************************
// <copyright file="modelnvmonitors.cpp" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include "modelnvmonitors.h"
#include "nvmonitorclass.h"
#include "modelnvmonitorsprivate.h"

modelNvMonitors::modelNvMonitors() {

	d_ptr = new modelNvMonitorsPrivate;
}

modelNvMonitors::~modelNvMonitors() {
	
}

void modelNvMonitors::commit()
{
	Q_D(modelNvMonitors);
	d->commit();
}

void modelNvMonitors::initialize()
{
	Q_D(modelNvMonitors);
	d->initialize("nvtable"); // use the default DSN from the Registry
}

void modelNvMonitors::InsertRow(nvMonitorClass * cls)
{
	Q_D(modelNvMonitors);
	d->insertRow(cls);
}

void modelNvMonitors::deleteRow(nvMonitorClass * cls)
{
	Q_D(modelNvMonitors);
	d->deleteRow(cls);
}

/// <summary>
/// Updates the row.
/// </summary>
/// <param name="cls">The CLS.</param>

void modelNvMonitors::updateRow(nvMonitorClass * cls)
{
	Q_D(modelNvMonitors);
	d->update(cls);
}