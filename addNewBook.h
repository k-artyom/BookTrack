#ifndef ADDNEWBOOK_H
#define ADDNEWBOOK_H

#include <QDialog>

namespace Ui {
class AddNewBook;
}
class DBManager;

class AddNewBook : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewBook(DBManager* dbManager, QWidget *parent = nullptr);
    ~AddNewBook();

private:
    DBManager* dbManager;
    Ui::AddNewBook *ui;
};

#endif // ADDNEWBOOK_H
