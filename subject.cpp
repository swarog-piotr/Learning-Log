#include "subject.h"

QString Subject::getName() const
{
    return name;
}

void Subject::setName(const QString &value)
{
    name = value;
}

QVector<QDateTime> Subject::getDates() const
{
    return dates;
}

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
