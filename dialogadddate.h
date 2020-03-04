#ifndef DIALOGADDDATE_H
#define DIALOGADDDATE_H

#include <QDialog>
#include <QDateTime>
#include "subject.h"
#include <QDebug>
namespace Ui {
class DialogAddDate;
}

class DialogAddDate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddDate(Subject* subject, QWidget *parent = nullptr);
    ~DialogAddDate();

private slots:
    void on_pushButtonAdd_clicked();

private:
    Ui::DialogAddDate *ui;

    QDate date;
    QTime timeSince;
    QTime timeTo;
    Subject* chosenSubject;

};

#endif // DIALOGADDDATE_H
