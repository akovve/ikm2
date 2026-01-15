/**
 * @file UniversityViewModel.h
 * @brief Заголовочный файл класса UniversityViewModel
 * @ingroup ViewModels
 * 
 * @class UniversityViewModel
 * @brief ViewModel для взаимодействия между моделями и QML интерфейсом
 * 
 * Класс выполняет функции:
 * - Предоставляет данные для отображения в QML
 * - Обрабатывает пользовательские действия из QML
 * - Управляет обновлением данных
 * - Отслеживает состояние подключения к БД
 * 
 * @property QStringList UniversityViewModel::teachers
 * @brief Список преподавателей в строковом формате
 * 
 * @property QStringList UniversityViewModel::students
 * @brief Список студентов в строковом формате
 * 
 * @property QStringList UniversityViewModel::subjects
 * @brief Список предметов в строковом формате
 * 
 * @property int UniversityViewModel::totalRecords
 * @brief Общее количество записей во всех таблицах
 * 
 * @property bool UniversityViewModel::isConnected
 * @brief Состояние подключения к базе данных
 */

#ifndef UNIVERSITYVIEWMODEL_H
#define UNIVERSITYVIEWMODEL_H

#include <QObject>
#include <QStringList>
#include <QAbstractListModel>
#include "../models/DatabaseManager.h"
#include "../models/Teacher.h"
#include "../models/Student.h"
#include "../models/Subject.h"

class UniversityViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList teachers READ teachers NOTIFY dataChanged)
    Q_PROPERTY(QStringList students READ students NOTIFY dataChanged)
    Q_PROPERTY(QStringList subjects READ subjects NOTIFY dataChanged)
    Q_PROPERTY(int totalRecords READ totalRecords NOTIFY dataChanged)
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionChanged)
    
public:
    /**
     * @brief Конструктор UniversityViewModel
     * @param parent Родительский QObject
     * 
     * @details При создании автоматически пытается подключиться к БД
     */
    explicit UniversityViewModel(QObject *parent = nullptr);
    
    /**
     * @brief Деструктор UniversityViewModel
     */
    ~UniversityViewModel();
    
    /**
     * @brief Получить список преподавателей
     * @return QStringList Список преподавателей
     */
    QStringList teachers() const;
    
    /**
     * @brief Получить список студентов
     * @return QStringList Список студентов
     */
    QStringList students() const;
    
    /**
     * @brief Получить список предметов
     * @return QStringList Список предметов
     */
    QStringList subjects() const;
    
    /**
     * @brief Получить общее количество записей
     * @return int Количество записей
     */
    int totalRecords() const;
    
    /**
     * @brief Проверить подключение к БД
     * @return bool Состояние подключения
     */
    bool isConnected() const;
    
    /**
     * @brief Добавить преподавателя (инвокабельный метод для QML)
     * @param name Имя преподавателя
     * @param department Кафедра
     * @return bool Результат операции
     */
    Q_INVOKABLE bool addTeacher(const QString &name, const QString &department);
    
    /**
     * @brief Добавить студента (инвокабельный метод для QML)
     * @param name Имя студента
     * @param grade Оценка
     * @return bool Результат операции
     */
    Q_INVOKABLE bool addStudent(const QString &name, int grade);
    
    /**
     * @brief Добавить предмет (инвокабельный метод для QML)
     * @param name Название предмета
     * @return bool Результат операции
     */
    Q_INVOKABLE bool addSubject(const QString &name);
    
    /**
     * @brief Удалить преподавателя по ID (инвокабельный метод для QML)
     * @param id Идентификатор преподавателя
     * @return bool Результат операции
     */
    Q_INVOKABLE bool deleteTeacher(int id);
    
    /**
     * @brief Удалить студента по ID (инвокабельный метод для QML)
     * @param id Идентификатор студента
     * @return bool Результат операции
     */
    Q_INVOKABLE bool deleteStudent(int id);
    
    /**
     * @brief Удалить предмет по ID (инвокабельный метод для QML)
     * @param id Идентификатор предмета
     * @return bool Результат операции
     */
    Q_INVOKABLE bool deleteSubject(int id);
    
    /**
     * @brief Обновить данные (инвокабельный метод для QML)
     */
    Q_INVOKABLE void refresh();
    
    /**
     * @brief Подключиться к базе данных (инвокабельный метод для QML)
     * @return bool Результат подключения
     */
    Q_INVOKABLE bool connectToDatabase();
    
signals:
    /**
     * @brief Сигнал об изменении данных
     * @details Генерируется при любом изменении данных в БД
     */
    void dataChanged();
    
    /**
     * @brief Сигнал об изменении состояния подключения
     */
    void connectionChanged();
    
    /**
     * @brief Сигнал об ошибке
     * @param message Текст ошибки
     */
    void errorOccurred(const QString &message);
    
private:
    /**
     * @brief Обновить список преподавателей
     */
    void updateTeachers();
    
    /**
     * @brief Обновить список студентов
     */
    void updateStudents();
    
    /**
     * @brief Обновить список предметов
     */
    void updateSubjects();
    
private:
    DatabaseManager *m_dbManager;   ///< Менеджер базы данных
    QStringList m_teachers;         ///< Кэшированный список преподавателей
    QStringList m_students;         ///< Кэшированный список студентов
    QStringList m_subjects;         ///< Кэшированный список предметов
};

#endif // UNIVERSITYVIEWMODEL_H