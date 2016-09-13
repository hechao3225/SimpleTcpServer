#include "mytask.h"
#include <QDebug>
MyTask::MyTask(QObject *parent) : QObject(parent),QRunnable()
{

}

void MyTask::run()
{
    allData =clientSocket->readAll();
}
