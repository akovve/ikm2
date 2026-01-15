/****************************************************************************
** Meta object code from reading C++ file 'UniversityViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewmodels/UniversityViewModel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UniversityViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN19UniversityViewModelE_t {};
} // unnamed namespace

template <> constexpr inline auto UniversityViewModel::qt_create_metaobjectdata<qt_meta_tag_ZN19UniversityViewModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "UniversityViewModel",
        "dataChanged",
        "",
        "connectionChanged",
        "errorOccurred",
        "message",
        "addTeacher",
        "name",
        "department",
        "addStudent",
        "grade",
        "addSubject",
        "deleteTeacher",
        "id",
        "deleteStudent",
        "deleteSubject",
        "refresh",
        "connectToDatabase",
        "teachers",
        "students",
        "subjects",
        "totalRecords",
        "isConnected"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dataChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connectionChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Method 'addTeacher'
        QtMocHelpers::MethodData<bool(const QString &, const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
        }}),
        // Method 'addStudent'
        QtMocHelpers::MethodData<bool(const QString &, int)>(9, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { QMetaType::Int, 10 },
        }}),
        // Method 'addSubject'
        QtMocHelpers::MethodData<bool(const QString &)>(11, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'deleteTeacher'
        QtMocHelpers::MethodData<bool(int)>(12, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 13 },
        }}),
        // Method 'deleteStudent'
        QtMocHelpers::MethodData<bool(int)>(14, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 13 },
        }}),
        // Method 'deleteSubject'
        QtMocHelpers::MethodData<bool(int)>(15, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 13 },
        }}),
        // Method 'refresh'
        QtMocHelpers::MethodData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'connectToDatabase'
        QtMocHelpers::MethodData<bool()>(17, 2, QMC::AccessPublic, QMetaType::Bool),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'teachers'
        QtMocHelpers::PropertyData<QStringList>(18, QMetaType::QStringList, QMC::DefaultPropertyFlags, 0),
        // property 'students'
        QtMocHelpers::PropertyData<QStringList>(19, QMetaType::QStringList, QMC::DefaultPropertyFlags, 0),
        // property 'subjects'
        QtMocHelpers::PropertyData<QStringList>(20, QMetaType::QStringList, QMC::DefaultPropertyFlags, 0),
        // property 'totalRecords'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'isConnected'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<UniversityViewModel, qt_meta_tag_ZN19UniversityViewModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject UniversityViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19UniversityViewModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19UniversityViewModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19UniversityViewModelE_t>.metaTypes,
    nullptr
} };

void UniversityViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UniversityViewModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->connectionChanged(); break;
        case 2: _t->errorOccurred((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { bool _r = _t->addTeacher((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->addStudent((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->addSubject((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->deleteTeacher((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->deleteStudent((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->deleteSubject((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->refresh(); break;
        case 10: { bool _r = _t->connectToDatabase();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UniversityViewModel::*)()>(_a, &UniversityViewModel::dataChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (UniversityViewModel::*)()>(_a, &UniversityViewModel::connectionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (UniversityViewModel::*)(const QString & )>(_a, &UniversityViewModel::errorOccurred, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->teachers(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->students(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->subjects(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->totalRecords(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isConnected(); break;
        default: break;
        }
    }
}

const QMetaObject *UniversityViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UniversityViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19UniversityViewModelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UniversityViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UniversityViewModel::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UniversityViewModel::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UniversityViewModel::errorOccurred(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
