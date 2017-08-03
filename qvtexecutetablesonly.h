#pragma once
#ifndef QVTEXECUTETABLESONLY_HPP
#define QVTEXECUTETABLESONLY_HPP
#include <QObject>
#include <QUuid>
#include <QThread>
#include <QFuture>
#include <QSqlDatabase>
#include <QStringList>

class qvtExecuteTablesOnly : public QObject {
	Q_OBJECT

public:
	qvtExecuteTablesOnly(QObject * parent = Q_NULLPTR);
	~qvtExecuteTablesOnly();
	void initialize(const QString &dataSource, const QString &sqlStatement, bool isSQL);
	QStringList tables;

private:
	QUuid m_uid;
	QSqlDatabase db;
	QString m_StrConnect;
	QString m_sqlStatement;
	bool isSQL;
	bool hasError() { return !errorText.trimmed().isEmpty(); }
	QString errorText;
	bool process();
	void close();

	public slots:

	void run();
	
};

#endif // QVTEXECUTETABLESONLY_HPP