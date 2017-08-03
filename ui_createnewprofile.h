/********************************************************************************
** Form generated from reading UI file 'createnewprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWPROFILE_H
#define UI_CREATENEWPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewProfile
{
public:
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_10;
    QLabel *label_4;
    QLineEdit *lineEdit_copyProfileName;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QVBoxLayout *verticalLayout_9;
    QTextEdit *textEdit_Source;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *textEdit_Target;
    QWidget *Properties;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_6;
    QTextEdit *textEdit_description;
    QLineEdit *lineEdit_ProfileName;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QComboBox *comboBox_loggingLevel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_LogFilebrowse;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_3;
    QLineEdit *lineEdit_LogFileName;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_14;
    QCheckBox *checkBox_ProfileEnabled;
    QCheckBox *checkBox_AutoCommitEnabled;
    QCheckBox *checkBox_ProfileTraceEnabled;
    QCheckBox *checkBox_ProfileTransactionLogging;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_CommitThrottle;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QSpinBox *spinBox_ExecutionThreads;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox_dropTarget;
    QWidget *tabTables;
    QGridLayout *gridLayout_4;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_12;
    QPushButton *pushButton_profileCheck;
    QPushButton *pushButton_Generate;
    QPushButton *pushButton_Commit;
    QPushButton *pushButton_editProfile;
    QPushButton *pushButton_deleteProfile;
    QPushButton *pushButton_copyProfile;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_create;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listWidget_createStatements;
    QWidget *tab_insert;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget_insertStatements;
    QWidget *tab_update;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget_updateStatements;
    QWidget *tab_SqlStatement;
    QGridLayout *gridLayout_7;
    QListWidget *listWidget_SqlStatements;
    QTabWidget *tabWidget_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *textEdit_messages;

    void setupUi(QDialog *CreateNewProfile)
    {
        if (CreateNewProfile->objectName().isEmpty())
            CreateNewProfile->setObjectName(QStringLiteral("CreateNewProfile"));
        CreateNewProfile->resize(930, 697);
        gridLayout_11 = new QGridLayout(CreateNewProfile);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        label = new QLabel(CreateNewProfile);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        lineEdit = new QLineEdit(CreateNewProfile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_6->addWidget(lineEdit);


        verticalLayout_11->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_4 = new QLabel(CreateNewProfile);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(false);

        gridLayout_10->addWidget(label_4, 0, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_10);

        lineEdit_copyProfileName = new QLineEdit(CreateNewProfile);
        lineEdit_copyProfileName->setObjectName(QStringLiteral("lineEdit_copyProfileName"));
        lineEdit_copyProfileName->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit_copyProfileName);


        verticalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget_2 = new QTabWidget(CreateNewProfile);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_9 = new QVBoxLayout(tab);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        textEdit_Source = new QTextEdit(tab);
        textEdit_Source->setObjectName(QStringLiteral("textEdit_Source"));

        verticalLayout_9->addWidget(textEdit_Source);

        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_8 = new QVBoxLayout(tab_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        textEdit_Target = new QTextEdit(tab_2);
        textEdit_Target->setObjectName(QStringLiteral("textEdit_Target"));

        verticalLayout_8->addWidget(textEdit_Target);

        tabWidget_2->addTab(tab_2, QString());
        Properties = new QWidget();
        Properties->setObjectName(QStringLiteral("Properties"));
        horizontalLayout_7 = new QHBoxLayout(Properties);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox_7 = new QGroupBox(Properties);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_6 = new QGroupBox(groupBox_7);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        textEdit_description = new QTextEdit(groupBox_6);
        textEdit_description->setObjectName(QStringLiteral("textEdit_description"));
        textEdit_description->setGeometry(QRect(10, 23, 256, 192));

        gridLayout_6->addWidget(groupBox_6, 1, 0, 1, 1);

        lineEdit_ProfileName = new QLineEdit(groupBox_7);
        lineEdit_ProfileName->setObjectName(QStringLiteral("lineEdit_ProfileName"));
        lineEdit_ProfileName->setReadOnly(true);

        gridLayout_6->addWidget(lineEdit_ProfileName, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(groupBox_7);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_9 = new QGridLayout(groupBox_9);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_2 = new QLabel(groupBox_9);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_8->addWidget(label_2);

        comboBox_loggingLevel = new QComboBox(groupBox_9);
        comboBox_loggingLevel->setObjectName(QStringLiteral("comboBox_loggingLevel"));

        horizontalLayout_8->addWidget(comboBox_loggingLevel);


        gridLayout_9->addLayout(horizontalLayout_8, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_LogFilebrowse = new QPushButton(groupBox_9);
        pushButton_LogFilebrowse->setObjectName(QStringLiteral("pushButton_LogFilebrowse"));

        gridLayout_9->addWidget(pushButton_LogFilebrowse, 1, 1, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_3 = new QLabel(groupBox_9);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_16->addWidget(label_3);

        lineEdit_LogFileName = new QLineEdit(groupBox_9);
        lineEdit_LogFileName->setObjectName(QStringLiteral("lineEdit_LogFileName"));

        verticalLayout_16->addWidget(lineEdit_LogFileName);


        gridLayout_9->addLayout(verticalLayout_16, 2, 0, 1, 2);


        gridLayout_6->addWidget(groupBox_9, 2, 0, 1, 1);


        horizontalLayout_7->addWidget(groupBox_7);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        checkBox_ProfileEnabled = new QCheckBox(Properties);
        checkBox_ProfileEnabled->setObjectName(QStringLiteral("checkBox_ProfileEnabled"));
        checkBox_ProfileEnabled->setCheckable(true);
        checkBox_ProfileEnabled->setChecked(false);

        verticalLayout_14->addWidget(checkBox_ProfileEnabled);

        checkBox_AutoCommitEnabled = new QCheckBox(Properties);
        checkBox_AutoCommitEnabled->setObjectName(QStringLiteral("checkBox_AutoCommitEnabled"));
        checkBox_AutoCommitEnabled->setChecked(false);

        verticalLayout_14->addWidget(checkBox_AutoCommitEnabled);

        checkBox_ProfileTraceEnabled = new QCheckBox(Properties);
        checkBox_ProfileTraceEnabled->setObjectName(QStringLiteral("checkBox_ProfileTraceEnabled"));

        verticalLayout_14->addWidget(checkBox_ProfileTraceEnabled);

        checkBox_ProfileTransactionLogging = new QCheckBox(Properties);
        checkBox_ProfileTransactionLogging->setObjectName(QStringLiteral("checkBox_ProfileTransactionLogging"));
        checkBox_ProfileTransactionLogging->setChecked(false);

        verticalLayout_14->addWidget(checkBox_ProfileTransactionLogging);


        verticalLayout_15->addLayout(verticalLayout_14);

        groupBox_4 = new QGroupBox(Properties);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBox_CommitThrottle = new QSpinBox(groupBox_4);
        spinBox_CommitThrottle->setObjectName(QStringLiteral("spinBox_CommitThrottle"));
        spinBox_CommitThrottle->setMaximum(100000);
        spinBox_CommitThrottle->setValue(1000);

        gridLayout->addWidget(spinBox_CommitThrottle, 0, 0, 1, 1);


        verticalLayout_15->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(Properties);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        spinBox_ExecutionThreads = new QSpinBox(groupBox_5);
        spinBox_ExecutionThreads->setObjectName(QStringLiteral("spinBox_ExecutionThreads"));
        spinBox_ExecutionThreads->setValue(1);

        gridLayout_5->addWidget(spinBox_ExecutionThreads, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_5);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        comboBox_dropTarget = new QComboBox(groupBox_8);
        comboBox_dropTarget->setObjectName(QStringLiteral("comboBox_dropTarget"));

        gridLayout_8->addWidget(comboBox_dropTarget, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_8, 1, 0, 1, 1);


        verticalLayout_15->addWidget(groupBox_5);


        horizontalLayout_7->addLayout(verticalLayout_15);

        tabWidget_2->addTab(Properties, QString());
        tabTables = new QWidget();
        tabTables->setObjectName(QStringLiteral("tabTables"));
        gridLayout_4 = new QGridLayout(tabTables);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        listWidget = new QListWidget(tabTables);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_4->addWidget(listWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tabTables, QString());

        horizontalLayout->addWidget(tabWidget_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_11->addLayout(horizontalLayout_2);


        gridLayout_11->addLayout(verticalLayout_11, 0, 0, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        pushButton_profileCheck = new QPushButton(CreateNewProfile);
        pushButton_profileCheck->setObjectName(QStringLiteral("pushButton_profileCheck"));

        verticalLayout_12->addWidget(pushButton_profileCheck);

        pushButton_Generate = new QPushButton(CreateNewProfile);
        pushButton_Generate->setObjectName(QStringLiteral("pushButton_Generate"));

        verticalLayout_12->addWidget(pushButton_Generate);

        pushButton_Commit = new QPushButton(CreateNewProfile);
        pushButton_Commit->setObjectName(QStringLiteral("pushButton_Commit"));

        verticalLayout_12->addWidget(pushButton_Commit);

        pushButton_editProfile = new QPushButton(CreateNewProfile);
        pushButton_editProfile->setObjectName(QStringLiteral("pushButton_editProfile"));
        pushButton_editProfile->setEnabled(false);

        verticalLayout_12->addWidget(pushButton_editProfile);

        pushButton_deleteProfile = new QPushButton(CreateNewProfile);
        pushButton_deleteProfile->setObjectName(QStringLiteral("pushButton_deleteProfile"));
        pushButton_deleteProfile->setEnabled(false);

        verticalLayout_12->addWidget(pushButton_deleteProfile);

        pushButton_copyProfile = new QPushButton(CreateNewProfile);
        pushButton_copyProfile->setObjectName(QStringLiteral("pushButton_copyProfile"));
        pushButton_copyProfile->setEnabled(false);

        verticalLayout_12->addWidget(pushButton_copyProfile);

        groupBox = new QGroupBox(CreateNewProfile);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        verticalLayout_12->addWidget(groupBox);


        gridLayout_11->addLayout(verticalLayout_12, 0, 1, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        groupBox_2 = new QGroupBox(CreateNewProfile);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setLayoutDirection(Qt::RightToLeft);
        groupBox_2->setAlignment(Qt::AlignCenter);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        buttonBox = new QDialogButtonBox(groupBox_2);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        horizontalLayout_5->addWidget(groupBox_2);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_10->addLayout(verticalLayout_6);

        groupBox_3 = new QGroupBox(CreateNewProfile);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget = new QTabWidget(groupBox_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_create = new QWidget();
        tab_create->setObjectName(QStringLiteral("tab_create"));
        verticalLayout_5 = new QVBoxLayout(tab_create);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        listWidget_createStatements = new QListWidget(tab_create);
        listWidget_createStatements->setObjectName(QStringLiteral("listWidget_createStatements"));

        verticalLayout_5->addWidget(listWidget_createStatements);

        tabWidget->addTab(tab_create, QString());
        tab_insert = new QWidget();
        tab_insert->setObjectName(QStringLiteral("tab_insert"));
        gridLayout_2 = new QGridLayout(tab_insert);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listWidget_insertStatements = new QListWidget(tab_insert);
        listWidget_insertStatements->setObjectName(QStringLiteral("listWidget_insertStatements"));

        gridLayout_2->addWidget(listWidget_insertStatements, 0, 0, 1, 1);

        tabWidget->addTab(tab_insert, QString());
        tab_update = new QWidget();
        tab_update->setObjectName(QStringLiteral("tab_update"));
        gridLayout_3 = new QGridLayout(tab_update);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        listWidget_updateStatements = new QListWidget(tab_update);
        listWidget_updateStatements->setObjectName(QStringLiteral("listWidget_updateStatements"));

        gridLayout_3->addWidget(listWidget_updateStatements, 0, 0, 1, 1);

        tabWidget->addTab(tab_update, QString());
        tab_SqlStatement = new QWidget();
        tab_SqlStatement->setObjectName(QStringLiteral("tab_SqlStatement"));
        gridLayout_7 = new QGridLayout(tab_SqlStatement);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        listWidget_SqlStatements = new QListWidget(tab_SqlStatement);
        listWidget_SqlStatements->setObjectName(QStringLiteral("listWidget_SqlStatements"));

        gridLayout_7->addWidget(listWidget_SqlStatements, 0, 0, 1, 1);

        tabWidget->addTab(tab_SqlStatement, QString());

        verticalLayout_4->addWidget(tabWidget);


        verticalLayout_10->addWidget(groupBox_3);


        gridLayout_11->addLayout(verticalLayout_10, 0, 2, 1, 1);

        tabWidget_3 = new QTabWidget(CreateNewProfile);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        textEdit_messages = new QTextEdit(tab_3);
        textEdit_messages->setObjectName(QStringLiteral("textEdit_messages"));

        verticalLayout_7->addWidget(textEdit_messages);

        tabWidget_3->addTab(tab_3, QString());

        gridLayout_11->addWidget(tabWidget_3, 1, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
        label_4->setBuddy(lineEdit_copyProfileName);
#endif // QT_NO_SHORTCUT

        retranslateUi(CreateNewProfile);

        tabWidget_2->setCurrentIndex(2);
        tabWidget->setCurrentIndex(3);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CreateNewProfile);
    } // setupUi

    void retranslateUi(QDialog *CreateNewProfile)
    {
        CreateNewProfile->setWindowTitle(QApplication::translate("CreateNewProfile", "Create New Profile", Q_NULLPTR));
        label->setText(QApplication::translate("CreateNewProfile", "Profile Name:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CreateNewProfile", "Copy Profile Name:", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("CreateNewProfile", "Source", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("CreateNewProfile", "Target", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("CreateNewProfile", "Profile Name", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("CreateNewProfile", "Description", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("CreateNewProfile", "Logging", Q_NULLPTR));
        label_2->setText(QApplication::translate("CreateNewProfile", "Level:", Q_NULLPTR));
        pushButton_LogFilebrowse->setText(QApplication::translate("CreateNewProfile", "Browse", Q_NULLPTR));
        label_3->setText(QApplication::translate("CreateNewProfile", "FileName", Q_NULLPTR));
        checkBox_ProfileEnabled->setText(QApplication::translate("CreateNewProfile", "Enabled", Q_NULLPTR));
        checkBox_AutoCommitEnabled->setText(QApplication::translate("CreateNewProfile", "AutoCommit", Q_NULLPTR));
        checkBox_ProfileTraceEnabled->setText(QApplication::translate("CreateNewProfile", "Trace", Q_NULLPTR));
        checkBox_ProfileTransactionLogging->setText(QApplication::translate("CreateNewProfile", "Logging", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("CreateNewProfile", "Commit Throttle", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("CreateNewProfile", "Execution Threads", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("CreateNewProfile", "Drop Target", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Properties), QApplication::translate("CreateNewProfile", "Properties", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabTables), QApplication::translate("CreateNewProfile", "Tables", Q_NULLPTR));
        pushButton_profileCheck->setText(QApplication::translate("CreateNewProfile", "Check", Q_NULLPTR));
        pushButton_Generate->setText(QApplication::translate("CreateNewProfile", "Generate", Q_NULLPTR));
        pushButton_Commit->setText(QApplication::translate("CreateNewProfile", "Commit", Q_NULLPTR));
        pushButton_editProfile->setText(QApplication::translate("CreateNewProfile", "Edit", Q_NULLPTR));
        pushButton_deleteProfile->setText(QApplication::translate("CreateNewProfile", "Delete", Q_NULLPTR));
        pushButton_copyProfile->setText(QApplication::translate("CreateNewProfile", "Copy", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("CreateNewProfile", "Action", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("CreateNewProfile", "SQL Statements", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_create), QApplication::translate("CreateNewProfile", "Create Statement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_insert), QApplication::translate("CreateNewProfile", "Insert Statement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_update), QApplication::translate("CreateNewProfile", "Update Statement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_SqlStatement), QApplication::translate("CreateNewProfile", "Sql Statement", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_3), QApplication::translate("CreateNewProfile", "Messages", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateNewProfile: public Ui_CreateNewProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWPROFILE_H
