#include "master.h"

MASTER::MASTER(QMainWindow *parent)

{
    LW = new QListWidget;
    QVBoxLayout* list = new QVBoxLayout();
    QVBoxLayout* message_box = new QVBoxLayout();
    QHBoxLayout* page = new QHBoxLayout();
    QWidget* m_b = new QWidget();

    //TO MODIFY--------------------------------------------
    manager = new QNetworkAccessManager();
    a_CC =  new contaact_container();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(contaact_rep(QNetworkReply*)));
    QString r= "http://api.softserver.org:1104/getuserlist?token=";
    r+= cur_u.getToken();
    req.setUrl(r);
    manager->get(req);
    a_CC->setStyleSheet(tr("color:#ffffff;background:none;"));
    a_it = new QListWidgetItem();
    a_it->setSizeHint(a_CC->sizeHint());
    LW->addItem(a_it);
    LW->setItemWidget(a_it,a_CC);
    //---------------------------------------------
    LW->setFixedWidth(200);
    LW->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     list->addWidget(LW);
     message_box->addWidget(m_b);
     page->addLayout(list);
     page->addLayout(message_box);
     LW->setStyleSheet("QListWidget::item:selected { background:#411934;border-radius: 5px;  };");
     setLayout(page);
     //////////////////////////
     ////////////////////
     /// /////////////////////
      m_b->setFixedWidth(350);
      m_b->setStyleSheet(tr("background:#3333333;"));

}

MASTER::~MASTER()
{

}

void MASTER::contaact_rep(QNetworkReply *rep)
{
    QString data = (QString) rep->readAll();
    QJsonDocument json_d= QJsonDocument::fromJson(data.toUtf8());
    QJsonObject Json_ob= json_d.object();
    QJsonObject Json_ob_chat= Json_ob["block 0"].toObject();
   a_CC->avatar->setText(tr("M"));//first letter of name
   a_CC->name->setText(Json_ob_chat["src"].toString().toUtf8());
   a_CC->last_text->setText(tr("last text"));//last text
}
