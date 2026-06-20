// To take input rfid
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#endif // SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parant = nullptr);

private:
    QSerialPort serial;
};
