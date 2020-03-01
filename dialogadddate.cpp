#include "dialogadddate.h"
#include "ui_dialogadddate.h"

DialogAddDate::DialogAddDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddDate)
{
    ui->setupUi(this);
    ui->dateTimeEditSince->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEditTo->setDateTime(QDateTime::currentDateTime());



}

DialogAddDate::~DialogAddDate()
{
    delete ui;
}
