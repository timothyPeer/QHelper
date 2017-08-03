// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 03-30-2017
// ***********************************************************************
// <copyright file="helperdelegate.hpp" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#ifndef HELPERDELEGATE_HPP
#define HELPERDELEGATE_HPP
#include <QItemDelegate>
#include <QModelIndex>
#include <QSize>
#include <QObject>


/// <summary>
/// Class helperDelegate.
/// </summary>
/// <seealso cref="QItemDelegate" />
class helperDelegate : public QItemDelegate {
	Q_OBJECT

public:
	helperDelegate(QObject * parent = Q_NULLPTR);
	~helperDelegate();


	QWidget *	createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void		setEditorData(QWidget *editor, const QModelIndex &index) const;
	void		setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	 //QSize		sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	 void		updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;


private:
	
};

#endif // HELPERDELEGATE_HPP