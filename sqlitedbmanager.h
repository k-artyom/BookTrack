#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H


#include <QSqlDatabase>
#include "dbmanager.h"



// Назіва БД
#define DATABASE_HOST_NAME   "BookTrackDB"
// Назва файлу БД
#define DATABASE_FILE_NAME   "BookTrackDataBase.sqlite"


#define TABLE_ADMINS "admins"
#define TABLE_ADMINS_LOGIN  "login"
#define TABLE_ADMINS_PASSWORD "password"

// #define TABLE_BOOKS "books"

// Клас, який реалізує логіку абстрактного класу DBManager для роботи із БД SQLite
class SqliteDBManager : public DBManager{
public:
    // Метод для отримання екземпляру даного класу (патерн Singleton)
    static SqliteDBManager* getInstance();

    // Метод для підключення до бази даних
    void connectToDataBase() override;

    // Метод для отримання обробника (хендлера) підключення до БД
    QSqlDatabase& getDB() override;

    // Метод для вставки записів у таблицю
    bool insertIntoAdminsTable(const AdminData& adminData) override;
    // bool insertIntoBooksTable(const BookData& bookData) override;
    // bool insertIntoReadersTable(const ReaderData& readerData) override;
    // bool insertIntoIssuesTable(const IssueData& issueData) override;

    // Метод для отримання обьекта по id
    AdminData findAdminDataById(int id) override;
    // BookData findBookDataById(int id) override;
    // ReaderData findReaderDataById(int id) override;
    // IssueData findIssueDataById(int id) override;

private:
    // Обробник підключення до БД, через який буде виконуватись робота із БД
    QSqlDatabase db;

    static SqliteDBManager* instance;

    // Приватний конструктор
    SqliteDBManager();

    // Внутрішні методи для роботи з базою даних
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();

    bool createAdminTable();
};

#endif // SQLITEDBMANAGER_H
