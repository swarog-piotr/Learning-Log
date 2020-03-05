#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QVector>
#include <QDateTime>
#include "interval.h"


class Subject
{
private:
    QString name;
    QString notes;
    QVector<Interval> intervals;

public:
    Subject();
    Subject(QString name);
    QString getName() const;
    void setName(const QString &value);

    QList<QString> getStringIntervals();
    void appendInterval(const QDate& date=QDate::currentDate(), const QTime& timeSince=QTime::currentTime(), const QTime& timeTo=QTime::currentTime());

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;


};

#endif // SUBJECT_H
