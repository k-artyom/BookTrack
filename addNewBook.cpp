#include "addNewBook.h"
#include "ui_addNewBook.h"
#include "dbmanager.h"
// #include "bookData.h"
// #include "sqlitedbmanager.h"

AddNewBook::AddNewBook(DBManager* dbManager, QWidget *parent) :
    QDialog(parent),
    dbManager(dbManager),
    ui(new Ui::AddNewBook)
{
    ui->setupUi(this);
}

AddNewBook::~AddNewBook()
{
    delete ui;
}
