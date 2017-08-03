#ifndef DBCHECKOBJ_H
#define DBCHECKOBJ_H

#include <QObject>
#include <QStringList>

class dbCheckObj : public QObject
{
    Q_OBJECT
public:
    explicit dbCheckObj(QObject *parent = nullptr);

    bool isValidConnection(  ) {return bIsValid; }
    void    initialize(const QString dsnConnectionString);
    QStringList     sqlTables();

signals:

public slots:

private:
    bool bIsValid;
    QStringList m_SqlTables;
    QString     m_DsnConnectionString;
};

#endif // DBCHECKOBJ_H
