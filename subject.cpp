#include "subject.h"
#include <QDebug>
Subject::Subject()
{

}

Subject::Subject(QString name)
{
 this->name=name;
}

QString Subject::getName() const
{
    return name;
}

void Subject::setName(const QString &value)
{
    name = value;
}

QList<QString> Subject::getStringIntervals()
{
  QList<QString> datesList;
  datesList.clear();

  qDebug()<<"inside object " << name;

  if(intervals.empty()){
      datesList.append("");
  }
  else{
      foreach(Interval interval, intervals){
         datesList.append(interval.toQString());
      }
  }
  return datesList;
}



void Subject::appendInterval(const QDate& date, const QTime& timeSince, const QTime& timeTo)
{
    Interval interval;
    interval.setInterval(date,timeSince,timeTo);
    intervals.append(interval);
}

void Subject::write(QJsonObject &json) const
{
    json["name"] = name;
    json["notes"] = notes;

    QJsonArray intervalsArray;

    for(const Interval& interval: intervals){
        QJsonObject intervalObject;
        interval.write(intervalObject);
        intervalsArray.append(intervalObject);
    }
    json["intervals"] = intervalsArray;
}

void Subject::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
            name = json["name"].toString();

    if (json.contains("notes") && json["notes"].isDouble())
            notes = json["notes"].toString();


    if(json.contains("intervals") & json["intervals"].isArray()) {
        QJsonArray intervalsArray = json["intervals"].toArray();
        intervals.clear();
        intervals.reserve(intervalsArray.size());
        for(int i=0;i<intervalsArray.size();i++){
            QJsonObject intervalObject = intervalsArray[i].toObject();
            Interval interval;
            interval.read(intervalObject);
            intervals.append(interval);
        }
    }
}



