#include "widget.h"
#include "ui_widget.h"
#include <QDate>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);//声明计时器

    connect(timer,SIGNAL(timeout()),this,SLOT(mysetText()));//信号函数
    timer->start(1000);//一秒刷新一次
}

QDate currentDate = QDate::currentDate();

void Widget::mysetText()
{
    currentDate = QDate::currentDate();//获取当前时间

    ui->label->setText(QString::number(
                           currentDate.daysTo(QDate(currentDate.year() +
                                               (currentDate.daysTo(QDate(currentDate.year(),6,7))<=0?1:0)
                                                                                    ,6,7)
                                              )
                                       )
                       );
}

Widget::~Widget()
{
    delete ui;
}
