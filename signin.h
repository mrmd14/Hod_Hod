#ifndef SIGNIN_H
#define SIGNIN_H
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
#include<user.h>
#include<mainwindow.h>
class signin : public QDialog
{
    Q_OBJECT
    //login part
    QLineEdit* signin_line[2];
    QPushButton* signin_btn[2];
    QLabel* logo;

    //network
    QNetworkAccessManager* manager;
    QNetworkRequest req;
    QString j_code;
     QJsonDocument  j_doc;
     QJsonObject j_ob;


public:
    explicit signin(QMainWindow *parent = 0);
    ~signin();


private slots:
     void signin_btn_slot();
     void rp_func(QNetworkReply* rp);

};



#endif // SIGNIN_H
