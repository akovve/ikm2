/**
 * @file Subject.cpp
 * @brief Реализация класса Subject
 * @ingroup Models
 */

#include "Subject.h"

/**
 * @brief Конструктор по умолчанию
 * @param parent Родительский QObject
 */
Subject::Subject(QObject *parent) 
    : QObject(parent), m_id(0)
{
}

/**
 * @brief Параметризованный конструктор
 * @param id Идентификатор предмета
 * @param name Название предмета
 * @param parent Родительский QObject
 */
Subject::Subject(int id, const QString &name, QObject *parent)
    : QObject(parent), m_id(id), m_name(name)
{
}

/**
 * @brief Получить идентификатор предмета
 * @return int Идентификатор
 */
int Subject::id() const
{
    return m_id;
}

/**
 * @brief Установить идентификатор предмета
 * @param id Новый идентификатор
 */
void Subject::setId(int id)
{
    if (m_id != id) {
        m_id = id;
        emit idChanged();
    }
}

/**
 * @brief Получить название предмета
 * @return QString Название
 */
QString Subject::name() const
{
    return m_name;
}

/**
 * @brief Установить название предмета
 * @param name Новое название
 */
void Subject::setName(const QString &name)
{
    if (m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

/**
 * @brief Преобразовать объект в строковое представление
 * @return QString Строка формата "ID. Название"
 */
QString Subject::toString() const
{
    return QString("%1. %2").arg(m_id).arg(m_name);
}