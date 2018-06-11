#ifndef CONTAACT_CONTAINER_H
#define CONTAACT_CONTAINER_H

#include <QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
namespace Ui {
class contaact_container;
}

class contaact_container : public QWidget
{
    Q_OBJECT
public:
    QLabel* avatar;
    QLabel* name;
    QLabel* last_text;
    QHBoxLayout* container;
    QVBoxLayout* det;

public:
    explicit contaact_container(QWidget *parent = 0);
    ~contaact_container();

private:
    Ui::contaact_container *ui;
};

#endif // CONTAACT_CONTAINER_H
