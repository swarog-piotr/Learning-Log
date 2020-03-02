#include "interval.h"

Interval::Interval()
{

}

QString Interval::toQString(){
    QString fullstring;

    fullstring.append("dzien tygodnia ");
    fullstring.append(date.toString());
    fullstring.append(timeSince.toString());
    fullstring.append(timeTo.toString());

    return fullstring;
}

void Interval::setInterval(QDate date, QTime timeSince, QTime timeTo)
{
    this->date = date;
    this->timeSince = timeSince;
    this->timeTo = timeTo;
}


