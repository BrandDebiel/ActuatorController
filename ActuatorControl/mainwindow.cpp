#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_actuatorController = new ActuatorController;
//    while(1)
//    {
//        for(int i = 0; i < 100; i++)
//        {
//            qDebug() << "Position: " << i;
//        }
//    }

    connect(ui->pushButtonForward, SIGNAL(pressed()), m_actuatorController, SLOT(moveActuatorForward()));
    connect(ui->pushButtonBack, SIGNAL(pressed()), m_actuatorController, SLOT(moveActuatorBackward()));
    connect(ui->pushButtonForward, SIGNAL(released()), m_actuatorController, SLOT(stopActuatorMovement()));
    connect(ui->pushButtonBack, SIGNAL(released()), m_actuatorController, SLOT(stopActuatorMovement()));
    connect(ui->pushButtonGoTo, SIGNAL(clicked(bool)), m_actuatorController, SLOT(moveActuatorTo()));
    connect(ui->lineEditPosition, SIGNAL(textChanged(QString)), this, SLOT(setPosition()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPosition()
{
    bool ok = false;
    m_actuatorController->setSetpointPosition(QString(ui->lineEditPosition->text()).toLong(&ok));
}
