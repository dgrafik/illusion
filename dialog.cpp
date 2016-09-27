#include "dialog.h"
#include "ui_dialog.h"
#include<QTimer>
#include<QDesktopWidget>
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    myTimerEnabled(false)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), ui->widget, SLOT(nextFrame()));
    QDesktopWidget desktop;
    int desktopHeight = desktop.geometry().height();
    int desktopWidth = desktop.geometry().width();
    this->resize(desktopWidth/2, desktopHeight/2);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    myTimerEnabled = !myTimerEnabled;
    if (myTimerEnabled)
    {
        timer->start(333);
        ui->pushButton->setText("&Stop");
    }
    else
    {
        timer->stop();
        ui->pushButton->setText("&Start");
    }
}
bool Dialog::event(QEvent *event)
{
    static int counter = 0;
    counter++;
    qDebug()<<counter<<event->type();
    return QDialog::event(event);
}
