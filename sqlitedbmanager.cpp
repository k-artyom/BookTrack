#include "sqlitedbmanager.h"

#include <QSqlDatabase>
#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>

SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager::SqliteDBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName(DATABASE_FILE_NAME);
}

// Метод для отримання екземпляру даного класу (патерн Singleton)
SqliteDBManager* SqliteDBManager::getInstance() {
    if (instance == nullptr) {
        instance = new SqliteDBManager();
    }
    return instance;
}

// Метод для підключення до бази даних
void SqliteDBManager::connectToDataBase() {
    /* Перед підключенням до бази даних виконуємо перевірку на її існування.
     * В залежності від результату виконуємо відкриття бази даних або її відновлення */
    if (QFile(DATABASE_FILE_NAME).exists()) {

        qDebug() << "Файл бази даних існує";

        this->openDataBase();
    } else {
        this->restoreDataBase();
    }
}

// Метод для отримання обробника підключення до БД
QSqlDatabase& SqliteDBManager::getDB() {
    return db;
}

// Метод відновлення бази даних
bool SqliteDBManager::restoreDataBase() {
    if (this->openDataBase()) {
        if (!this->createAdminTable()) {
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

// Метод для відкриття бази даних
bool SqliteDBManager::openDataBase() {
    /* База даних відкривається по вказаному шляху
     * та імені бази даних, якщо вона існує
     * */
    if (db.open()) {
        qDebug() << "openDataBase FN db.open() True";
        return true;
    }
    qDebug() << "openDataBase FN db.open() False";
    return false;


}

// Метод закриття бази даних
void SqliteDBManager::closeDataBase() {
    db.close();
}

// Метод для створення таблиці в базі даних
bool SqliteDBManager::createAdminTable() {
    /* В даному випадку використовується фурмування сирого SQL-запиту
     * з наступним його виконанням.
     * */
    QSqlQuery query;
    if (!query.exec("CREATE TABLE " TABLE_ADMINS " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_ADMINS_LOGIN " VARCHAR(255) NOT NULL,"
                    TABLE_ADMINS_PASSWORD " VARCHAR(255) NOT NULL)")
        )
    {
        qDebug() << "DataBase: error of create " << TABLE_ADMINS;
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "createAdminTable succes";
        return true;
    }

}

// Метод для вставки записів у таблицю admins
bool SqliteDBManager::insertIntoAdminsTable(const AdminData& adminData) {
    qDebug() << "Початок функції insertIntoAdminsTable";
    // SQL-запит формується із об'єкта класу AdminData
    QSqlQuery query;
    /*
     * Спочатку SQL-запит формується з ключами, які потім зв'язуються методом bindValue
     * для підставки даних із об'єкта класу AdminData
     * */
    query.prepare("INSERT INTO " TABLE_ADMINS " ( "
                  TABLE_ADMINS_LOGIN ", "
                  TABLE_ADMINS_PASSWORD ") "
                  "VALUES (:Login, :Password)");

    query.bindValue(":Login", adminData.getAdminLogin());
    query.bindValue(":Password", adminData.getAdminPassword());

    // Після чого виконується запит методом exec()
    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE_ADMINS;
        qDebug() << query.lastError().text();
        qDebug() << "Failed query: " << query.lastQuery();
        return false;

    } else {
        qDebug() << "Insert successful into " << TABLE_ADMINS;
        return true;
    }

}

// Метод для отримання данних про адміна по id
AdminData SqliteDBManager::findAdminDataById(int id) {
    QSqlQuery query(this->db);
    AdminData adminData;
    // Спочатку формується SQL-запит з ключем (заповнювачем) 'id', який потім замінюється значенням методом bindValue
    query.prepare("SELECT * FROM " TABLE_ADMINS " WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        adminData.setId(query.value("id").toInt());
        adminData.setAdminLogin(query.value(TABLE_ADMINS_LOGIN).toString());
        adminData.setAdminPassword(query.value(TABLE_ADMINS_PASSWORD).toString());
    }
    return adminData;
}
