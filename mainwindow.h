#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class DBManager; //

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DBManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void on_logOutBtn_clicked();

    void on_logInBtn_clicked();
    void on_addAdmin_triggered();
    void on_addBookBtn_clicked();
    void on_about_triggered();
    void on_help_triggered();
    void on_logOut_triggered();

private:
    Ui::MainWindow *ui;
    DBManager* dbManager; //
};
#endif // MAINWINDOW_H
