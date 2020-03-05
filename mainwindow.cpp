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
    if(ui->listWidgetSubjects->currentRow()==-1){
        ui->statusBar->showMessage("First select a subject!",1500);
    }
    else{
   qDebug() <<  activeSubject->getStringIntervals();
    }
}


void MainWindow::read(const QJsonObject &json)
{
    if (json.contains("subjects") && json["subjects"].isArray()) {
            QJsonArray subjectsArray = json["subjects"].toArray();
            subjects.clear();
            subjects.reserve(subjects.size());
            for (int i = 0; i < subjectsArray.size(); ++i) {
                QJsonObject subjectObject = subjectsArray[i].toObject();
                Subject subject;
                subject.read(subjectObject);
                subjects.append(subject);
            }
    }
}


void MainWindow::write(QJsonObject &json) const
{
    QJsonArray subjectArray;
        for (const Subject &subject : subjects) {
            QJsonObject subjectObject;
            subject.write(subjectObject);
            subjectArray.append(subjectObject);
        }
        json["subjects"] = subjectArray;
}


bool MainWindow::loadSubjects()
{
    QFile loadFile( QStringLiteral("save.json") );
    if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return false;
        }

     QByteArray saveData = loadFile.readAll();

     QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

     read(loadDoc.object());

     QTextStream(stdout) << "Loaded save for "
                            << loadDoc["player"]["name"].toString()
                            << " using "
                            <<  "JSON...\n";
     return true;
}

bool MainWindow::saveSubjects()
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
            qWarning("Couldn't open save file.");
            return false;
        }

    QJsonObject subjectsObject;
    write(subjectsObject);
    QJsonDocument saveDoc(subjectsObject);
    saveFile.write(saveDoc.toJson());

    return true;
}


void MainWindow::on_pushButtonSAVE_clicked()
{
    saveSubjects();
}



void MainWindow::on_pushButton_clicked()
{
         ui->listWidgetSubjects->clear();
         loadSubjects();
         for(int i=0;i<subjects.size();i++){
             ui->listWidgetSubjects->addItem(subjects[i].getName());
         }//IMPORTANTE
}
