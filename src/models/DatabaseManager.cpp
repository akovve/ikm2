/**
 * @file DatabaseManager.cpp
 * @brief Реализация класса DatabaseManager
 * @ingroup Models
 */

#include "DatabaseManager.h"
#include <QDebug>
#include <QSqlError>

/**
 * @brief Конструктор DatabaseManager
 * @param parent Родительский QObject
 * 
 * @details Создает подключение к базе данных PostgreSQL с именем "university_connection"
 */
DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
{
    m_database = QSqlDatabase::addDatabase("QPSQL", "university_connection");
}

/**
 * @brief Деструктор DatabaseManager
 * 
 * @details Закрывает соединение с базой данных если оно открыто
 */
DatabaseManager::~DatabaseManager()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

/**
 * @brief Подключение к базе данных
 * @return bool Результат операции подключения
 * 
 * @details Устанавливает параметры подключения и пытается открыть соединение.
 * В случае успеха инициализирует структуру базы данных.
 */
bool DatabaseManager::connectToDatabase()
{
    m_database.setHostName("localhost");
    m_database.setDatabaseName("university");
    m_database.setUserName("postgres");
    m_database.setPassword("1488");
    
    if (m_database.open()) {
        qDebug() << "✅ PostgreSQL подключен успешно!";
        initializeDatabase();
        emit databaseConnected(true);
        return true;
    } else {
        qCritical() << "❌ Ошибка подключения к PostgreSQL:" << m_database.lastError().text();
        emit databaseConnected(false);
        return false;
    }
}

/**
 * @brief Проверка подключения к базе данных
 * @return bool Состояние подключения
 */
bool DatabaseManager::isConnected() const
{
    return m_database.isOpen();
}

/**
 * @brief Инициализация структуры базы данных
 * 
 * @details Создает три таблицы если они не существуют:
 * - teachers: преподаватели
 * - students: студенты  
 * - subjects: предметы
 */
void DatabaseManager::initializeDatabase()
{
    QSqlQuery query(m_database);
    
    // Create teachers table
    query.exec("CREATE TABLE IF NOT EXISTS teachers ("
               "id SERIAL PRIMARY KEY, "
               "full_name VARCHAR(100) NOT NULL, "
               "department VARCHAR(100) NOT NULL)");
    
    // Create students table
    query.exec("CREATE TABLE IF NOT EXISTS students ("
               "id SERIAL PRIMARY KEY, "
               "full_name VARCHAR(100) NOT NULL, "
               "grade INTEGER CHECK (grade >= 1 AND grade <= 5))");
    
    // Create subjects table
    query.exec("CREATE TABLE IF NOT EXISTS subjects ("
               "id SERIAL PRIMARY KEY, "
               "name VARCHAR(100) NOT NULL)");
}

/**
 * @brief Получение списка всех преподавателей
 * @return QList<Teacher*> Список преподавателей
 * 
 * @note Вызывающая сторона должна освободить память объектов Teacher
 */
QList<Teacher*> DatabaseManager::getAllTeachers()
{
    QList<Teacher*> teachers;
    QSqlQuery query("SELECT id, full_name, department FROM teachers ORDER BY id", m_database);
    
    while (query.next()) {
        Teacher *teacher = new Teacher(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString()
        );
        teachers.append(teacher);
    }
    
    return teachers;
}

/**
 * @brief Добавление нового преподавателя
 * @param fullName Полное имя преподавателя
 * @param department Кафедра преподавателя
 * @return bool Результат операции
 */
bool DatabaseManager::addTeacher(const QString &fullName, const QString &department)
{
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO teachers (full_name, department) VALUES (?, ?)");
    query.addBindValue(fullName);
    query.addBindValue(department);
    
    if (query.exec()) {
        emit dataChanged();
        return true;
    }
    return false;
}

/**
 * @brief Удаление преподавателя по ID
 * @param id Идентификатор преподавателя
 * @return bool Результат операции
 */
