#ifndef INTERVAL_H
#define INTERVAL_H

#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>

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

    void read(const QJsonObject &json);


    void write(QJsonObject &json) const;
};

#endif // INTERVAL_H
