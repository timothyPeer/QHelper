#pragma once
#ifndef MODELNVPROFILES_HPP
#define MODELNVPROFILES_HPP

#include <QObject>
#include <QtCore>
#include "modelNvProfilesPrivate.h"
#include "nvprofilesclass.h"

class modelNvProfilesPrivate;
class modelNvProfiles  {
	
	Q_DECLARE_PRIVATE(modelNvProfiles)   // assumes that the PIMPL pointer is named d_ptr
	modelNvProfilesPrivate		*d_ptr;

public:
			modelNvProfiles();
			~modelNvProfiles();

		//modelNvProfiles( const modelNvProfiles &obj);
		// custom Insert
		void	InsertRow(nvProfilesClass * cls);
		// custom Delete
		void	deleteRow(nvProfilesClass * cls);
		void	updateRow(nvProfilesClass * cls);
		void	setEditOnly();
	nvProfilesClass* fetch(const QString profileName)
	{
		Q_D(modelNvProfiles);
		nvProfilesClass *clsObj= d->fetch_current(profileName);
		return clsObj;
	}

protected:
	void	commit();

	void	initialize();
};

#endif // MODELNVPROFILES_HPP