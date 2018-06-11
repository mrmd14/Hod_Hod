#include "contaact_container.h"


contaact_container::contaact_container(QWidget *parent) :
    QWidget(parent)

{
    det = new QVBoxLayout;
    container = new QHBoxLayout;
    avatar = new QLabel;
    name = new QLabel;
    last_text = new QLabel;
    det->addWidget(name);
    det->addWidget(last_text);
    container->addWidget(avatar);
    container->addLayout(det);
    setLayout(container);
    avatar->setFixedWidth(25);
    avatar->setStyleSheet(tr("font:20px;font-weight: bold;color:#E95420;"));
    name->setStyleSheet(tr("font:15px;font-weight: bold;color:#B5A5B0;"));
    last_text->setStyleSheet(tr("font:10px;font-weight: normal;color:#ffffff;"));
}

contaact_container::~contaact_container()
{
    delete det;
    delete container;
    delete avatar;
    delete name;
    delete last_text;
}
