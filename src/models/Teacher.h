/**
 * @file Teacher.h
 * @brief Заголовочный файл класса Teacher
 * @ingroup Models
 * 
 * @class Teacher
 * @brief Класс, представляющий преподавателя в системе
 * 
 * Содержит информацию о преподавателе:
 * - Идентификатор
 * - Полное имя
 * - Кафедру
 * 
 * @property int Teacher::id
 * @brief Идентификатор преподавателя
 * 
 * @property QString Teacher::fullName
 * @brief Полное имя преподавателя
 * 
 * @property QString Teacher::department
 * @brief Кафедра преподавателя
 */

#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class Teacher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString fullName READ fullName WRITE setFullName NOTIFY fullNameChanged)
    Q_PROPERTY(QString department READ department WRITE setDepartment NOTIFY departmentChanged)
    
public:
    /**
     * @brief Конструктор по умолчанию
     * @param parent Родительский QObject
     */
    explicit Teacher(QObject *parent = nullptr);
    
    /**
     * @brief Параметризованный конструктор
     * @param id Идентификатор преподавателя
     * @param fullName Полное имя преподавателя
     * @param department Кафедра преподавателя
     * @param parent Родительский QObject
     */
    Teacher(int id, const QString &fullName, const QString &department, QObject *parent = nullptr);
    
    /**
     * @brief Получить идентификатор преподавателя
     * @return int Идентификатор
     */
    int id() const;
    
    /**
     * @brief Установить идентификатор преподавателя
     * @param id Новый идентификатор
     */
    void setId(int id);
    
    /**
     * @brief Получить полное имя преподавателя
     * @return QString Полное имя
     */
    QString fullName() const;
    
    /**
     * @brief Установить полное имя преподавателя
     * @param fullName Новое полное имя
     */
    void setFullName(const QString &fullName);
    
    /**
     * @brief Получить кафедру преподавателя
     * @return QString Кафедра
     */
    QString department() const;
    
    /**
     * @brief Установить кафедру преподавателя
     * @param department Новая кафедра
     */
    void setDepartment(const QString &department);
    
    /**
     * @brief Преобразовать объект в строковое представление
     * @return QString Строка в формате "ID. Имя (Кафедра)"
     */
    QString toString() const;
    
signals:
    /**
     * @brief Сигнал об изменении идентификатора
     */
    void idChanged();
    
    /**
     * @brief Сигнал об изменении имени
     */
    void fullNameChanged();
    
    /**
     * @brief Сигнал об изменении кафедры
     */
    void departmentChanged();
    
private:
    int m_id;               ///< Идентификатор преподавателя
    QString m_fullName;     ///< Полное имя преподавателя
    QString m_department;   ///< Кафедра преподавателя
};

#endif // TEACHER_H