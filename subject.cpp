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
  QList<QString> datesList;

  if(dates.empty()){
      datesList.append("");
  }
  else{
      foreach(QDateTime date, dates){
         datesList.append(date.toString());
      }
  }
  return datesList;
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
