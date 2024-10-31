#ifndef SQLITE_DB_MANAGER_H
#define SQLITE_DB_MANAGER_H

#include <QSqlDatabase>

#include "adminData.h"
#include "bookData.h"
#include "readerData.h"
#include "issueData.h"

// #include <string>
using namespace std;

// Абстрактний клас (інтерфейс) для роботи з базою даних
class DBManager {
public:
    // Суто віртуальний метод для підключення до бази даних
    virtual void connectToDataBase() = 0;

    // Суто віртуальний метод для отримання обробника (хендлера) підключення до БД
    virtual QSqlDatabase& getDB() = 0;

    // Суто віртуальний метод для збереження повідомлення у базі даних
    // virtual bool inserIntoTable(const Message& message) = 0;
    virtual bool insertIntoAdminsTable(const AdminData& adminData) = 0;
    // virtual bool insertIntoBooksTable(const BookData& bookInfo) = 0;
    // virtual bool insertIntoReadersTable(const ReaderData& readerData) = 0;
    // virtual bool insertIntoIssuesTable(const IssueData& issueData) = 0;

    // Суто віртуальний метод для отримання повідомлення по id

    virtual AdminData findAdminDataById(int id) = 0;
    // virtual BookData findBookDataById(int id) = 0;
    // virtual ReaderData findReaderDataById(int id) = 0;
    // virtual IssueData findIssueDataById(int id) = 0;

    // virtual AdminData findAdminByLogin(string login) = 0;

};

#endif // SQLITE_DB_MANAGER_H
