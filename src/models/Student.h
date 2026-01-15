/**
 * @file Student.h
 * @brief Заголовочный файл класса Student
 * @ingroup Models
 * 
 * @class Student
 * @brief Класс, представляющий студента в системе
 * 
 * Содержит информацию о студенте:
 * - Идентификатор
 * - Полное имя
 * - Оценку (1-5)
 * 
 * @property int Student::id
 * @brief Идентификатор студента
 * 
 * @property QString Student::fullName  
 * @brief Полное имя студента
 * 
 * @property int Student::grade
 * @brief Оценка студента (должна быть в диапазоне 1-5)
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class Student : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString fullName READ fullName WRITE setFullName NOTIFY fullNameChanged)
    Q_PROPERTY(int grade READ grade WRITE setGrade NOTIFY gradeChanged)
    
public:
    /**
     * @brief Конструктор по умолчанию
     * @param parent Родительский QObject
     */
    explicit Student(QObject *parent = nullptr);
    
    /**
     * @brief Параметризованный конструктор
     * @param id Идентификатор студента
     * @param fullName Полное имя студента
     * @param grade Оценка студента
     * @param parent Родительский QObject
     */
    Student(int id, const QString &fullName, int grade, QObject *parent = nullptr);
    
    /**
     * @brief Получить идентификатор студента
     * @return int Идентификатор
     */
    int id() const;
    
    /**
     * @brief Установить идентификатор студента
     * @param id Новый идентификатор
     */
    void setId(int id);
    
    /**
     * @brief Получить полное имя студента
     * @return QString Полное имя
     */
    QString fullName() const;
    
    /**
     * @brief Установить полное имя студента
     * @param fullName Новое полное имя
     */
    void setFullName(const QString &fullName);
    
    /**
     * @brief Получить оценку студента
     * @return int Оценка (1-5)
     */
    int grade() const;
    
    /**
     * @brief Установить оценку студента
     * @param grade Новая оценка
     * @warning Оценка должна быть в диапазоне 1-5
     */
    void setGrade(int grade);
    
    /**
     * @brief Преобразовать объект в строковое представление
     * @return QString Строка в формате "ID. Имя (Оценка: X)"
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
     * @brief Сигнал об изменении оценки
     */
    void gradeChanged();
    
private:
    int m_id;           ///< Идентификатор студента
    QString m_fullName; ///< Полное имя студента
    int m_grade;        ///< Оценка студента
};

#endif // STUDENT_H