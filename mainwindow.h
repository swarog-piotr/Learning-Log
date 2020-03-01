#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subject.h"
#include <QListWidgetItem>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listWidgetSubjects_itemClicked(QListWidgetItem *item);

    void on_pushButtonAddTime_clicked();

private:
    Ui::MainWindow *ui;

    QVector<Subject> subjects;


    void initSampleSubjects();

};

#endif // MAINWINDOW_H
