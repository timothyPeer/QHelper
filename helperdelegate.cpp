#include "helperdelegate.hpp"
#include <QTextEdit>

helperDelegate::helperDelegate(QObject * parent) : QItemDelegate(parent) {
	
}

/// <summary>
/// Destructor for an instance of the <see cref="helperDelegate"/> class.
/// </summary>
helperDelegate::~helperDelegate() {
	
}

/// <summary>
/// Creates the editor.
/// </summary>
/// <param name="parent">The parent.</param>
/// <param name="option">The option.</param>
/// <param name="index">The index.</param>
/// <returns>QWidget *.</returns>
QWidget * helperDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QTextEdit *editor = new QTextEdit(parent);
	return editor;
}

/// <summary>
/// Sets the editor data.
/// </summary>
/// <param name="editor">The editor.</param>
/// <param name="index">The index.</param>
void helperDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QString value = index.model()->data(index, Qt::EditRole).toString();
	QTextEdit *editorX = static_cast<QTextEdit*>(editor);
	editorX->setPlainText(value);
}

/// <summary>
/// Sets the model data.
/// </summary>
/// <param name="editor">The editor.</param>
/// <param name="model">The model.</param>
/// <param name="index">The index.</param>
void helperDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QTextEdit *editorX = static_cast<QTextEdit*>(editor);
	QString value = editorX->toPlainText();
	model->setData(index, value, Qt::EditRole);
}



/// <summary>
/// Updates the editor geometry.
/// </summary>
/// <param name="editor">The editor.</param>
/// <param name="option">The option.</param>
/// <param name="index">The index.</param>
void helperDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}
