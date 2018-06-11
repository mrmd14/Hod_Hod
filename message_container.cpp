#include "message_container.h"


message_container::message_container(QString Isrc,QString Imessage,QString Idate,bool sv)

{
    SRC_vis =  sv;
    QVBoxLayout* v = new QVBoxLayout();
    QHBoxLayout* h = new QHBoxLayout();
    sp = new QSpacerItem(100,0);
    message  = new QTextBrowser();message->setText(Imessage);
    sp = new QSpacerItem(140,0);
    if(SRC_vis)
    src = new QLabel(Isrc);

    date = new QLabel(Idate);
    message->setReadOnly(1);
    if(SRC_vis)
    h->addWidget(src);
    else{
        h->addItem(sp);
    }
    h->addWidget(message);
    if(SRC_vis)
    h->addItem(sp);
    v->addLayout(h);
    v->addWidget(date);
    setLayout(v);

    //style----------------
    if(SRC_vis){
   src->setStyleSheet(tr("font:10px;font-weight: bold;color:#E95420;"));
    message->setStyleSheet(tr("background:#2C001E;border-radius:25px;color:#ffffff;padding:10px 10px 10px 10px;"));
    date->setStyleSheet(tr("color:#f4e3f3;font:10px;padding:7px 0px 0px 0px;"));
    }else{
        message->setStyleSheet(tr("background:#5E2750;border-radius:30px;color:#ffffff;padding:15px 10px 10px 10px;"));
        date->setStyleSheet(tr("color:#f4e3f3;font:10px;padding:7px 0px 0px 0px;"));
    }


   int sh = message->document()->characterCount()/36;
   sh++;
   sh *= 30;
   sh+= 10;
   if(sh<70)sh = 60;
   message->setFixedHeight(sh);


}


message_container::~message_container()
{

}
