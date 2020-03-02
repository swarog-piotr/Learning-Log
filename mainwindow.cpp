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
    astronomy.appendInterval();
    subjects.append(astronomy);

    ui->listWidgetSubjects->addItem(subjects[0].getName());

    Subject electronics("Electronics");
    astronomy.appendInterval();

    subjects.append(electronics);

    ui->listWidgetSubjects->addItem(subjects[1].getName());

}



void MainWindow::on_listWidgetSubjects_itemClicked(QListWidgetItem *item)
{
    ui->listWidgetTimes->clear();

    QString clickedSubjectName = item->text();
    Subject wantedSubject;
    foreach(Subject suspectSubject, subjects){ //create a separate method
        if(suspectSubject.getName()==clickedSubjectName){
            wantedSubject=suspectSubject;
        }
    }

    ui->listWidgetTimes->addItems(wantedSubject.getStringIntervals());


}










void MainWindow::on_pushButtonAddTime_clicked()
{

    if(ui->listWidgetSubjects->currentRow()==-1){
        ui->statusBar->showMessage("First select a subject!",500);
    }
    else{
        DialogAddDate* dialog = new DialogAddDate(this);
        dialog->show();
    }



}




void MainWindow::on_pushButtonAddSubject_clicked()
{
    QString subjectName = QInputDialog::getText(this,"What's the name?","Enter the name");

    //add subject method?
    if(subjectName!=""){
        Subject subject(subjectName);
        subjects.append(subject);
        ui->listWidgetSubjects->addItem(subject.getName());
    }
}
