#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);

    int remainingMoney = money;
    count500 = remainingMoney / 500;
    remainingMoney %= 500;
    count100 = remainingMoney / 100;
    remainingMoney %= 100;
    count50 = remainingMoney / 50;
    remainingMoney %= 50;
    count10 = remainingMoney / 10;
}

void Widget::resetCoins()
{
    count500 = 0;
    count100 = 0;
    count50 = 0;
    count10 = 0;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString message = "500원 : " + QString::number(count500) + "개\n"
                      "100원 : " + QString::number(count100) + "개\n"
                      "50원 : " + QString::number(count50) + "개\n"
                      "10원 : " + QString::number(count10) + "개";
    mb.information(nullptr, "Coins", message);

    resetCoins();
    money = 0;
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

