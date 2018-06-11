#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define ip_server "http://api.softserver.org:1104/"
#include <QMainWindow>
#include<QPushButton>
#include <QSpacerItem>
#include<QDesktopWidget>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QWidget>
#include <QApplication>
#include <QSizePolicy>
#include<QDesktopWidget>
#include<QWindow>
#include<QtNetwork>
#include<QLabel>
#include<QJsonDocument>
#include<QJsonObject>
#include<QDebug>

//---------------------------
#include<signup.h>
#include<signin.h>
#include<contaact_container.h>
#include<master.h>
#include<user.h>
extern master_user cur_u;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //login part
    QLineEdit* signin_line[2];
    QPushButton* signin_btn[2];
    QLabel* logo;
    //network
   QNetworkAccessManager* manager;
   QNetworkRequest req;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void setC_u(const master_user &value);
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
