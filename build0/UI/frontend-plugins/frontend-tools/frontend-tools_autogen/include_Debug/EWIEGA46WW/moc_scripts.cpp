/****************************************************************************
** Meta object code from reading C++ file 'scripts.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scripts.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripts.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScriptLogWindow_t {
    QByteArrayData data[9];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptLogWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptLogWindow_t qt_meta_stringdata_ScriptLogWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ScriptLogWindow"
QT_MOC_LITERAL(1, 16, 9), // "AddLogMsg"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "log_level"
QT_MOC_LITERAL(4, 37, 3), // "msg"
QT_MOC_LITERAL(5, 41, 11), // "ClearWindow"
QT_MOC_LITERAL(6, 53, 5), // "Clear"
QT_MOC_LITERAL(7, 59, 13), // "ScrollChanged"
QT_MOC_LITERAL(8, 73, 3) // "val"

    },
    "ScriptLogWindow\0AddLogMsg\0\0log_level\0"
    "msg\0ClearWindow\0Clear\0ScrollChanged\0"
    "val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptLogWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       5,    0,   39,    2, 0x0a /* Public */,
       6,    0,   40,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ScriptLogWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptLogWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddLogMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ClearWindow(); break;
        case 2: _t->Clear(); break;
        case 3: _t->ScrollChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScriptLogWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ScriptLogWindow.data,
    qt_meta_data_ScriptLogWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScriptLogWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptLogWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptLogWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ScriptLogWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_ScriptsTool_t {
    QByteArrayData data[16];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptsTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptsTool_t qt_meta_stringdata_ScriptsTool = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ScriptsTool"
QT_MOC_LITERAL(1, 12, 16), // "on_close_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_addScripts_clicked"
QT_MOC_LITERAL(4, 52, 24), // "on_removeScripts_clicked"
QT_MOC_LITERAL(5, 77, 24), // "on_reloadScripts_clicked"
QT_MOC_LITERAL(6, 102, 20), // "on_scriptLog_clicked"
QT_MOC_LITERAL(7, 123, 19), // "on_defaults_clicked"
QT_MOC_LITERAL(8, 143, 25), // "OpenScriptParentDirectory"
QT_MOC_LITERAL(9, 169, 28), // "on_scripts_currentRowChanged"
QT_MOC_LITERAL(10, 198, 3), // "row"
QT_MOC_LITERAL(11, 202, 27), // "on_pythonPathBrowse_clicked"
QT_MOC_LITERAL(12, 230, 28), // "on_description_linkActivated"
QT_MOC_LITERAL(13, 259, 4), // "link"
QT_MOC_LITERAL(14, 264, 37), // "on_scripts_customContextMenuR..."
QT_MOC_LITERAL(15, 302, 3) // "pos"

    },
    "ScriptsTool\0on_close_clicked\0\0"
    "on_addScripts_clicked\0on_removeScripts_clicked\0"
    "on_reloadScripts_clicked\0on_scriptLog_clicked\0"
    "on_defaults_clicked\0OpenScriptParentDirectory\0"
    "on_scripts_currentRowChanged\0row\0"
    "on_pythonPathBrowse_clicked\0"
    "on_description_linkActivated\0link\0"
    "on_scripts_customContextMenuRequested\0"
    "pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptsTool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QPoint,   15,

       0        // eod
};

void ScriptsTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptsTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_close_clicked(); break;
        case 1: _t->on_addScripts_clicked(); break;
        case 2: _t->on_removeScripts_clicked(); break;
        case 3: _t->on_reloadScripts_clicked(); break;
        case 4: _t->on_scriptLog_clicked(); break;
        case 5: _t->on_defaults_clicked(); break;
        case 6: _t->OpenScriptParentDirectory(); break;
        case 7: _t->on_scripts_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pythonPathBrowse_clicked(); break;
        case 9: _t->on_description_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_scripts_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScriptsTool::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ScriptsTool.data,
    qt_meta_data_ScriptsTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScriptsTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptsTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptsTool.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ScriptsTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
