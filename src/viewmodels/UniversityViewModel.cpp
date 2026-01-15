/**
 * @file UniversityViewModel.cpp
 * @brief Реализация класса UniversityViewModel
 * @ingroup ViewModels
 */

#include "UniversityViewModel.h"
#include <QDebug>
#include <QTimer> 
#include <QCoreApplication>

/**
 * @brief Конструктор UniversityViewModel
 * @param parent Родительский QObject
 * 
 * @details Инициализирует менеджер БД и настраивает соединения сигналов.
 * Автоматически пытается подключиться к БД с небольшой задержкой.
 */
UniversityViewModel::UniversityViewModel(QObject *parent)
    : QObject(parent)
    , m_dbManager(new DatabaseManager(this))
{
    // Подключаем сигналы от менеджера БД
    connect(m_dbManager, &DatabaseManager::dataChanged, this, &UniversityViewModel::refresh);
    connect(m_dbManager, &DatabaseManager::databaseConnected, this, [this](bool success) {
        if (success) {
            refresh();
        }
        emit connectionChanged();
    });
    
    // Пытаемся подключиться к БД с задержкой (после инициализации UI)
    QTimer::singleShot(0, this, &UniversityViewModel::connectToDatabase);
}

/**
 * @brief Деструктор UniversityViewModel
 * 
 * @note DatabaseManager автоматически удаляется как дочерний объект
 */
UniversityViewModel::~UniversityViewModel()
{
    // DatabaseManager будет удален автоматически как дочерний объект
}

/**
 * @brief Подключение к базе данных
 * @return bool Результат подключения
 */
bool UniversityViewModel::connectToDatabase()
{
    return m_dbManager->connectToDatabase();
}

/**
 * @brief Проверка состояния подключения к БД
 * @return bool Состояние подключения
 */
bool UniversityViewModel::isConnected() const
{
    return m_dbManager->isConnected();
}

/**
 * @brief Получение списка преподавателей
 * @return QStringList Список преподавателей
 */
QStringList UniversityViewModel::teachers() const
{
    return m_teachers;
}

/**
 * @brief Получение списка студентов
 * @return QStringList Список студентов
 */
QStringList UniversityViewModel::students() const
{
    return m_students;
}

/**
 * @brief Получение списка предметов
 * @return QStringList Список предметов
 */
QStringList UniversityViewModel::subjects() const
{
    return m_subjects;
}

/**
 * @brief Получение общего количества записей
 * @return int Количество записей
 */
int UniversityViewModel::totalRecords() const
{
    return m_teachers.size() + m_students.size() + m_subjects.size();
}

/**
 * @brief Обновление списка преподавателей
 * 
 * @details Загружает данные из БД и преобразует в строковый формат
 */
void UniversityViewModel::updateTeachers()
{
    QList<Teacher*> teacherList = m_dbManager->getAllTeachers();
    m_teachers.clear();
    
    for (Teacher *teacher : teacherList) {
        m_teachers.append(teacher->toString());
        teacher->deleteLater(); // Очистка памяти
    }
}

/**
 * @brief Обновление списка студентов
 * 
 * @details Загружает данные из БД и преобразует в строковый формат
 */
void UniversityViewModel::updateStudents()
{
    QList<Student*> studentList = m_dbManager->getAllStudents();
    m_students.clear();
    
    for (Student *student : studentList) {
        m_students.append(student->toString());
        student->deleteLater(); // Очистка памяти
    }
}

/**
 * @brief Обновление списка предметов
 * 
 * @details Загружает данные из БД и преобразует в строковый формат
 */
void UniversityViewModel::updateSubjects()
{
    QList<Subject*> subjectList = m_dbManager->getAllSubjects();
    m_subjects.clear();
    
    for (Subject *subject : subjectList) {
        m_subjects.append(subject->toString());
        subject->deleteLater(); // Очистка памяти
    }
}

/**
 * @brief Добавление преподавателя
 * @param name Имя преподавателя
 * @param department Кафедра
 * @return bool Результат операции
 */
bool UniversityViewModel::addTeacher(const QString &name, const QString &department)
{
    if (name.isEmpty() || department.isEmpty()) {
        emit errorOccurred("Имя и кафедра не могут быть пустыми");
        return false;
    }
    
    bool success = m_dbManager->addTeacher(name, department);
    if (success) {
        qDebug() << "Преподаватель добавлен:" << name;
        refresh();
    } else {
        emit errorOccurred("Не удалось добавить преподавателя");
    }
    return success;
}

/**
 * @brief Добавление студента
 * @param name Имя студента
 * @param grade Оценка
 * @return bool Результат операции
 */
bool UniversityViewModel::addStudent(const QString &name, int grade)
{
    if (name.isEmpty()) {
        emit errorOccurred("Имя не может быть пустым");
        return false;
    }
    
    if (grade < 1 || grade > 5) {
        emit errorOccurred("Оценка должна быть от 1 до 5");
        return false;
    }
    
    bool success = m_dbManager->addStudent(name, grade);
    if (success) {
        qDebug() << "Студент добавлен:" << name;
        refresh();
    } else {
        emit errorOccurred("Не удалось добавить студента");
    }
    return success;
}

/**
 * @brief Добавление предмета
 * @param name Название предмета
 * @return bool Результат операции
 */
bool UniversityViewModel::addSubject(const QString &name)
{
    if (name.isEmpty()) {
        emit errorOccurred("Название предмета не может быть пустым");
        return false;
    }
    
    bool success = m_dbManager->addSubject(name);
    if (success) {
        qDebug() << "Предмет добавлен:" << name;
        refresh();
    } else {
        emit errorOccurred("Не удалось добавить предмет");
    }
    return success;
}

/**
 * @brief Удаление преподавателя
 * @param id Идентификатор преподавателя
 * @return bool Результат операции
 */
bool UniversityViewModel::deleteTeacher(int id)
{
    bool success = m_dbManager->deleteTeacher(id);
    if (success) {
        qDebug() << "Преподаватель удален, ID:" << id;
        refresh();
    } else {
        emit errorOccurred("Не удалось удалить преподавателя");
    }
    return success;
}

/**
 * @brief Удаление студента
 * @param id Идентификатор студента
 * @return bool Результат операции
 */
bool UniversityViewModel::deleteStudent(int id)
{
    bool success = m_dbManager->deleteStudent(id);
    if (success) {
        qDebug() << "Студент удален, ID:" << id;
        refresh();
    } else {
        emit errorOccurred("Не удалось удалить студента");
    }
    return success;
}

/**
 * @brief Удаление предмета
 * @param id Идентификатор предмета
 * @return bool Результат операции
 */
bool UniversityViewModel::deleteSubject(int id)
{
    bool success = m_dbManager->deleteSubject(id);
    if (success) {
        qDebug() << "Предмет удален, ID:" << id;
        refresh();
    } else {
        emit errorOccurred("Не удалось удалить предмет");
    }
    return success;
}

/**
 * @brief Обновление всех данных
 * 
 * @details Загружает актуальные данные из всех таблиц БД
 * и обновляет соответствующие списки
 */
void UniversityViewModel::refresh()
{
    if (!m_dbManager->isConnected()) {
        return;
    }
    
    updateTeachers();
    updateStudents();
    updateSubjects();
    
    emit dataChanged();
    qDebug() << "Данные обновлены. Всего записей:" << totalRecords();
}