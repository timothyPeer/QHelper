#ifndef QLSREGISTER_H
#define QLSREGISTER_H

#include <QObject>
#include <QString>

class qlsRegister : public QObject
{
    Q_OBJECT
public:
    explicit qlsRegister(QObject *parent = 0);
        ~qlsRegister();
    bool initMySet();
    QString getErrorText() { return m_ErrorText; }
    QString getErrorCode() { return m_errorCode; }
    void setTempStringValue(QString key, QString value);
    QString getTempStringValue(QString key, QString defaultValue= "");
    void setLogfileName(QString file_Name);
    QString getLogFileName() { return m_LogFileName; }
    int getOrdinal() { return m_DBMSOrdinal; }
    void setOrdinal(int ordinalValue);
    QString getCDatabaseDSN() { return m_CDatabaseRepositoryDSN; }
    bool gotDSN() { return  m_gotDSN; }
    QString getRepositoryDSN() { return m_repositoryDSN; }
    void setRepositoryDSN(QString strValue);




signals:

public slots:
private:

    bool m_bLogFileOpened;
    QString m_LogFileName;
    int m_DBMSOrdinal;
    QString m_CDatabaseRepositoryDSN;
    QString m_KeyRoot;
    QString m_section;
    bool m_gotDSN;
    QString m_repositoryNode;
    QString m_repositoryDSN;
    QString m_errorCode;
    QString m_ErrorText;
    bool m_isOpen;
    int qProfileMachineID;
    int qProfileAutoCommitEnabled;
    int qProfileNetworkPacketSize;
};

#endif // QLSREGISTER_H
