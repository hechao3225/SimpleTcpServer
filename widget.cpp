#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new MyServer(this);

    connect(server,SIGNAL(startStatus()),this,SLOT(setStartStatus()));
    connect(server,SIGNAL(shutdownStatus()),this,SLOT(setShutdownStatus()));
    connect(server,SIGNAL(newConnection()),this,SLOT(updateClientStatus()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_start_clicked()
{
    server->startServer();

}

void Widget::setReadyReadStatus()
{
     ui->label_status->setText(tr("start communicating.."));
     ui->label_content->setText(tr("   socketID:")+QString::number(server->client->getClientID())
                                +tr("   number:")+QString::number(server->getClientCount()));
     ui->textEdit->append(server->client->getAllData());
}

void Widget::setStartStatus()
{
    ui->label_status->setText(tr("server start"));
}

void Widget::setShutdownStatus()
{
    ui->label_status->setText(tr("server shut down"));
}

void Widget::updateClientStatus()
{
    ui->label_content->setText(tr("   socketID:")+QString::number(server->client->getClientID())
                               +tr("   number:")+QString::number(server->getClientCount()));
    connect(server->client,SIGNAL(readyreadStatusChanged()),this,SLOT(setReadyReadStatus()));
    connect(this,SIGNAL(sendLineDone(QString)),server->client,SLOT(slotSendLine(QString)));
}


void Widget::on_pushButton_shutdown_clicked()
{
    server->shutdownServer();
}

void Widget::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
        emit sendLineDone(ui->lineEdit->text());
}
