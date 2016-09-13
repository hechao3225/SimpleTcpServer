#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myserver.h"
#include "myclient.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:

    void sendLineDone(QString);

private slots:
    void on_pushButton_start_clicked();
    void setReadyReadStatus();

    void setStartStatus();
    void setShutdownStatus();
    void updateClientStatus();

    void on_pushButton_shutdown_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    MyServer *server;

};

#endif // WIDGET_H
