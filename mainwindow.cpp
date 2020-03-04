#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSampleSubjects();
    connect(ui->listWidgetSubjects,&QListWidget::itemClicked,this,&MainWindow::searchForActiveSubject);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//custom slots
void MainWindow::searchForActiveSubject(QListWidgetItem *item)
{
    QString clickedSubjectName = item->text();

    for(int i=0;i<subjects.size();i++){
        if(subjects[i].getName()==clickedSubjectName){
            activeSubject=&(subjects[i]);
            break;
        }
    }


    qDebug()<< activeSubject->getName();
    qDebug() << activeSubject->getStringIntervals();

    updateListWidgetItems();
}




void MainWindow::initSampleSubjects()
{
    Subject astronomy("Astronomy");
    astronomy.appendInterval();
    astronomy.appendInterval();
    subjects.append(astronomy);

    ui->listWidgetSubjects->addItem(subjects[0].getName());

    Subject electronics("Electronics");

    electronics.appendInterval();
    subjects.append(electronics);

    ui->listWidgetSubjects->addItem(subjects[1].getName());

}

void MainWindow::updateListWidgetItems()
{
    ui->listWidgetTimes->clear();
    ui->listWidgetTimes->addItems(activeSubject->getStringIntervals());
}


void MainWindow::on_pushButtonAddTime_clicked()
{

    if(ui->listWidgetSubjects->currentRow()==-1){
        ui->statusBar->showMessage("First select a subject!",500);
        qDebug() << activeSubject->getStringIntervals();
    }
    else{
        DialogAddDate* dialog = new DialogAddDate(activeSubject, this);
        dialog->exec();
        updateListWidgetItems();
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


void MainWindow::on_pushButtonTEST_clicked()
{
   qDebug() <<  activeSubject->getStringIntervals();
}
