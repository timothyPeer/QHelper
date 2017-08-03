/********************************************************************************
** Form generated from reading UI file 'selectedProfileDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTEDPROFILEDLG_H
#define UI_SELECTEDPROFILEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableViewProfile;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_rebuildSql;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_editProfile;
    QPushButton *pushButton_saveProfile;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(683, 404);
        verticalLayout_3 = new QVBoxLayout(Dialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableViewProfile = new QTableView(Dialog);
        tableViewProfile->setObjectName(QStringLiteral("tableViewProfile"));

        verticalLayout->addWidget(tableViewProfile);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_rebuildSql = new QPushButton(Dialog);
        pushButton_rebuildSql->setObjectName(QStringLiteral("pushButton_rebuildSql"));

        horizontalLayout_3->addWidget(pushButton_rebuildSql);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_editProfile = new QPushButton(groupBox);
        pushButton_editProfile->setObjectName(QStringLiteral("pushButton_editProfile"));

        horizontalLayout->addWidget(pushButton_editProfile);

        pushButton_saveProfile = new QPushButton(groupBox);
        pushButton_saveProfile->setObjectName(QStringLiteral("pushButton_saveProfile"));

        horizontalLayout->addWidget(pushButton_saveProfile);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(hboxLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Dialog", "Rebuild Preferred Statements: ", Q_NULLPTR));
        pushButton_rebuildSql->setText(QApplication::translate("Dialog", "Rebuild", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "GroupBox", Q_NULLPTR));
        pushButton_editProfile->setText(QApplication::translate("Dialog", "Edit", Q_NULLPTR));
        pushButton_saveProfile->setText(QApplication::translate("Dialog", "Save", Q_NULLPTR));
        okButton->setText(QApplication::translate("Dialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTEDPROFILEDLG_H
