#include "mainwindow.h"
#include "firsttable.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Секретарь");
    w.setStyleSheet("QMainWindow{background-color: pink}");
    w.show();
    return a.exec();
}
