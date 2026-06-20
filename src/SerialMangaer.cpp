#include "SerialManager.h"

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{
    serial.setPortName("Arduio port");
    serial.setBaudRate(QSerialPort::Baud9600);

    if(serial.open(QIODevice::ReadOnly))
        qDebug() << "Serial Conected";
    else
        qDebug() << "Failed to open port";
}