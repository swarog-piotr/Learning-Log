#ifndef INTERVAL_H
#define INTERVAL_H

#include <QDateTime>


class Interval
{
private:
    QDate date;
    QTime timeSince;
    QTime timeTo;
public:
    Interval();
    void setInterval(const QDate& date,const  QTime& timeSince,const QTime& timeTo);
    QString toQString();
};

#endif // INTERVAL_H
