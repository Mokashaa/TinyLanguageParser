#include "newparser.h"
#include "ui_newparser.h"
#include <QFileDialog>
#include <QMessageBox>
#include<QPlainTextEdit>
#include <QProcess>
#include<QTextStream>
#include <QPalette>

QString file_name="";

NewParser::NewParser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewParser)
{

    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
}

NewParser::~NewParser()
{
    delete ui;
}

void NewParser::on_pushButton_clicked()
{
    file_name = QFileDialog::getOpenFileName(this , "Choose Tokens File");
    if(file_name.size()==0)
    {
        ui->pushButton_2->setEnabled(false);
    }
    else
    {
        int filelength = file_name.length()-1 ;
        if(file_name[filelength] == 't' && file_name[filelength-1] == 'x' && file_name[filelength-2]=='t'){
            ui->pushButton_2->setEnabled(true);
        }
        else{
            QMessageBox::information(this,"Error","You must choose txt file !");
            ui->pushButton_2->setEnabled(false);
        }
    }

    ui->label_2->setText(file_name);

}

void NewParser::on_pushButton_2_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString  command("python");
    QStringList params = QStringList() << "parser.py" << file_name ;
    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
    for (int i = 0; i<100000000;i++);
    QFile inputFile("result.txt");
    QString line;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       line = in.readLine();
       inputFile.close();
    }
    ui->label_3->setText(line);
}
