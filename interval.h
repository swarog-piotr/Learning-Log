#ifndef INTERVAL_H
#define INTERVAL_H

#include <QDateTime>


class Interval
{
public:
    Interval();
    QString toQString();
    void setInterval(QDate date, QTime timeSince, QTime timeTo); //TODO: proper signature
private:

    QDate date;
    QTime timeSince;
    QTime timeTo;
};

#endif // INTERVAL_H
