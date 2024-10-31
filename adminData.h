#ifndef ADMINDATA_H
#define ADMINDATA_H

#include <QString>

class AdminData{
    int id;
    QString login;
    QString password;

public:
    AdminData();
    AdminData(int id, const QString& login, const QString& password);

    int getId() const;
    void setId(int id);

    QString getAdminLogin() const;
    void setAdminLogin(const QString& login);

    QString getAdminPassword() const;
    void setAdminPassword(const QString& password);

    QString toString();
};

#endif // ADMINDATA_H