bool DatabaseManager::deleteTeacher(int id)
{
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM teachers WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.numRowsAffected() > 0) {
        emit dataChanged();
        return true;
    }
    return false;
}

/**
 * @brief Поиск преподавателя по ID
 * @param id Идентификатор преподавателя
 * @return Teacher* Найденный преподаватель или nullptr
 */
Teacher* DatabaseManager::getTeacherById(int id)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT id, full_name, department FROM teachers WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        return new Teacher(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString()
        );
    }
    return nullptr;
}

/**
 * @brief Получение списка всех студентов
 * @return QList<Student*> Список студентов
 */
QList<Student*> DatabaseManager::getAllStudents()
{
    QList<Student*> students;
    QSqlQuery query("SELECT id, full_name, grade FROM students ORDER BY id", m_database);
    
    while (query.next()) {
        Student *student = new Student(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toInt()
        );
        students.append(student);
    }
    
    return students;
}

/**
 * @brief Добавление нового студента
 * @param fullName Полное имя студента
 * @param grade Оценка студента
 * @return bool Результат операции
 */
bool DatabaseManager::addStudent(const QString &fullName, int grade)
{
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO students (full_name, grade) VALUES (?, ?)");
    query.addBindValue(fullName);
    query.addBindValue(grade);
    
    if (query.exec()) {
        emit dataChanged();
        return true;
    }
    return false;
}

/**
 * @brief Удаление студента по ID
 * @param id Идентификатор студента
 * @return bool Результат операции
 */
bool DatabaseManager::deleteStudent(int id)
{
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM students WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.numRowsAffected() > 0) {
        emit dataChanged();
        return true;
    }
    return false;
}

/**
 * @brief Поиск студента по ID
 * @param id Идентификатор студента
 * @return Student* Найденный студент или nullptr
 */
Student* DatabaseManager::getStudentById(int id)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT id, full_name, grade FROM students WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        return new Student(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toInt()
        );
    }
    return nullptr;
}

/**
 * @brief Получение списка всех предметов
 * @return QList<Subject*> Список предметов
 */
QList<Subject*> DatabaseManager::getAllSubjects()
{
    QList<Subject*> subjects;
    QSqlQuery query("SELECT id, name FROM subjects ORDER BY id", m_database);
    
    while (query.next()) {
        Subject *subject = new Subject(
            query.value(0).toInt(),
            query.value(1).toString()
        );
        subjects.append(subject);
    }
    
    return subjects;
}

/**
 * @brief Добавление нового предмета
 * @param name Название предмета
 * @return bool Результат операции
 */
bool DatabaseManager::addSubject(const QString &name)
{
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO subjects (name) VALUES (?)");
    query.addBindValue(name);
    
    if (query.exec()) {
        emit dataChanged();
        return true;
    }
    return false;
}

/**
 * @brief Удаление предмета по ID
 * @param id Идентификатор предмета
 * @return bool Результат операции
 */
bool DatabaseManager::deleteSubject(int id)
{
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM subjects WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.numRowsAffected() > 0) {
        emit dataChanged();
        return true;
    }
    return false;
}

/**
 * @brief Поиск предмета по ID
 * @param id Идентификатор предмета
 * @return Subject* Найденный предмет или nullptr
 */
Subject* DatabaseManager::getSubjectById(int id)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT id, name FROM subjects WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        return new Subject(
            query.value(0).toInt(),
            query.value(1).toString()
        );
    }
    return nullptr;
}

/**
 * @brief Получение общего количества записей
 * @return int Суммарное количество записей во всех таблицах
 */
int DatabaseManager::getTotalRecords() const
{
    int count = 0;
    QSqlQuery query(m_database);
    
    query.exec("SELECT COUNT(*) FROM teachers");
    if (query.next()) count += query.value(0).toInt();
    
    query.exec("SELECT COUNT(*) FROM students");
    if (query.next()) count += query.value(0).toInt();
    
    query.exec("SELECT COUNT(*) FROM subjects");
    if (query.next()) count += query.value(0).toInt();
    
    return count;
}