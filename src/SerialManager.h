// To take input rfid
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#endif // SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parant = nullptr);

signals:
    void cardScanned(const QString &uid);

private slots:
    void onDataRecived();

private:
    QSerialPort serial;
    QByteArray buffer;
};
