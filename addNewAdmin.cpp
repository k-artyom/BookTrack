


#include "addNewAdmin.h"
#include "ui_addNewAdmin.h"
#include "adminData.h"

#include "dbmanager.h"
// #include "sqlitedbmanager.h"

AddNewAdmin::AddNewAdmin(DBManager* dbManager, QWidget *parent) :
    QDialog(parent),
    dbManager(dbManager),
    ui(new Ui::AddNewAdmin) {

    ui->setupUi(this);
}

void AddNewAdmin::on_createAdminBtn_clicked()
{
    QString newAdminLogin;
    QString newAdminPassword;

    // Перевірка на непорожність полів
    if ((newAdminLogin = ui->newAdmLogin->text()) != "" &&
        (newAdminPassword = ui->newAdmPass->text()) != ""){

        AdminData newAdminData;

        newAdminData.setAdminLogin(newAdminLogin);
        newAdminData.setAdminPassword(newAdminPassword);

        qDebug() << "Admin data seted into obj";
        qDebug() << "Admin data:";
        qDebug() << "newAdminData login: " + newAdminData.getAdminLogin();
        qDebug() << "newAdminData password: " + newAdminData.getAdminPassword();

        if (!(dbManager->insertIntoAdminsTable(newAdminData))){
            qDebug() << "dbManager->insertIntoAdminsTable(newAdminData) Повернув False";
        } else {
            QString additionMsg = "New admin '" + newAdminLogin + "' successfully added!";
            ui->additionResult_label->setText(additionMsg);
        }

    } else {
        ui->additionResult_label->setText("Поля не можуть бути порожніми");
    }
    // Доробити: ВЖЕ
    // 1. деактивація кнопки якщо порожньо
    // 2. очищеня полів після успіху + деактивація
}

AddNewAdmin::~AddNewAdmin()
{
    delete ui;
}
