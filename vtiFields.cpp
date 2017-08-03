#include "vtifields.h"
#include <QRegExp>

vtiFields::vtiFields(QObject *parent) : QObject(parent)
{

}

vtiFields::~vtiFields()
{

}

/// <summary>
/// Gets the type of the variant.
/// </summary>
/// <param name="str">The string.</param>
/// <returns>QString</returns>

QString vtiFields::getVariantType(QString str)
{
    QRegExp rx0(str.trimmed());
    QRegExp rx1("(\\d+)");
    //int pos = 0;
    rx0.setPatternSyntax(QRegExp::Wildcard);
    // check if character
    if (
        (str.contains("SQL$")) &&
        (str.contains("CHR")))
    {
		QStringList myVal = str.split('$');
		if (myVal.size() == 2)
		{
			QString mySize = myVal.at(1);
			mySize.replace("CHR", "");
			return QString("varchar(%1)").arg(mySize);
		}
        return "varchar";
    }
    if (rx0.exactMatch("SQL$INT"))
    {
        return "int";
    }
    if (rx0.exactMatch("SQL$FLT"))
    {
        return "double precision";
    }
    if (rx0.exactMatch("SQL$SML"))
    {
        return "int";
    }
    if (rx0.exactMatch("SQL$TSP2"))
    {
        return "datetime";
    }
    return "varchar";
}
