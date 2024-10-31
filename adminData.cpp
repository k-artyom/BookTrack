#include "adminData.h"
#include <qdebug.h>

AdminData::AdminData(){

}
AdminData::AdminData(int id, const QString& login, const QString& password) :
    id(id), login(login), password(password){
};

int AdminData::getId() const{
    return id;
};
void AdminData::setId(int id){
    this->id = id;
};

QString AdminData::getAdminLogin() const {
    qDebug() << "getAdminLogin used";
    return login;
};
void AdminData::setAdminLogin(const QString& login){
    qDebug() << "setAdminLogin used";
    this->login = login;
};

QString AdminData::getAdminPassword() const {
    qDebug() << "getAdminPassword used";
    return password;
};
void AdminData::setAdminPassword(const QString& password) {
    qDebug() << "setAdminPassword used";
    this->password = password;
};

QString AdminData::toString(){
    return  "Admin(id " + QString::number(id) +
            ", login: " + login +
            ", password: " + password +
            ")";
};
