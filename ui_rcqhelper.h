/********************************************************************************
** Form generated from reading UI file 'rcqhelper.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCQHELPER_H
#define UI_RCQHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RcQHelperClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QWidget *Tables;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget_tables;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancelled;
    QPushButton *pushButton_configureProfiles;
    QPushButton *pushButton_AddProfile;
    QPushButton *pushButton_loadProfiles;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RcQHelperClass)
    {
        if (RcQHelperClass->objectName().isEmpty())
            RcQHelperClass->setObjectName(QStringLiteral("RcQHelperClass"));
        RcQHelperClass->resize(420, 893);
        centralWidget = new QWidget(RcQHelperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        Tables = new QWidget();
        Tables->setObjectName(QStringLiteral("Tables"));
        gridLayout_3 = new QGridLayout(Tables);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        listWidget_tables = new QListWidget(Tables);
        listWidget_tables->setObjectName(QStringLiteral("listWidget_tables"));

        gridLayout_3->addWidget(listWidget_tables, 0, 0, 1, 1);

        tabWidget->addTab(Tables, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_ok = new QPushButton(centralWidget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        verticalLayout->addWidget(pushButton_ok);

        pushButton_cancelled = new QPushButton(centralWidget);
        pushButton_cancelled->setObjectName(QStringLiteral("pushButton_cancelled"));

        verticalLayout->addWidget(pushButton_cancelled);

        pushButton_configureProfiles = new QPushButton(centralWidget);
        pushButton_configureProfiles->setObjectName(QStringLiteral("pushButton_configureProfiles"));

        verticalLayout->addWidget(pushButton_configureProfiles);

        pushButton_AddProfile = new QPushButton(centralWidget);
        pushButton_AddProfile->setObjectName(QStringLiteral("pushButton_AddProfile"));

        verticalLayout->addWidget(pushButton_AddProfile);

        pushButton_loadProfiles = new QPushButton(centralWidget);
        pushButton_loadProfiles->setObjectName(QStringLiteral("pushButton_loadProfiles"));

        verticalLayout->addWidget(pushButton_loadProfiles);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        RcQHelperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RcQHelperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 420, 21));
        RcQHelperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RcQHelperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RcQHelperClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RcQHelperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RcQHelperClass->setStatusBar(statusBar);

        retranslateUi(RcQHelperClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RcQHelperClass);
    } // setupUi

    void retranslateUi(QMainWindow *RcQHelperClass)
    {
        RcQHelperClass->setWindowTitle(QApplication::translate("RcQHelperClass", "Profile Helper", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RcQHelperClass", "Profiles ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Tables), QApplication::translate("RcQHelperClass", "Tables", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("RcQHelperClass", "Ok", Q_NULLPTR));
        pushButton_cancelled->setText(QApplication::translate("RcQHelperClass", "Cancel", Q_NULLPTR));
        pushButton_configureProfiles->setText(QApplication::translate("RcQHelperClass", "Convert Profiles", Q_NULLPTR));
        pushButton_AddProfile->setText(QApplication::translate("RcQHelperClass", "Add", Q_NULLPTR));
        pushButton_loadProfiles->setText(QApplication::translate("RcQHelperClass", "Load", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RcQHelperClass: public Ui_RcQHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCQHELPER_H
