#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QVector>
#include <QDateTime>

class Subject
{
private:
    QString name;
    QString notes;
    QVector<QDateTime> dates;



public:
    Subject();
    Subject(QString name);
    QString getName() const;
    void setName(const QString &value);
    QVector<QDateTime> getDates() const;
    void appendDate(const QDateTime &date);
};

#endif // SUBJECT_H
