#include "subject.h"

QString Subject::getName() const
{
    return name;
}

void Subject::setName(const QString &value)
{
    name = value;
}

QList<QString> Subject::getStringDates()
{
  dates[0].toString();

  QList<QString> dateList;
  foreach(QDateTime date, dates){
      dateList.append(date.toString());
  }

  return dateList;
}

//QVector<QDateTime>& Subject::getDates()
//{
//    return dates;
//}

void Subject::appendDate(const QDateTime &date)
{
    dates.append(date);
}



Subject::Subject()
{

}

Subject::Subject(QString name)
{
 this->name=name;
}
