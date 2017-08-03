#include "qlsregister.h"
#include <QSettings>
#include <QString>

qlsRegister::qlsRegister(QObject *parent) : QObject(parent)
{

}
qlsRegister::~qlsRegister()
{

}
void qlsRegister::setRepositoryDSN( QString strValue )
{
    QSettings settings("Replicator Console Q", "rcQ");

    QString tmpString;
    if (!settings.contains("EnvyDSN"))
    {
        settings.setValue("EnvyDSN","DRIVER=SQL Server;SERVER=10.1.4.23;UID=sa;PWD=password;APP=Replicator Console;WSID=SCG1S006;DATABASE=EnvyRCQ");
        settings.setValue("qProfileMachineID",0);
        settings.setValue("qProfileAutoCommitEnabled",1);
        settings.setValue("qProfileNetworkPacketSize",4096);
    }
    else
    {
        this->setRepositoryDSN(tmpString) ;
        this->qProfileMachineID = settings.value("qProfileMachineID").toInt();
        this->qProfileAutoCommitEnabled = settings.value("qProfileAutoCommitEnabled").toInt();
        this->qProfileNetworkPacketSize = settings.value("qProfileNetworkPacketSize").toInt();
    }



}
