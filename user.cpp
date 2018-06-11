#include "user.h"


name_last_name master_user::getN_l() const
{
    return n_l;
}

void master_user::setN_l(const name_last_name &value)
{
    n_l = value;
}

QString master_user::getToken() const
{
    return token;
}

void master_user::setToken(const QString &value)
{
    token = value;
}

master_user::master_user()
{

}

master_user::~master_user()
{

}

user_pass master_user::getU_p() const
{
    return u_p;
}

void master_user::setU_p(const user_pass &value)
{
    u_p = value;
}
master_user cur_u;
