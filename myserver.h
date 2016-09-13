#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include "myclient.h"

class MyServer : public QTcpServer
{
    Q_OBJECT

signals:
    void startStatus();
    void shutdownStatus();
    void clientComing();

public:
    explicit MyServer(QObject *parent = 0);

    void startServer();
    void shutdownServer();
    qint64 getClientCount();

    MyClient *client;

public slots:

protected:

    void incomingConnection(qintptr socketDescriptor);

private:
    QThreadPool *threadPool;
    qint64 clientCount;
};

#endif // MYSERVER_H
