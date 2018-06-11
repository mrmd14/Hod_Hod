#ifndef USER_H
#define USER_H
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

struct user_pass{
    QString user;
    QString pass;
};
struct name_last_name{
    QString name;
    QString last_name;
};
class master_user{

    user_pass u_p;
    name_last_name n_l;
    QString token;
public:
    master_user();
    ~master_user();

    user_pass getU_p() const;
    void setU_p(const user_pass &value);
    name_last_name getN_l() const;
    void setN_l(const name_last_name &value);
    QString getToken() const;
    void setToken(const QString &value);
};
extern master_user cur_u;
#endif // USER_H
