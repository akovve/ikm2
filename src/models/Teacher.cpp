/**
 * @file Teacher.cpp
 * @brief Реализация класса Teacher
 * @ingroup Models
 */

#include "Teacher.h"

/**
 * @brief Конструктор по умолчанию
 * @param parent Родительский QObject
 */
Teacher::Teacher(QObject *parent) 
    : QObject(parent), m_id(0)
{
}

/**
 * @brief Параметризованный конструктор
 * @param id Идентификатор преподавателя
 * @param fullName Полное имя преподавателя
 * @param department Кафедра преподавателя
 * @param parent Родительский QObject
 */
Teacher::Teacher(int id, const QString &fullName, const QString &department, QObject *parent)
    : QObject(parent), m_id(id), m_fullName(fullName), m_department(department)
{
}

/**
 * @brief Получить идентификатор преподавателя
 * @return int Идентификатор
 */
int Teacher::id() const
{
    return m_id;
}

/**
 * @brief Установить идентификатор преподавателя
 * @param id Новый идентификатор
 */
void Teacher::setId(int id)
{
    if (m_id != id) {
        m_id = id;
        emit idChanged();
    }
}

/**
 * @brief Получить полное имя преподавателя
 * @return QString Полное имя
 */
QString Teacher::fullName() const
{
    return m_fullName;
}

/**
 * @brief Установить полное имя преподавателя
 * @param fullName Новое полное имя
 */
void Teacher::setFullName(const QString &fullName)
{
    if (m_fullName != fullName) {
        m_fullName = fullName;
        emit fullNameChanged();
    }
}

/**
 * @brief Получить кафедру преподавателя
 * @return QString Кафедра
 */
QString Teacher::department() const
{
    return m_department;
}

/**
 * @brief Установить кафедру преподавателя
 * @param department Новая кафедра
 */
void Teacher::setDepartment(const QString &department)
{
    if (m_department != department) {
        m_department = department;
        emit departmentChanged();
    }
}

/**
 * @brief Преобразовать объект в строковое представление
 * @return QString Строка формата "ID. Имя (Кафедра)"
 */
QString Teacher::toString() const
{
    return QString("%1. %2 (%3)").arg(m_id).arg(m_fullName).arg(m_department);
}