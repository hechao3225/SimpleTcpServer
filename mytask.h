#ifndef MYTASK_H
#define MYTASK_H

#include <QObject>
#include <QRunnable>
#include "myclient.h"

class MyTask : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MyTask(QObject *parent = 0);

signals:

public slots:

protected:
    void run();


};

#endif // MYTASK_H
