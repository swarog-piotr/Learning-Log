#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSampleSubjects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSampleSubjects()
{
    Subject astronomy("Astronomy");
    astronomy.appendDate(QDateTime::currentDateTime());

    subjects.append(astronomy);

    ui->listWidgetSubjects->addItem(subjects[0].getName());

    Subject electronics("Electronics");
    astronomy.appendDate(QDateTime::currentDateTime());

    subjects.append(electronics);

    ui->listWidgetSubjects->addItem(subjects[1].getName());

}
