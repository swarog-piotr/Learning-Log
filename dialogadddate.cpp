#include "dialogadddate.h"
#include "ui_dialogadddate.h"

DialogAddDate::DialogAddDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddDate)
{
    ui->setupUi(this);
    ui->timeEditSince->setTime(QTime::currentTime());
    ui->timeEditTo->setTime(QTime::currentTime());
    ui->dateEdit->setDate(QDate::currentDate());

}

DialogAddDate::~DialogAddDate()
{
    delete ui;
}
