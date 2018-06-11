#ifndef SIGNUP_H
#define SIGNUP_H
#include<QMainWindow>
#include <QWidget>
#include<QDialog>
#include<mainwindow.h>

class signup : public QDialog
{
    Q_OBJECT
    signup* ui;

public:
    explicit signup(QMainWindow *parent = 0);
    ~signup();

private slots:

};


#endif // SIGNUP_H
