#include "qclogobject.h"




qCLogObject::qCLogObject(QObject * parent) : QObject(parent) {
	
	
}

qCLogObject::~qCLogObject() {
	
	//if (m_Database) delete m_Database;
}






void qCLogObject::log(enumerateClass::LoggerLevel level, const QString format, ...)
{

}

const QString qCLogObject::getTimeString()
{
	return QString();
}

const QString qCLogObject::getAttributeString()
{
	return QString();
}

const QString qCLogObject::formatLogString()
{
	return QString();
}

const QString qCLogObject::formatHtmlString()
{
	return QString();
}

bool qCLogObject::logToDebug()
{
	return false;
}

bool qCLogObject::logToFile()
{
	return false;
}

bool qCLogObject::logToConsole()
{
	return false;
}

bool qCLogObject::logToDatabase()
{
	return false;
}

bool qCLogObject::logToEventLog()
{
	return false;
}

bool qCLogObject::logToHtml()
{
	return false;
}

QString qCLogObject::getDSNName()
{
	return QString();
}

QString qCLogObject::getDBTableName()
{
	return QString();
}

QString qCLogObject::getFileName()
{
	return QString();
}

int qCLogObject::getLevel()
{
	return 0;
}

int qCLogObject::getFileOpenFlags()
{
	return 0;
}

bool qCLogObject::logToTarget(int uTarget)
{

	return false;
}



bool qCLogObject::hasAttribute(const QString lpszAttrName)
{
	return false;
}

bool qCLogObject::setAttribute(const QString lpszAttrName, const QString lpszAttrValue, bool bAutoCreate)
{
	return false;
}

QString qCLogObject::getAttributeValue(const QString lpszAttrName)
{
	return QString();
}

void qCLogObject::copyAttributes(qCLogObject & obj)
{
}

void qCLogObject::copyTargets(qCLogObject & obj)
{
}

void qCLogObject::copyAllSettings(qCLogObject & obj)
{
}

void qCLogObject::setFile(const QString lpszFilename, bool bAppend)
{
}
