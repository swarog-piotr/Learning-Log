#include "dialogadddate.h"
#include "ui_dialogadddate.h"

DialogAddDate::DialogAddDate(Subject *subject, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddDate)
{
    ui->setupUi(this);
    chosenSubject=subject;
    ui->labelSubject->setText(chosenSubject->getName());


    ui->timeEditSince->setTime(QTime::currentTime());
    ui->timeEditTo->setTime(QTime::currentTime());
    ui->dateEdit->setDate(QDate::currentDate());

}

DialogAddDate::~DialogAddDate()
{
    delete ui;
}

void DialogAddDate::on_pushButtonAdd_clicked()
{
    date = ui->dateEdit->date();
    timeSince = ui->timeEditSince->time();
    timeTo = ui->timeEditTo->time();

    chosenSubject->appendInterval(date, timeSince, timeTo);
    qDebug() << chosenSubject->getStringIntervals();

    close();
}
