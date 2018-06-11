#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget dw;
    MainWindow w;
    w.setFixedSize(dw.width()*0.5,dw.height()*0.75);
    w.show();
    return a.exec();
}
