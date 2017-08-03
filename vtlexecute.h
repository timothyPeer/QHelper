#ifndef VTLEXECUTE_H
#define VTLEXECUTE_H

#include <QObject>
#include <QtGlobal>
#include <QIcon>
#include <QMessageLogger>
#include <QFile>
#include <QCommandLineOption>
#include <QStringList>
#include <QRegExp>
#include <QSqlField>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QThreadPool>
#include <QFuture>
#include <QList>
#include <QScopedPointer>
#include <QUuid>

class vtlExecute : public QObject
{
    Q_OBJECT
public:
    explicit vtlExecute(QObject *parent = 0);

    void process();
    void initialize(const QString &dataSource, const QString &sqlStatement);
    void setBatch(const QStringList batch_List) { batchList = batch_List; isBatch = true;}
    void setSqlStatement(QString str) { m_sqlStatement = str; }
    void setScalarBool(bool isBool) { m_bSetScalarBool = isBool;}
    bool getScalarBoolResult() { return m_bScalarBoolResult; }
    void run();
    void setDefaultDSN();
    ~vtlExecute();
    bool executeScalarBool();
signals:

public slots:
private:
    QUuid m_uid ;
    QString m_StrConnect;
    QString m_sqlStatement;
    bool isBatch;
    QStringList batchList;
    void setDSNToDefault(QString str) {m_StrConnect = str; }
    bool m_bSetScalarBool;
    bool m_bScalarBoolResult;
};

#endif // VTLEXECUTE_H
