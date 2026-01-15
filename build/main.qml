import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import UniversityDB 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1000
    height: 750
    title: "University Database (OOP)"
    color: "#f5f5f5"
    
    // Переменная для текущей вкладки
    property int currentTab: 0
    
    // Функция для обновления всех данных
    function refreshAll() {
        viewModel.refresh()
        console.log("Данные обновлены")
    }
    
    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        
        // Шапка
        Rectangle {
            Layout.fillWidth: true
            height: 70
            color: viewModel.isConnected ? "#3498db" : "#e74c3c"
            
            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                
                Text {
                    text: "🎓 University Database (OOP)"
                    color: "white"
                    font.pixelSize: 24
                    font.bold: true
                }
                
                Item { Layout.fillWidth: true }
                
                Rectangle {
                    width: 120
                    height: 30
                    color: viewModel.isConnected ? "#27ae60" : "#e74c3c"
                    radius: 4
                    
                    Text {
                        anchors.centerIn: parent
                        text: viewModel.isConnected ? "PostgreSQL ✅" : "PostgreSQL ❌"
                        color: "white"
                        font.bold: true
                        font.pixelSize: 12
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: viewModel.connectToDatabase()
                    }
                }
            }
        }
        
        // Панель вкладок
        RowLayout {
            Layout.fillWidth: true
            height: 50
            spacing: 1
            
            // Кнопка вкладки Преподаватели
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: currentTab === 0 ? "#2980b9" : "#3498db"
                
                Text {
                    anchors.centerIn: parent
                    text: "👨‍🏫 Преподаватели"
                    color: "white"
                    font.bold: true
                }
                
                MouseArea {
                    anchors.fill: parent
                    onClicked: currentTab = 0
                }
            }
            
            // Кнопка вкладки Студенты
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: currentTab === 1 ? "#2980b9" : "#3498db"
                
                Text {
                    anchors.centerIn: parent
                    text: "👨‍🎓 Студенты"
                    color: "white"
                    font.bold: true
                }
                
                MouseArea {
                    anchors.fill: parent
                    onClicked: currentTab = 1
                }
            }
            
            // Кнопка вкладки Предметы
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: currentTab === 2 ? "#2980b9" : "#3498db"
                
                Text {
                    anchors.centerIn: parent
                    text: "📚 Предметы"
                    color: "white"
                    font.bold: true
                }
                
                MouseArea {
                    anchors.fill: parent
                    onClicked: currentTab = 2
                }
            }
        }
        
        // Контент вкладок
        StackLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: currentTab
            
            // Вкладка 1: Преподаватели
            ColumnLayout {
                spacing: 15
                anchors.margins: 20
                
                // Форма добавления
                Rectangle {
                    Layout.fillWidth: true
                    height: 140
                    color: "white"
                    border.color: "#ddd"
                    radius: 8
                    
                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        
                        Text {
                            text: "Добавить нового преподавателя:"
                            font.bold: true
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            TextField {
                                id: teacherNameInput
                                placeholderText: "ФИО преподавателя"
                                Layout.fillWidth: true
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                            }
                            
                            TextField {
                                id: teacherDeptInput
                                placeholderText: "Кафедра"
                                Layout.fillWidth: true
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                            }
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            Button {
                                text: "➕ Добавить"
                                font.bold: true
                                padding: 10
                                enabled: teacherNameInput.text && teacherDeptInput.text
                                onClicked: {
                                    var success = viewModel.addTeacher(teacherNameInput.text, teacherDeptInput.text)
                                    if (success) {
                                        teacherNameInput.text = ""
                                        teacherDeptInput.text = ""
                                    }
                                }
                            }
                            
                            Button {
                                text: "🗑️ Удалить по ID"
                                font.bold: true
                                padding: 10
                                
                                background: Rectangle {
                                    color: "#e74c3c"
                                    radius: 4
                                }
                                
                                contentItem: Text {
                                    text: parent.text
                                    color: "white"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                                
                                onClicked: {
                                    if (deleteTeacherIdInput.text) {
                                        var id = parseInt(deleteTeacherIdInput.text)
                                        viewModel.deleteTeacher(id)
                                        deleteTeacherIdInput.text = ""
                                    }
                                }
                            }
                            
                            TextField {
                                id: deleteTeacherIdInput
                                placeholderText: "ID для удаления"
                                Layout.preferredWidth: 100
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                                validator: IntValidator { bottom: 1 }
                            }
                        }
                    }
                }
                
                // Список преподавателей
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    border.color: "#ddd"
                    radius: 8
                    
                    ColumnLayout {
                        anchors.fill: parent
                        
                        Text {
                            text: "Список преподавателей:"
                            font.bold: true
                            color: "#2c3e50"
                            font.pixelSize: 16
                            Layout.topMargin: 15
                            Layout.leftMargin: 15
                        }
                        
                        ListView {
                            id: teachersList
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            model: viewModel.teachers
                            clip: true
                            spacing: 1
                            
                            delegate: Rectangle {
                                width: ListView.view.width
                                height: 50
                                color: index % 2 === 0 ? "#ffffff" : "#f8f9fa"
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.leftMargin: 15
                                    anchors.rightMargin: 15
                                    
                                    Text {
                                        text: modelData
                                        color: "#2c3e50"
                                        font.pixelSize: 14
                                        Layout.fillWidth: true
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            // Вкладка 2: Студенты
            ColumnLayout {
                spacing: 15
                anchors.margins: 20
                
                // Форма добавления
                Rectangle {
                    Layout.fillWidth: true
                    height: 140
                    color: "white"
                    border.color: "#ddd"
                    radius: 8
                    
                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        
                        Text {
                            text: "Добавить нового студента:"
                            font.bold: true
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            TextField {
                                id: studentNameInput
                                placeholderText: "ФИО студента"
                                Layout.fillWidth: true
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                            }
                            
                            TextField {
                                id: studentGradeInput
                                placeholderText: "Оценка (1-5)"
                                Layout.preferredWidth: 120
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                                validator: IntValidator { bottom: 1; top: 5 }
                            }
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            Button {
                                text: "➕ Добавить"
                                font.bold: true
                                padding: 10
                                enabled: studentNameInput.text && studentGradeInput.text
                                onClicked: {
                                    var grade = parseInt(studentGradeInput.text)
                                    if (grade >= 1 && grade <= 5) {
                                        var success = viewModel.addStudent(studentNameInput.text, grade)
                                        if (success) {
                                            studentNameInput.text = ""
                                            studentGradeInput.text = ""
                                        }
                                    }
                                }
                            }
                            
                            Button {
                                text: "🗑️ Удалить по ID"
                                font.bold: true
                                padding: 10
                                
                                background: Rectangle {
                                    color: "#e74c3c"
                                    radius: 4
                                }
                                
                                contentItem: Text {
                                    text: parent.text
                                    color: "white"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                                
                                onClicked: {
                                    if (deleteStudentIdInput.text) {
                                        var id = parseInt(deleteStudentIdInput.text)
                                        viewModel.deleteStudent(id)
                                        deleteStudentIdInput.text = ""
                                    }
                                }
                            }
                            
                            TextField {
                                id: deleteStudentIdInput
                                placeholderText: "ID для удаления"
                                Layout.preferredWidth: 100
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                                validator: IntValidator { bottom: 1 }
                            }
                        }
                    }
                }
                
                // Список студентов
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    border.color: "#ddd"
                    radius: 8
                    
                    ColumnLayout {
                        anchors.fill: parent
                        
                        Text {
                            text: "Список студентов:"
                            font.bold: true
                            color: "#2c3e50"
                            font.pixelSize: 16
                            Layout.topMargin: 15
                            Layout.leftMargin: 15
                        }
                        
                        ListView {
                            id: studentsList
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            model: viewModel.students
                            clip: true
                            spacing: 1
                            
                            delegate: Rectangle {
                                width: ListView.view.width
                                height: 50
                                color: index % 2 === 0 ? "#ffffff" : "#f8f9fa"
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.leftMargin: 15
                                    anchors.rightMargin: 15
                                    
                                    Text {
                                        text: modelData
                                        color: "#2c3e50"
                                        font.pixelSize: 14
                                        Layout.fillWidth: true
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            // Вкладка 3: Предметы
            ColumnLayout {
                spacing: 15
                anchors.margins: 20
                
                // Форма добавления
                Rectangle {
                    Layout.fillWidth: true
                    height: 140
                    color: "white"
                    border.color: "#ddd"
                    radius: 8
                    
                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        
                        Text {
                            text: "Добавить новый предмет:"
                            font.bold: true
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            TextField {
                                id: subjectNameInput
                                placeholderText: "Название предмета"
                                Layout.fillWidth: true
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                            }
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            Button {
                                text: "➕ Добавить"
                                font.bold: true
                                padding: 10
                                enabled: subjectNameInput.text
                                onClicked: {
                                    var success = viewModel.addSubject(subjectNameInput.text)
                                    if (success) {
                                        subjectNameInput.text = ""
                                    }
                                }
                            }
                            
                            Button {
                                text: "🗑️ Удалить по ID"
                                font.bold: true
                                padding: 10
                                
                                background: Rectangle {
                                    color: "#e74c3c"
                                    radius: 4
                                }
                                
                                contentItem: Text {
                                    text: parent.text
                                    color: "white"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                                
                                onClicked: {
                                    if (deleteSubjectIdInput.text) {
                                        var id = parseInt(deleteSubjectIdInput.text)
                                        viewModel.deleteSubject(id)
                                        deleteSubjectIdInput.text = ""
                                    }
                                }
                            }
                            
                            TextField {
                                id: deleteSubjectIdInput
                                placeholderText: "ID для удаления"
                                Layout.preferredWidth: 100
                                font.pixelSize: 14
                                padding: 10
                                color: "black"
                                background: Rectangle {
                                    color: "white"
                                    border.color: "#ccc"
                                    border.width: 1
                                    radius: 4
                                }
                                validator: IntValidator { bottom: 1 }
                            }
                        }
                    }
                }
                
                // Список предметов
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    border.color: "#ddd"
                    radius: 8
                    
                    ColumnLayout {
                        anchors.fill: parent
                        
                        Text {
                            text: "Список предметов:"
                            font.bold: true
                            color: "#2c3e50"
                            font.pixelSize: 16
                            Layout.topMargin: 15
                            Layout.leftMargin: 15
                        }
                        
                        ListView {
                            id: subjectsList
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            model: viewModel.subjects
                            clip: true
                            spacing: 1
                            
                            delegate: Rectangle {
                                width: ListView.view.width
                                height: 50
                                color: index % 2 === 0 ? "#ffffff" : "#f8f9fa"
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.leftMargin: 15
                                    anchors.rightMargin: 15
                                    
                                    Text {
                                        text: modelData
                                        color: "#2c3e50"
                                        font.pixelSize: 14
                                        Layout.fillWidth: true
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        // Статус бар
        Rectangle {
            Layout.fillWidth: true
            height: 40
            color: "#2c3e50"
            
            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                
                Text {
                    text: "University Database v3.0 (OOP)"
                    color: "#bdc3c7"
                    font.pixelSize: 11
                }
                
                Item { Layout.fillWidth: true }
                
                Button {
                    text: "🔄 Обновить все"
                    onClicked: refreshAll()
                }
                
                Text {
                    text: "Записей: " + viewModel.totalRecords
                    color: "white"
                    font.bold: true
                    Layout.leftMargin: 10
                }
            }
        }
    }
    
    // При запуске обновляем данные
    Component.onCompleted: {
        console.log("Приложение запущено!")
        refreshAll()
    }
}