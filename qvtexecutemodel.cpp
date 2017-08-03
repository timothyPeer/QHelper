#include "qvtexecutemodel.h"
#include "qclsregister.h"
#include <QScopedPointer>
#include "connectionstringbuilder.h"

qVtExecuteModel::qVtExecuteModel(QObject * parent) : QObject(parent) {
    //cls = new qClsRegister(this);
    QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
	m_uid = QUuid::createUuid();
	db = QSqlDatabase::addDatabase("QODBC", m_uid.toString());
	db.setConnectOptions(builder->getOdbcAttributes());
	db.database(m_uid.toString(), false);

	// Pointer

    //cls = new qClsRegister(this);
	m_pTableModel = new QSqlTableModel(this);

}

/// <summary>
/// Destructor for an instance of the <see cref="qVtExecuteModel"/> class.
/// </summary>
qVtExecuteModel::~qVtExecuteModel() {
	
    //if (cls) delete cls;
	close();
	QSqlDatabase::removeDatabase(m_uid.toString());
}

/// <summary>
/// Initializes the specified DSN.
/// </summary>
/// <param name="dsn">The DSN.</param>
/// <param name="tableName">Name of the table.</param>
void qVtExecuteModel::initialize(const QString dsn, const QString tableName)
{
	m_StrConnect = dsn;
	this->m_strTableName = tableName; // QString("select * from ").arg(tableName);
	db.open();
	
	m_pTableModel->setTable(tableName);
	m_pTableModel->select();
}



/// <summary>
/// Closes this instance.
/// </summary>
void qVtExecuteModel::close()
{
	db.close();
}

