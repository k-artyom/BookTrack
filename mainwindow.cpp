

#include <QDebug> // Вивід повідомлень
#include <QMessageBox>

#include "mainwindow.h"
// #include "adminData.h"
#include "ui_mainwindow.h"

#include "addNewAdmin.h"
#include "addNewBook.h"

#include "dbmanager.h"
// #include "sqlitedbmanager.h"

MainWindow::MainWindow(DBManager* dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // відкриття вікна входу при відкритті програми
    ui->stackedWidget->setCurrentIndex(0);
    // деактивація функцій коли вхід не здійснено
    ui->logOut->setEnabled(false);
    ui->addAdmin->setEnabled(false);

    // налаштування поля входу
    ui->logInBtn->setShortcut(Qt::Key_Return);
    ui->passwordInput->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}


    // Клік по кнопці Увійти
void MainWindow::on_logInBtn_clicked()
{
    QString userName = "qwe";
    QString password = "123";

    QString inpUserName = ui->userNameInput->text();
    QString inpPassword = ui->passwordInput->text();

    if (inpUserName == userName && inpPassword == password){
        qDebug() << "login has been completed\n";
        ui->stackedWidget->setCurrentIndex(1); // Зміна екрану

        // активація функцій після входу
        ui->logOut->setEnabled(true);
        ui->addAdmin->setEnabled(true);

    } else {
        qDebug() << "login failed\n";
        ui->welcomeSubTitle->setText("Невірний пароль або логін спробуйте ще раз");
    }
}

// Клік по кнопці Вийти
void MainWindow::on_logOut_triggered()
{
    if (ui->stackedWidget->currentIndex() == 1){
        qDebug() << "exit completed\n";
        ui->stackedWidget->setCurrentIndex(0); // Зміна екрану
        ui->passwordInput->setText(""); // Очисщеня поля вводу пароля
        ui->logOut->setEnabled(false);
        ui->addAdmin->setEnabled(false);
    }
}


// Кнопка відкриття вікна Додати адміна
void MainWindow::on_addAdmin_triggered()
{
    AddNewAdmin newAdminDialog(dbManager);
    newAdminDialog.setModal(true);
    newAdminDialog.exec();
}

// Кнопка відкриття вікна Додати книгу
void MainWindow::on_addBookBtn_clicked()
{
    AddNewBook newBookDialog(dbManager);
    newBookDialog.setModal(true);
    newBookDialog.exec();
}

    // Про програму
void MainWindow::on_about_triggered()
{
    QMessageBox::about(this, "Кілька слів про програму...",
                            "<h3>BookTrack</h3>"
                            "<p>Версія 0.0.0</p>");
}
    // Довідка
void MainWindow::on_help_triggered()
{
    QMessageBox::about(this, "Довідка",
                             "<p>Інстукція з користування програмою...</p>");
}
