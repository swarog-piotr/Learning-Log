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


void Interval::write(QJsonObject &json) const
{
    json["date"] = date.toString();
    json["timeSince"] = timeSince.toString();
    json["timeTo"] = timeTo.toString();
}

void Interval::read(const QJsonObject &json)
{
    if (json.contains("date") && json["date"].isString())
           date = QDate::fromString(json["date"].toString());

    if(json.contains("timeSince") && json["timeSince"].isString())
           timeSince=QTime::fromString(json["timeSince"].toString());

    if(json.contains("timeTo") && json["timeTo"].isString())
           timeTo=QTime::fromString(json["timeTo"].toString());
}










