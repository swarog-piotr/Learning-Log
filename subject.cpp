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




