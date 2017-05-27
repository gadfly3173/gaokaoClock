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
/*int strYear = 0;
QDate gaokaoDat(2017,6,7);
qint64 i = 0;
qint64 dayNumbe = 0;
int strYearr = 0;
QDate gaokaoDate(2017,6,7);
qint64 dayNumb = 0;
QString dayNum = 0;*/

void Widget::mysetText()
{
    currentDate = QDate::currentDate();//获取当前时间
    /*strYear = currentDate.year();
    gaokaoDat(strYear,6,7);
    //qint64 i = 0;
    dayNumbe = currentDate.daysTo(gaokaoDat);
    if(dayNumbe<=i)
    {
        int strYearr = strYear + 1;
        QDate gaokaoDate(strYearr,6,7);
        qint64 dayNumb = currentDate.daysTo(gaokaoDate);
        QString dayNum = QString::number(dayNumb);
        ui->label->setText(dayNum);
    }
    else
    {
        dayNum = QString::number(dayNumbe);
        ui->label->setText(dayNum);
    }*/
    if(currentDate.daysTo(QDate(currentDate.year(),6,7))<=0)//判断距离今年高考剩余天数是否小于等于零
    {
        ui->label->setText(QString::number(currentDate.daysTo(QDate (currentDate.year() + 1,6,7))));//显示距离明年高考日的剩余天数
    }
    else
    {
        ui->label->setText(QString::number(currentDate.daysTo(QDate(currentDate.year(),6,7))));//显示距离今年高考日的剩余天数
    }

}

Widget::~Widget()
{
    delete ui;
}
