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

void MainWindow::on_listWidgetSubjects_itemClicked(QListWidgetItem *item)
{
    QString clickedSubjectName = item->text();
    Subject wantedSubject;
    foreach(Subject suspectSubject, subjects){ //create a separate method
        if(suspectSubject.getName()==clickedSubjectName){
            wantedSubject=suspectSubject;
        }
    }

    ui->listWidgetTimes->addItems(wantedSubject.getStringDates());


}










void MainWindow::on_pushButtonAddTime_clicked()
{

    if(ui->listWidgetSubjects->currentRow()==-1){
        ui->statusBar->showMessage("First select a subject!",500);
    }



}



