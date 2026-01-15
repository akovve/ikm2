/**
 * @file main.cpp
 * @brief Главный файл приложения University Database Management System
 * @mainpage University Database Management System
 * 
 * @section intro_sec Введение
 * Приложение для управления базой данных университета с использованием Qt, QML и PostgreSQL.
 * Предоставляет интерфейс для работы с преподавателями, студентами и предметами.
 * 
 * @section arch_sec Архитектура
 * Приложение использует паттерн MVVM (Model-View-ViewModel):
 * - Модели: Teacher, Student, Subject
 * - ViewModel: UniversityViewModel
 * - Представление: QML интерфейс
 * 
 * @section features_sec Основные возможности
 * - Просмотр списков преподавателей, студентов и предметов
 * - Добавление новых записей
 * - Удаление существующих записей
 * - Подключение к PostgreSQL базе данных
 * - Автоматическое обновление интерфейса при изменении данных
 */

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "src/viewmodels/UniversityViewModel.h"

/**
 * @brief Точка входа в приложение University Database
 * 
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return int Код завершения приложения:
 *             - 0: Успешное завершение
 *             - -1: Ошибка загрузки QML интерфейса
 * 
 * @details Выполняет инициализацию приложения:
 * 1. Создает объект QApplication
 * 2. Регистрирует типы для QML
 * 3. Создает ViewModel
 * 4. Регистрирует ViewModel в QML контексте
 * 5. Загружает QML интерфейс
 * 6. Запускает главный цикл приложения
 * 
 * @note Для корректной работы требуется:
 * - Установленный PostgreSQL
 * - База данных "university"
 * - Таблицы teachers, students, subjects
 */
int main(int argc, char *argv[])
{
    // Инициализация Qt приложения
    QApplication app(argc, argv);
    
    // Регистрируем типы для QML
    qmlRegisterType<UniversityViewModel>("UniversityDB", 1, 0, "UniversityViewModel");
    
    // Создаем ViewModel
    UniversityViewModel viewModel;
    
    // Создаем QML движок
    QQmlApplicationEngine engine;
    
    // Регистрируем объект ViewModel в QML
    engine.rootContext()->setContextProperty("viewModel", &viewModel);
    
    // Загружаем QML файл
    engine.load(QUrl::fromLocalFile("main.qml"));
    
    if (engine.rootObjects().isEmpty()) {
        qCritical() << "❌ Не удалось загрузить QML интерфейс!";
        return -1;
    }
    
    qDebug() << "✅ Приложение запущено успешно!";
    return app.exec();
}