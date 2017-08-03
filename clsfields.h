#ifndef CLSTABLEFIELDS_H
#define CLSTABLEFIELDS_H

#include <QObject>
#include <QString>

class clsFields :
{

public:
     clsFields();
    ~clsFields();
    void setFieldName(QString field_Name) {  fieldName = field_Name; }
    void setField(QString field_Name, QString field_Type) { fieldName = field_Name; fieldType = field_Type; }
    void setFieldType(QString field_Type) { fieldType = field_Type; }
    QString getFieldName() {return fieldName; }
    QString getFieldType() { return fieldType; }

signals:

public slots:
private:


    QString fieldName;
    QString fieldType;
};

#endif // CLSTABLEFIELDS_H
