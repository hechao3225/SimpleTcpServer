#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QRunnable>
#include <QDebug>
#include <QThreadPool>

class MyClient : public QObject,public QRunnable
{
    Q_OBJECT

public:
    explicit MyClient(QObject *parent = 0);
    void setSocket(qintptr socketDescriptor);
    QByteArray getAllData();
    int getClientID();

signals:
    void readyreadStatusChanged();
public slots:
    void slotReadyRead();
    void slotSendLine(QString sendLine);
protected:
    void run();
private:
    QTcpSocket *clientSocket;
    QByteArray allData;


};

#endif // MYCLIENT_H
