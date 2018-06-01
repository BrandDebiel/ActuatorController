#include "actuator.h"
#include <QDebug>

Actuator::Actuator()
{
    setPosition(0);
}

void Actuator::initialize(quint8 stepPin, quint8 directionPin)
{
    m_stepPin = stepPin;
    m_directionPin = directionPin;
    m_stepPinLevel = false;
    m_direction = false;
    m_speed = 100;

//    bcm2835_gpio_fsel(m_A2, m_stepPin);
//    bcm2835_gpio_fsel(m_A2, m_directionPin);
//    bcm2835_gpio_write(m_stepPin, m_stepPinLevel);
//    bcm2835_gpio_write(m_directionPin, m_direction);


}

void Actuator::setOffset(long offset)
{
    m_offset = offset;
}

void Actuator::setLimit(long limit)
{
    m_limit = limit;
}

void Actuator::setDirection(bool direction)
{
    m_direction = direction;
//    bcm2835_gpio_write(m_directionPin, m_direction);
}

void Actuator::setSpeed(quint16 speed)
{
    m_speed = speed;
}

long Actuator::getPosition()
{
    return(m_position);
}

bool Actuator::getDirection()
{
    return(m_direction);
}

quint16 Actuator::getSpeed()
{
    return(m_speed);
}

bool Actuator::isHomed()
{
    return(m_isHomed);
}

void Actuator::home()
{

}

void Actuator::makeStep()
{
    m_stepPinLevel = !m_stepPinLevel;

    if(m_direction)
    {
        //Make step
        m_position++;
    }
    else
    {
        //Make step
        m_position--;
    }

    qDebug() << "Actuator::postition: " << m_position;
//    bcm2835_gpio_write(m_stepPin, m_stepPinLevel);
}

void Actuator::setPosition(long position)
{
    m_position = position;
}

void Actuator::setSetpointPosition(long position)
{
    m_setPointPosition = position;
}

long Actuator::getSetPointPosition()
{
    return m_setPointPosition;
}
