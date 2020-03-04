#include "interval.h"

Interval::Interval()
{

}

QString Interval::toQString(){
    QString formattedDate;
    formattedDate = date.toString("dddd dd.MM ");
    formattedDate.append(timeSince.toString() + " - " + timeTo.toString());
//    fullstring.append(timeSince.toString());
//    fullstring.append(timeTo.toString());
    return formattedDate;
}

void Interval::setInterval(const QDate &date, const QTime &timeSince, const QTime &timeTo)
{
    this->date = date;
    this->timeSince = timeSince;
    this->timeTo = timeTo;
}


