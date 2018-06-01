#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QObject>

class Actuator : public QObject
{
    Q_OBJECT

    public:
        Actuator();
        void initialize(quint8 stepPin, quint8 directionPin);
        void moveToPosition(long position);
        void setOffset(long offset);
        void setLimit(long limit);
        void setDirection(bool direction);
        void setSpeed(quint16 speed);
        void setPosition(long position);
        void setSetpointPosition(long position);
        void makeStep();

        long getPosition();
        long getSetPointPosition();
        bool getDirection();
        quint16 getSpeed();
        bool isHomed();

        void home();

    public slots:


    private:
        long m_position;
        long m_setPointPosition;
        long m_offset;
        long m_limit;
        quint16 m_speed;
        bool m_direction;
        bool m_isHomed;
        bool m_stepPinLevel;

        quint8 m_stepPin;
        quint8 m_directionPin;


        void setHomed(bool isHomed);

		
	private slots:

	signals:


};

#endif // ACTUATOR_H
