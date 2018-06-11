#include "signin.h"
#include<QMainWindow>
#include<mainwindow.h>

signin::signin(QMainWindow *parent)

{
    QHBoxLayout* main_layout= new QHBoxLayout;
    QVBoxLayout* container  = new QVBoxLayout;
    QWidget* wi_container = new QWidget();
    QHBoxLayout* btn_container  = new QHBoxLayout;
    QHBoxLayout* central_layout  = new QHBoxLayout;
    logo = new QLabel(tr("\tHOD HOD"));
    for(int  i=0;i<2;i++){
        if(!i)
        signin_btn[i] = new QPushButton(tr("signin"));
        else
        signin_btn[i] = new QPushButton(tr("signup"));
        signin_line[i] = new QLineEdit;
        signin_btn[i]->setStyleSheet(tr("background-color:#333333;border:none;border-radius:5px;"));
        signin_line[i]->setStyleSheet(tr("background-color:#333333;border:none;border-radius:5px;"));
    }
    container->addWidget(logo);
    signin_line[0]->setPlaceholderText(tr("user name"));
    signin_line[1]->setPlaceholderText(tr("password"));
    for(int i =0 ;i<2;i++)
        container->addWidget(signin_line[i]);
        for(int i =0 ;i<2;i++)
         btn_container->addWidget(signin_btn[i]);
        container->addLayout(btn_container);
        wi_container->setLayout(container);
        main_layout->addWidget(wi_container);
        QWidget* central  = new QWidget;
        central->setLayout(main_layout);
        central_layout->addWidget(central);
        setLayout(central_layout);
        //style----------
        //setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
        wi_container->setFixedWidth(300);
        wi_container->setFixedHeight(200);
        wi_container->setStyleSheet(tr("color:#ffffff;background-color:#411934;border-radius:5px;"));
        logo->setStyleSheet(tr("font-size:20px;"));

        //SIGNAL SLOT----------------------
       connect(signin_btn[0],SIGNAL(clicked(bool)),this,SLOT(signin_btn_slot()));
       connect(signin_btn[1],SIGNAL(clicked(bool)),this,SLOT(signup_btn_slot()));
}

signin::~signin()
{

}
void signin::signin_btn_slot()
{
    signin_line[0]->setPlaceholderText(tr("user name"));
    signin_line[1]->setPlaceholderText(tr("password"));
    bool ret= 0;
   for(int i=0;i<2;i++)
       if(signin_line[i]->text()=="")
          {  signin_line[i]->setStyleSheet(tr("background-color:#E95420;"));
          ret= 1;
       }
           else
           signin_line[i]->setStyleSheet(tr("background-color:#333333;"));
  if(ret) return;
   manager   = new QNetworkAccessManager;
   connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(rp_func(QNetworkReply*)));
   QString r = "http://api.softserver.org:1104/login?username="+signin_line[0]->text()+"&password="+signin_line[1]->text();
   req.setUrl(QUrl(r));
   manager->get(req);
   }
void signin::rp_func(QNetworkReply *rp)
{

    QString data = (QString) rp->readAll();
     j_doc = QJsonDocument::fromJson(data.toUtf8());
     j_ob= j_doc.object();
    j_code= j_ob["code"].toString();
    if(j_code!= "200"){
        if(j_code=="404"){
            QString u ="User";
            u+= "\tNot Found!!!";
            signin_line[0]->setText("");
            signin_line[0]->setPlaceholderText(u);
            signin_line[0]->setStyleSheet(tr("background-color:#f44250;"));
        }else if(j_code=="401"){
            signin_line[1]->setText("");
            signin_line[1]->setPlaceholderText(tr("Password is not Correct."));
            signin_line[1]->setStyleSheet(tr("background-color:#f44250;"));
        }
    }else{
        user_pass value;
        value.user = signin_line[0]->text();
        value.pass = signin_line[1]->text();
        cur_u.setU_p(value);
        cur_u.setToken(j_ob["token"].toString());
        this->close();

    }

}


