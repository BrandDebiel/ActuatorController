/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonGoTo;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonHome;
    QPushButton *pushButtonForward;
    QLineEdit *lineEditPosition;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonGoTo = new QPushButton(centralWidget);
        pushButtonGoTo->setObjectName(QStringLiteral("pushButtonGoTo"));

        gridLayout->addWidget(pushButtonGoTo, 0, 0, 1, 1);

        pushButtonBack = new QPushButton(centralWidget);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));

        gridLayout->addWidget(pushButtonBack, 1, 0, 1, 1);

        pushButtonHome = new QPushButton(centralWidget);
        pushButtonHome->setObjectName(QStringLiteral("pushButtonHome"));

        gridLayout->addWidget(pushButtonHome, 1, 1, 1, 1);

        pushButtonForward = new QPushButton(centralWidget);
        pushButtonForward->setObjectName(QStringLiteral("pushButtonForward"));

        gridLayout->addWidget(pushButtonForward, 1, 2, 1, 1);

        lineEditPosition = new QLineEdit(centralWidget);
        lineEditPosition->setObjectName(QStringLiteral("lineEditPosition"));

        gridLayout->addWidget(lineEditPosition, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButtonGoTo->setText(QApplication::translate("MainWindow", "GoTo", Q_NULLPTR));
        pushButtonBack->setText(QApplication::translate("MainWindow", "back", Q_NULLPTR));
        pushButtonHome->setText(QApplication::translate("MainWindow", "home", Q_NULLPTR));
        pushButtonForward->setText(QApplication::translate("MainWindow", "forward", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
