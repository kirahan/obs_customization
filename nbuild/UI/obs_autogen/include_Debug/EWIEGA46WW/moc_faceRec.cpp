/****************************************************************************
** Meta object code from reading C++ file 'faceRec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../UI/faceRec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'faceRec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FaceRec_t {
    QByteArrayData data[11];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FaceRec_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FaceRec_t qt_meta_stringdata_FaceRec = {
    {
QT_MOC_LITERAL(0, 0, 7), // "FaceRec"
QT_MOC_LITERAL(1, 8, 14), // "ShowTheCapture"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "SavePicture"
QT_MOC_LITERAL(4, 36, 12), // "displayImage"
QT_MOC_LITERAL(5, 49, 5), // "image"
QT_MOC_LITERAL(6, 55, 23), // "on_cameraType_activated"
QT_MOC_LITERAL(7, 79, 5), // "index"
QT_MOC_LITERAL(8, 85, 13), // "finishRequest"
QT_MOC_LITERAL(9, 99, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 114, 4) // "Exit"

    },
    "FaceRec\0ShowTheCapture\0\0SavePicture\0"
    "displayImage\0image\0on_cameraType_activated\0"
    "index\0finishRequest\0QNetworkReply*\0"
    "Exit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FaceRec[] = {

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

void FaceRec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FaceRec *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject FaceRec::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_FaceRec.data,
    qt_meta_data_FaceRec,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FaceRec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FaceRec::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FaceRec.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FaceRec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
