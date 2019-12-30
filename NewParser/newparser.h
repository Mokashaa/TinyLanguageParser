#ifndef NEWPARSER_H
#define NEWPARSER_H

#include <QMainWindow>

namespace Ui {
class NewParser;
}

class NewParser : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewParser(QWidget *parent = 0);
    ~NewParser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::NewParser *ui;
};

#endif // NEWPARSER_H
