/********************************************************************************
** Form generated from reading UI file 'newparser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPARSER_H
#define UI_NEWPARSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewParser
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NewParser)
    {
        if (NewParser->objectName().isEmpty())
            NewParser->setObjectName(QStringLiteral("NewParser"));
        NewParser->resize(553, 353);
        centralWidget = new QWidget(NewParser);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 481, 61));
        QFont font;
        font.setFamily(QStringLiteral("Umpush"));
        font.setPointSize(19);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 100, 361, 20));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 100, 80, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 140, 80, 25));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 180, 535, 103));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(26, 40, 491, 61));
        label_3->setAlignment(Qt::AlignCenter);
        NewParser->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NewParser);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 553, 22));
        NewParser->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NewParser);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NewParser->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NewParser);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NewParser->setStatusBar(statusBar);

        retranslateUi(NewParser);

        QMetaObject::connectSlotsByName(NewParser);
    } // setupUi

    void retranslateUi(QMainWindow *NewParser)
    {
        NewParser->setWindowTitle(QApplication::translate("NewParser", "NewParser", Q_NULLPTR));
        label->setText(QApplication::translate("NewParser", "YOUR PERFECT PARSER", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewParser", "Choose file  ..", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NewParser", "Browse", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NewParser", "Parse!", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NewParser", "Parsing Feedback:", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewParser: public Ui_NewParser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPARSER_H
