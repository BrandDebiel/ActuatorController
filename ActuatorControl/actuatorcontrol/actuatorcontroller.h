#ifndef ACTUATORCONTROLLER_H
#define ACTUATORCONTROLLER_H

#include <QObject>
#include <QThread>

#include "actuatorthread.h"
#include "actuator.h"

class ActuatorController : public QObject
{
    Q_OBJECT
    QThread m_workerThread;

    public:
        ActuatorController();
        ~ActuatorController();

    public slots:
        void moveActuatorForward();
        void moveActuatorBackward();
        void stopActuatorMovement();
        void homeActuator();
        void moveActuatorTo();
        void setSetpointPosition(long position);

    private:        
        ActuatorThread *m_actuatorThread;
        Actuator *m_actuator;
        bool m_actuatorStop;
        bool m_moveForward;
        bool m_moveBackward;
        long m_setPointPosition;

		
	private slots:
        void handleActuatorReady();


	signals:
        void startOperation();


};

#endif // ACTUATORCONTROLLER_H
