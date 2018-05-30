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
        void setSPeed(quint16 speed);

        long int getPosition();
        bool getDirection();
        quint16 getSpeed();
        bool isHomed();

        void home();

    public slots:

    private:
        long m_position;
        long m_offset;
        long m_limit;
        quint16 m_speed;
        bool m_direction;
        bool m_isHomed;
        bool m_stepPinLevel;

        quint8 m_stepPin;
        quint8 m_directionPin;


        void setHomed(bool isHomed);
        void makeStep();
		
	private slots:

	signals:


};

#endif // ACTUATOR_H
