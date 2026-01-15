/**
 * @file Subject.h
 * @brief Заголовочный файл класса Subject
 * @ingroup Models
 * 
 * @class Subject
 * @brief Класс, представляющий учебный предмет в системе
 * 
 * Содержит информацию о предмете:
 * - Идентификатор
 * - Название предмета
 * 
 * @property int Subject::id
 * @brief Идентификатор предмета
 * 
 * @property QString Subject::name
 * @brief Название предмета
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <QString>

class Subject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    
public:
    /**
     * @brief Конструктор по умолчанию
     * @param parent Родительский QObject
     */
    explicit Subject(QObject *parent = nullptr);
    
    /**
     * @brief Параметризованный конструктор
     * @param id Идентификатор предмета
     * @param name Название предмета
     * @param parent Родительский QObject
     */
    Subject(int id, const QString &name, QObject *parent = nullptr);
    
    /**
     * @brief Получить идентификатор предмета
     * @return int Идентификатор
     */
    int id() const;
    
    /**
     * @brief Установить идентификатор предмета
     * @param id Новый идентификатор
     */
    void setId(int id);
    
    /**
     * @brief Получить название предмета
     * @return QString Название
     */
    QString name() const;
    
    /**
     * @brief Установить название предмета
     * @param name Новое название
     */
    void setName(const QString &name);
    
    /**
     * @brief Преобразовать объект в строковое представление
     * @return QString Строка в формате "ID. Название"
     */
    QString toString() const;
    
signals:
    /**
     * @brief Сигнал об изменении идентификатора
     */
    void idChanged();
    
    /**
     * @brief Сигнал об изменении названия
     */
    void nameChanged();
    
private:
    int m_id;       ///< Идентификатор предмета
    QString m_name; ///< Название предмета
};

#endif // SUBJECT_H