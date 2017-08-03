#pragma once
#ifndef QCLSREGISTER_HPP
#define QCLSREGISTER_HPP
#include <QObject>
#include <QString>
#include <QSettings>
#include <QPointer>

class qClsRegister : public QObject {
	Q_OBJECT

public:
	qClsRegister(QObject * parent = Q_NULLPTR);
	~qClsRegister();

	bool		InitMySet(void);
	QString		GetErrorText(void);
	QString		GetErrorCode(void);
	
	void		setLogFileName(QString lpszFilename);
	QString		getLogFileName();
	int			GetOrdinal();
	void		SetOrdinal(int uOrdinal);
	/*void		SetEnabled(bool  isEnabled);*/
	//QString		GetCDatabaseDSN();
	bool		InitializeTables();
	//bool		IsEmpty();

	QString		GetRepositoryDSN();
	void		SetRepositoryDSN(const QString strValue);

	bool  getIsOpen(void)
	{
		return m_bIsOpen;
	}

protected:
	void writeProfileString(const QString group, const QString key, const QString value);
	void writeProfileInt(const QString group, const QString key, const int value);
	QString getProfileString(const QString group, const QString key);
	int getProfileInt(const QString group, const QString key);


private:
	bool 		m_bLogFileOpened;
	QString	m_LogFileName;
	int		m_DBMSOrdinal;
	QString	m_CDatabaseRepositoryDSN;

	//HKEY     m_HTopKey;
	QString  m_KeyRoot;
	QString	m_Section;
	bool 		m_GotDSN;
	QString	m_RepositoryNode;
	QString	m_RepositoryDSN;
	QString m_ErrorCode;
	QString m_ErrorText;
	bool  m_bIsOpen;
	QPointer<QSettings> settings;
	
};

#endif // QCLSREGISTER_HPP