#include "newparser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewParser w;
    w.show();

    return a.exec();
}
