/**
 * @file Student.cpp
 * @brief Реализация класса Student
 * @ingroup Models
 */

#include "Student.h"

/**
 * @brief Конструктор по умолчанию
 * @param parent Родительский QObject
 */
Student::Student(QObject *parent) 
    : QObject(parent), m_id(0), m_grade(0)
{
}

/**
 * @brief Параметризованный конструктор
 * @param id Идентификатор студента
 * @param fullName Полное имя студента
 * @param grade Оценка студента
 * @param parent Родительский QObject
 */
Student::Student(int id, const QString &fullName, int grade, QObject *parent)
    : QObject(parent), m_id(id), m_fullName(fullName), m_grade(grade)
{
}

/**
 * @brief Получить идентификатор студента
 * @return int Идентификатор
 */
int Student::id() const
{
    return m_id;
}

/**
 * @brief Установить идентификатор студента
 * @param id Новый идентификатор
 */
void Student::setId(int id)
{
    if (m_id != id) {
        m_id = id;
        emit idChanged();
    }
}

/**
 * @brief Получить полное имя студента
 * @return QString Полное имя
 */
QString Student::fullName() const
{
    return m_fullName;
}

/**
 * @brief Установить полное имя студента
 * @param fullName Новое полное имя
 */
void Student::setFullName(const QString &fullName)
{
    if (m_fullName != fullName) {
        m_fullName = fullName;
        emit fullNameChanged();
    }
}

/**
 * @brief Получить оценку студента
 * @return int Оценка
 */
int Student::grade() const
{
    return m_grade;
}

/**
 * @brief Установить оценку студента
 * @param grade Новая оценка
 */
void Student::setGrade(int grade)
{
    if (m_grade != grade) {
        m_grade = grade;
        emit gradeChanged();
    }
}

/**
 * @brief Преобразовать объект в строковое представление
 * @return QString Строка формата "ID. Имя (Оценка: X)"
 */
QString Student::toString() const
{
    return QString("%1. %2 (Оценка: %3)").arg(m_id).arg(m_fullName).arg(m_grade);
}