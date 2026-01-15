/**
 * @file DatabaseManager.h
 * @brief Заголовочный файл класса DatabaseManager
 * @ingroup Models
 * 
 * @class DatabaseManager
 * @brief Класс для управления подключением и операциями с базой данных
 * 
 * Отвечает за:
 * - Подключение к PostgreSQL базе данных
 * - Создание таблиц при необходимости
 * - Выполнение CRUD операций
 * - Управление соединением с БД
 * 
 * @warning Для работы требуется драйвер QPSQL
 */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QList>
#include "Teacher.h"
#include "Student.h"
#include "Subject.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
    
public:
    /**
     * @brief Конструктор класса DatabaseManager
     * @param parent Родительский QObject
     */
    explicit DatabaseManager(QObject *parent = nullptr);
    
    /**
     * @brief Деструктор класса DatabaseManager
     * @details Закрывает соединение с базой данных при уничтожении объекта
     */
    ~DatabaseManager();
    
    /**
     * @brief Подключиться к базе данных
     * @return bool true если подключение успешно, иначе false
     * 
     * @details Использует следующие параметры подключения:
     * - Хост: localhost
     * - Имя БД: university
     * - Пользователь: postgres
     * - Пароль: 1488
     */
    bool connectToDatabase();
    
    /**
     * @brief Проверить подключение к базе данных
     * @return bool true если подключение активно
     */
    bool isConnected() const;
    
    // Teacher operations
    
    /**
     * @brief Получить всех преподавателей
     * @return QList<Teacher*> Список указателей на объекты Teacher
     * 
     * @note Ответственность за удаление объектов лежит на вызывающей стороне
     */
    QList<Teacher*> getAllTeachers();
    
    /**
     * @brief Добавить нового преподавателя
     * @param fullName Полное имя преподавателя
     * @param department Кафедра преподавателя
     * @return bool true если операция успешна
     */
    bool addTeacher(const QString &fullName, const QString &department);
    
    /**
     * @brief Удалить преподавателя по ID
     * @param id Идентификатор преподавателя
     * @return bool true если удаление успешно
     */
    bool deleteTeacher(int id);
    
    /**
     * @brief Найти преподавателя по ID
     * @param id Идентификатор преподавателя
     * @return Teacher* Указатель на объект Teacher или nullptr если не найден
     */
    Teacher* getTeacherById(int id);
    
    // Student operations
    
    /**
     * @brief Получить всех студентов
     * @return QList<Student*> Список указателей на объекты Student
     */
    QList<Student*> getAllStudents();
    
    /**
     * @brief Добавить нового студента
     * @param fullName Полное имя студента
     * @param grade Оценка студента (1-5)
     * @return bool true если операция успешна
     */
    bool addStudent(const QString &fullName, int grade);
    
    /**
     * @brief Удалить студента по ID
     * @param id Идентификатор студента
     * @return bool true если удаление успешно
     */
    bool deleteStudent(int id);
    
    /**
     * @brief Найти студента по ID
     * @param id Идентификатор студента
     * @return Student* Указатель на объект Student или nullptr если не найден
     */
    Student* getStudentById(int id);
    
    // Subject operations
    
    /**
     * @brief Получить все предметы
     * @return QList<Subject*> Список указателей на объекты Subject
     */
    QList<Subject*> getAllSubjects();
    
    /**
     * @brief Добавить новый предмет
     * @param name Название предмета
     * @return bool true если операция успешна
     */
    bool addSubject(const QString &name);
    
    /**
     * @brief Удалить предмет по ID
     * @param id Идентификатор предмета
     * @return bool true если удаление успешно
     */
    bool deleteSubject(int id);
    
    /**
     * @brief Найти предмет по ID
     * @param id Идентификатор предмета
     * @return Subject* Указатель на объект Subject или nullptr если не найден
     */
    Subject* getSubjectById(int id);
    
    // Statistics
    
    /**
     * @brief Получить общее количество записей во всех таблицах
     * @return int Суммарное количество записей
     */
    int getTotalRecords() const;
    
signals:
    /**
     * @brief Сигнал о изменении состояния подключения к БД
     * @param success true если подключение успешно установлено
     */
    void databaseConnected(bool success);
    
    /**
     * @brief Сигнал об изменении данных в базе
     * @details Генерируется при любых операциях изменения данных (добавление, удаление)
     */
    void dataChanged();
    
private:
    /**
     * @brief Инициализировать базу данных
     * @details Создает необходимые таблицы если они не существуют
     */
    void initializeDatabase();
    
    /**
     * @brief Объект соединения с базой данных
     */
    QSqlDatabase m_database;
};

#endif // DATABASEMANAGER_H