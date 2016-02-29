/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Feb 7 16:17:32 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "basicopenglview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Model;
    QAction *actionRemove_Selected;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    BasicOpenGLView *oglwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(770, 608);
        MainWindow->setMaximumSize(QSize(770, 16777215));
        actionAdd_Model = new QAction(MainWindow);
        actionAdd_Model->setObjectName(QString::fromUtf8("actionAdd_Model"));
        actionRemove_Selected = new QAction(MainWindow);
        actionRemove_Selected->setObjectName(QString::fromUtf8("actionRemove_Selected"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        oglwidget = new BasicOpenGLView(centralWidget);
        oglwidget->setObjectName(QString::fromUtf8("oglwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(oglwidget->sizePolicy().hasHeightForWidth());
        oglwidget->setSizePolicy(sizePolicy);
        oglwidget->setMinimumSize(QSize(500, 300));

        horizontalLayout->addWidget(oglwidget);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(230, 0));
        groupBox->setMaximumSize(QSize(230, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(200, 300));
        listWidget->setMaximumSize(QSize(200, 16777215));
        listWidget->setAlternatingRowColors(true);
        listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        listWidget->setSelectionRectVisible(true);

        verticalLayout->addWidget(listWidget);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        addButton = new QPushButton(groupBox);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        removeButton = new QPushButton(groupBox);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout->addWidget(removeButton);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 770, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionAdd_Model);
        menuEdit->addAction(actionRemove_Selected);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAdd_Model->setText(QApplication::translate("MainWindow", "Add Model...", 0, QApplication::UnicodeUTF8));
        actionRemove_Selected->setText(QApplication::translate("MainWindow", "Remove Selected", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Models", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("MainWindow", "Add...", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
