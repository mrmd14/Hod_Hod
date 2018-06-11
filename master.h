#ifndef MASTER_H
#define MASTER_H

#include <QMainWindow>
#include<contaact_container.h>
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
#include<QListWidgetItem>
#include<QWidget>
#include<QListView>
#include <QListWidget>
#include <QVector>
#include<QThread>
#include<QScrollArea>
#include<mainwindow.h>
#include<contaact_container.h>
#include<message_container.h>
class MASTER : public QDialog
{
    Q_OBJECT
    QVector<contaact_container*> contact_list;
    QVector<QListWidgetItem*>contact_list_item;
    contaact_container* a_CC;
    QListWidgetItem* a_it;
    QListWidget* LW;
    //network
    QNetworkAccessManager* manager;
    QNetworkRequest req;
    //message box
    QVector<message_container*> m_list;
    QScrollArea* scrol_box;
    QNetworkRequest m_req;

public:
    explicit MASTER(QMainWindow *parent = 0);
    ~MASTER();

private slots:
    void contaact_rep(QNetworkReply* rep);

};

#endif // MASTER_H
