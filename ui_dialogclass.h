/********************************************************************************
** Form generated from reading UI file 'dialogclass.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCLASS_H
#define UI_DIALOGCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogClass
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogClass)
    {
        if (DialogClass->objectName().isEmpty())
            DialogClass->setObjectName(QStringLiteral("DialogClass"));
        DialogClass->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogClass);
    } // setupUi

    void retranslateUi(QDialog *DialogClass)
    {
        DialogClass->setWindowTitle(QApplication::translate("DialogClass", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogClass: public Ui_DialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCLASS_H
