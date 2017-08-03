#pragma once
#ifndef QVTEXECUTE_HPP
#define QVTEXECUTE_HPP
#include <QObject>
#include <QUuid>
#include <QThread>
#include <QFuture>
#include <QSqlDatabase>
#include <QSqlRecord>
#include "nvtablesclass.h"

class qVtExecute : public QObject {
	Q_OBJECT

public:
	qVtExecute(QObject * parent = Q_NULLPTR);
	~qVtExecute();
	void initialize(const QString &dataSource, const QString &tableName);
	void initialize(const QString &dataSource, const QString &sqlStatement, bool isSQL);
	bool ExecuteDirect(QString str) { m_sqlStatement = str;  return process(); }


	void close();
private:
	QUuid m_uid;
	QSqlDatabase db;
	QString m_StrConnect;
	QString m_sqlStatement;
	bool isSQL;
    bool hasError() {return  errorText.trimmed().isEmpty(); }
	QString errorText;
	bool process();



public slots:
	
	void run();
	
};

#endif // QVTEXECUTE_HPP
