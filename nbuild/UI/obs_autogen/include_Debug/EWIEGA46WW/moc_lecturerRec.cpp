/****************************************************************************
** Meta object code from reading C++ file 'lecturerRec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../UI/lecturerRec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecturerRec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Lectrrerrec_t {
    QByteArrayData data[11];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Lectrrerrec_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Lectrrerrec_t qt_meta_stringdata_Lectrrerrec = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Lectrrerrec"
QT_MOC_LITERAL(1, 12, 14), // "ShowTheCapture"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "SavePicture"
QT_MOC_LITERAL(4, 40, 12), // "displayImage"
QT_MOC_LITERAL(5, 53, 5), // "image"
QT_MOC_LITERAL(6, 59, 23), // "on_cameraType_activated"
QT_MOC_LITERAL(7, 83, 5), // "index"
QT_MOC_LITERAL(8, 89, 13), // "finishRequest"
QT_MOC_LITERAL(9, 103, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 118, 4) // "Exit"

    },
    "Lectrrerrec\0ShowTheCapture\0\0SavePicture\0"
    "displayImage\0image\0on_cameraType_activated\0"
    "index\0finishRequest\0QNetworkReply*\0"
    "Exit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Lectrrerrec[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    2,   46,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,
       8,    1,   54,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    2,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,

       0        // eod
};

void Lectrrerrec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Lectrrerrec *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowTheCapture(); break;
        case 1: _t->SavePicture(); break;
        case 2: _t->displayImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 3: _t->on_cameraType_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->finishRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->Exit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Lectrrerrec::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Lectrrerrec.data,
    qt_meta_data_Lectrrerrec,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Lectrrerrec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Lectrrerrec::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Lectrrerrec.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Lectrrerrec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
