#ifndef MESSAGE_CONTAINER_H
#define MESSAGE_CONTAINER_H

#include <QWidget>
#include<QTextBrowser>
#include<QLabel>
#include<QVBoxLayout>
#include<QString>
#include <QSpacerItem>

class message_container : public QWidget
{
    Q_OBJECT
public:
   QTextBrowser* message;
   QLabel* src;
   QLabel* date;
   bool SRC_vis=1;
   QSpacerItem* sp;
public:
    explicit message_container(QString Isrc,QString Imessage,QString Idate,bool sv);
    ~message_container();

private:

};

#endif // MESSAGE_CONTAINER_H
