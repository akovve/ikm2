## @file CMakeLists.txt
## @brief Конфигурационный файл сборки проекта UniversityDB
## 
## @section overview_sec Обзор
## Этот файл определяет параметры сборки проекта, включая:
## - Версию CMake
## - Стандарт C++
## - Зависимости (Qt6)
## - Исходные файлы
## - Целевой исполняемый файл
## 
## @section deps_sec Зависимости
## - Qt6 Core, Quick, Sql, Widgets
## - Компилятор с поддержкой C++17
## 
## @section usage_sec Использование
## 1. mkdir build && cd build
## 2. cmake ..
## 3. make
## 
## @section macos_sec macOS специфика
## Для macOS создается .app bundle с идентификатором com.university.db

cmake_minimum_required(VERSION 3.16)
## @brief Название проекта
project(UniversityDB)

## @brief Путь к установленной Qt6
set(CMAKE_PREFIX_PATH "/Users/egorshestakov/Qt/6.10.1/macos")

## @brief Использовать стандарт C++17
set(CMAKE_CXX_STANDARD 17)
## @brief Включить автоматическую генерацию MOC файлов
set(CMAKE_AUTOMOC ON)
## @brief Включить текущую директорию в список include
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## @brief Найти и подключить необходимые компоненты Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Quick Sql Widgets)

## @brief Список исходных файлов проекта
set(SOURCE_FILES
    main.cpp
    src/viewmodels/UniversityViewModel.cpp
    src/models/DatabaseManager.cpp
    src/models/Teacher.cpp
    src/models/Student.cpp
    src/models/Subject.cpp
)

## @brief Проверка существования исходных файлов
foreach(file ${SOURCE_FILES})
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
        message(FATAL_ERROR "Файл ${file} не найден в ${CMAKE_CURRENT_SOURCE_DIR}")
    else()
        message(STATUS "✓ Файл ${file} найден")
    endif()
endforeach()

## @brief Создать исполняемый файл
add_executable(university_db ${SOURCE_FILES})

## @brief Установить директории для поиска заголовочных файлов
target_include_directories(university_db PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
    ${CMAKE_CURRENT_SOURCE_DIR}/src/viewmodels
)

## @brief Копировать QML файл в директорию сборки
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.qml")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/main.qml" 
                   "${CMAKE_CURRENT_BINARY_DIR}/main.qml" COPYONLY)
    message(STATUS "✓ main.qml скопирован")
endif()

## @brief Подключить необходимые библиотеки Qt
target_link_libraries(university_db PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Widgets
    Qt6::Sql
)

## @brief Настройки для macOS
if(APPLE)
    set_target_properties(university_db PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.university.db"
        MACOSX_BUNDLE_BUNDLE_NAME "UniversityDB"
    )
endif()