#ifndef ADDNEWADMIN_H
#define ADDNEWADMIN_H

#include <QDialog>

namespace Ui {
class AddNewAdmin;
}

class DBManager;

class AddNewAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewAdmin(DBManager* dbManager, QWidget *parent = nullptr);

    ~AddNewAdmin();

private slots:
    void on_createAdminBtn_clicked();

private:
    DBManager* dbManager;
    Ui::AddNewAdmin *ui;


};

#endif // ADDNEWADMIN_H
