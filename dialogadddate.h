#ifndef DIALOGADDDATE_H
#define DIALOGADDDATE_H

#include <QDialog>

namespace Ui {
class DialogAddDate;
}

class DialogAddDate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddDate(QWidget *parent = nullptr);
    ~DialogAddDate();

private:
    Ui::DialogAddDate *ui;
};

#endif // DIALOGADDDATE_H
