#include "myserver.h"

MyServer::MyServer(QObject *parent):QTcpServer(parent)
{
    clientCount=0;
}

void MyServer::startServer()
{
    if(listen(QHostAddress::Any,8888))
    {
         emit startStatus();
    }
}

void MyServer::shutdownServer()
{
    this->close();
    emit shutdownStatus();
}

qint64 MyServer::getClientCount()
{
    return clientCount;
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    client =new MyClient(this);
    client->setSocket(socketDescriptor);
    clientCount++;
}
