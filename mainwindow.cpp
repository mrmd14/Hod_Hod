#include "mainwindow.h"
#include "ui_mainwindow.h"
#define d_w dw.width()*0.50
#define d_h dw.height()*0.84


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    signin* ob;
    MASTER* master_p;
    QDesktopWidget dw;
    ob = new signin(this);
    ob->setFixedSize(d_w,d_h);
    //signup* ob2 = new signup(this);
    ob->setStyleSheet(tr("background-color:#2c001e;padding:10px;"));
    ob->exec();
    delete ob;
    if(cur_u.getToken().size()!= 0){
    master_p = new MASTER(this);
    master_p->setFixedSize(d_w,d_h);
     master_p->setStyleSheet("background-color:#2c001e;");
    master_p->exec();
    }
    exit(0);
}

MainWindow::~MainWindow()
{

}


