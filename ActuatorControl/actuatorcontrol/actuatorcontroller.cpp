#include "actuatorcontroller.h"
#include <QDebug>

ActuatorController::ActuatorController()
{
    m_actuatorStop = true;
    m_moveForward = false;
    m_moveBackward = false;

    m_actuator = new Actuator;
    m_actuator->setSpeed(10);

    m_actuatorThread = new ActuatorThread(m_actuator);
    m_actuatorThread->moveToThread(&m_workerThread);
    connect(&m_workerThread, SIGNAL(finished()), m_actuatorThread, SLOT(deleteLater()));
    connect(this, SIGNAL(startOperation()), m_actuatorThread, SLOT(doActuatorMove()));
    connect(m_actuatorThread, SIGNAL(readyActuatorMove()), this, SLOT(handleActuatorReady()));   

    qDebug() << Q_FUNC_INFO;
    m_workerThread.start();
}

ActuatorController::~ActuatorController()
{
    qDebug() << Q_FUNC_INFO;

    m_workerThread.quit();
    m_workerThread.wait();
}

void ActuatorController::handleActuatorReady()
{
    qDebug() << Q_FUNC_INFO;

    if(m_actuatorStop)
    {
        qDebug() << "Actuator stop";
    }
    else
    {
        if(m_moveForward)
        {
            moveActuatorForward();
        }
        if(m_moveBackward)
        {
            moveActuatorBackward();
        }
    }
}

void ActuatorController::moveActuatorForward()
{
    qDebug() << Q_FUNC_INFO;
    m_moveForward = true;
    m_moveBackward = false;
    m_actuatorStop = false;
    m_actuator->setDirection(true);
    m_actuator->setSetpointPosition(m_actuator->getPosition() + 1);
    emit startOperation();
}

void ActuatorController::moveActuatorBackward()
{
    qDebug() << Q_FUNC_INFO;
    m_moveForward = false;
    m_moveBackward = true;
    m_actuatorStop = false;
    m_actuator->setDirection(false);
    m_actuator->setSetpointPosition(m_actuator->getPosition() - 1);
    emit startOperation();
}

void ActuatorController::stopActuatorMovement()
{
    qDebug() << Q_FUNC_INFO;

    m_actuatorStop = true;
}

void ActuatorController::homeActuator()
{
    qDebug() << Q_FUNC_INFO;
}

void ActuatorController::moveActuatorTo()
{
    qDebug() << Q_FUNC_INFO;
    m_moveForward = false;
    m_moveBackward = false;
    m_actuatorStop = false;

    if(m_setPointPosition > m_actuator->getPosition())
    {
        m_actuator->setDirection(true);
        m_actuator->setSetpointPosition(m_setPointPosition);
        emit startOperation();
    }
    else
    {
        m_actuator->setDirection(false);
        m_actuator->setSetpointPosition(m_setPointPosition);
        emit startOperation();
    }
}

void ActuatorController::setSetpointPosition(long position)
{
    qDebug() << Q_FUNC_INFO;
    m_setPointPosition = position;

}

