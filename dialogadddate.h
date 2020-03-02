#ifndef DIALOGADDDATE_H
#define DIALOGADDDATE_H

#include <QDialog>
#include <QDateTime>
namespace Ui {
class DialogAddDate;
}

class DialogAddDate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddDate(QWidget *parent = nullptr);
    ~DialogAddDate();

private:
    Ui::DialogAddDate *ui;

    QDate date;
    QTime timeSince;
    QTime timeTo;
};

#endif // DIALOGADDDATE_H
