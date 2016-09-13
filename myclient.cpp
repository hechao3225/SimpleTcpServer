#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(500);//最大同时连接500个Client

    clientSocket = new QTcpSocket(this);

    QThreadPool::globalInstance()->start(this);//启动一个新的线程来执行任务
    setAutoDelete(true);

}

void MyClient::setSocket(qintptr socketDescriptor)
{
    clientSocket->setSocketDescriptor(socketDescriptor);
}

QByteArray MyClient::getAllData()
{
    return allData;
}

int MyClient::getClientID()
{
   qint64 id=static_cast<qint64>(clientSocket->socketDescriptor());
   return id;
}

void MyClient::slotReadyRead()
{
    allData=clientSocket->readAll();
    qDebug()<<"communicate beginning.."
            <<allData;
    emit readyreadStatusChanged();

}
//写
void MyClient::slotSendLine(QString sendLine)
{
    clientSocket->write(sendLine.toLatin1());
    clientSocket->waitForBytesWritten();
}

void MyClient::run()
{
    //读
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));

    //耗时操作：测试（否则会死锁）
    int i=0;
    qDebug()<<"task start";
    for(;i<10000;i++);
    qDebug()<<"task done";
    clientSocket->write(QString::number(i).toLatin1());
    clientSocket->waitForBytesWritten();

}

