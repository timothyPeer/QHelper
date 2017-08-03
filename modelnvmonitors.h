#pragma once
#ifndef MODELNVMONITORS_HPP
#define MODELNVMONITORS_HPP
#include <QObject>
#include <QtCore>
#include "modelnvmonitorsprivate.h"
#include "nvmonitorclass.h"

class modelNvMonitorsPrivate;
/// <summary>
/// Class modelNvMonitors.
/// </summary>
class modelNvMonitors {

	Q_DECLARE_PRIVATE(modelNvMonitors)
		
		/// <summary>
		/// The d PTR
		/// </summary>
		modelNvMonitorsPrivate *d_ptr;

public:

	/// <summary>
	/// Initializes a new instance of the <see cref="modelNvMonitors" /> class.
	/// </summary>
	modelNvMonitors();

	/// <summary>
	/// Destructor for an instance of the <see cref="modelNvMonitors" /> class.
	/// </summary>
	~modelNvMonitors();



	/// <summary>
	/// Commits this instance.
	/// </summary>
	void	commit();

	/// <summary>
	/// Initializes this instance.
	/// </summary>
	void initialize();

	// custom Insert


/// <summary>
/// Inserts the row.
/// </summary>
/// <param name="cls">The CLS.</param>
	void InsertRow(nvMonitorClass * cls);
	// custom Delete


/// <summary>
/// Deletes the row.
/// </summary>
/// <param name="cls">The CLS.</param>
	void deleteRow(nvMonitorClass * cls);

	/// <summary>
	/// Updates the row.
	/// </summary>
	/// <param name="cls">The CLS.</param>
	void updateRow(nvMonitorClass * cls);
	
};

#endif // MODELNVMONITORS_HPP