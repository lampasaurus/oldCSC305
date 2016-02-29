/********************************************************************************
** Form generated from reading UI file 'toolbar.ui'
**
** Created: Thu Feb 7 16:17:32 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBAR_H
#define UI_TOOLBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_toolbar
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;

    void setupUi(QDialog *toolbar)
    {
        if (toolbar->objectName().isEmpty())
            toolbar->setObjectName(QString::fromUtf8("toolbar"));
        toolbar->resize(400, 300);
        groupBox = new QGroupBox(toolbar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 239, 401, 61));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 20, 102, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(100, 20, 102, 20));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(200, 20, 102, 20));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(0, 40, 102, 20));
        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(100, 40, 102, 20));
        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(200, 40, 102, 20));

        retranslateUi(toolbar);

        QMetaObject::connectSlotsByName(toolbar);
    } // setupUi

    void retranslateUi(QDialog *toolbar)
    {
        toolbar->setWindowTitle(QApplication::translate("toolbar", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("toolbar", "Toolbar", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("toolbar", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("toolbar", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("toolbar", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("toolbar", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("toolbar", "RadioButton", 0, QApplication::UnicodeUTF8));
        radioButton_6->setText(QApplication::translate("toolbar", "RadioButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class toolbar: public Ui_toolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBAR_H
