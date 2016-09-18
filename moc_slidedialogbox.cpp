/****************************************************************************
** Meta object code from reading C++ file 'slidedialogbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "slidedialogbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slidedialogbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SlideDialogBox_t {
    QByteArrayData data[21];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlideDialogBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlideDialogBox_t qt_meta_stringdata_SlideDialogBox = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SlideDialogBox"
QT_MOC_LITERAL(1, 15, 16), // "changeMassCenter"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "massCenter"
QT_MOC_LITERAL(4, 44, 15), // "changeRectAngle"
QT_MOC_LITERAL(5, 60, 9), // "rectAngle"
QT_MOC_LITERAL(6, 70, 24), // "changePJointConnectingId"
QT_MOC_LITERAL(7, 95, 19), // "_pJointConnectingId"
QT_MOC_LITERAL(8, 115, 15), // "changeRectColor"
QT_MOC_LITERAL(9, 131, 9), // "rectColor"
QT_MOC_LITERAL(10, 141, 9), // "okClicked"
QT_MOC_LITERAL(11, 151, 12), // "colorClicked"
QT_MOC_LITERAL(12, 164, 14), // "setButtonColor"
QT_MOC_LITERAL(13, 179, 6), // "_color"
QT_MOC_LITERAL(14, 186, 18), // "getIdListFromSlide"
QT_MOC_LITERAL(15, 205, 14), // "std::list<int>"
QT_MOC_LITERAL(16, 220, 7), // "_idList"
QT_MOC_LITERAL(17, 228, 10), // "getSlideId"
QT_MOC_LITERAL(18, 239, 8), // "_slideId"
QT_MOC_LITERAL(19, 248, 15), // "changeAngleUnit"
QT_MOC_LITERAL(20, 264, 5) // "index"

    },
    "SlideDialogBox\0changeMassCenter\0\0"
    "massCenter\0changeRectAngle\0rectAngle\0"
    "changePJointConnectingId\0_pJointConnectingId\0"
    "changeRectColor\0rectColor\0okClicked\0"
    "colorClicked\0setButtonColor\0_color\0"
    "getIdListFromSlide\0std::list<int>\0"
    "_idList\0getSlideId\0_slideId\0changeAngleUnit\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlideDialogBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   76,    2, 0x0a /* Public */,
      11,    0,   77,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,
      17,    1,   84,    2, 0x0a /* Public */,
      19,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QColor,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void SlideDialogBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SlideDialogBox *_t = static_cast<SlideDialogBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeMassCenter((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->changeRectAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changePJointConnectingId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeRectColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->okClicked(); break;
        case 5: _t->colorClicked(); break;
        case 6: _t->setButtonColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->getIdListFromSlide((*reinterpret_cast< std::list<int>(*)>(_a[1]))); break;
        case 8: _t->getSlideId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeAngleUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SlideDialogBox::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SlideDialogBox::changeMassCenter)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SlideDialogBox::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SlideDialogBox::changeRectAngle)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SlideDialogBox::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SlideDialogBox::changePJointConnectingId)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SlideDialogBox::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SlideDialogBox::changeRectColor)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SlideDialogBox::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SlideDialogBox.data,
      qt_meta_data_SlideDialogBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SlideDialogBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlideDialogBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SlideDialogBox.stringdata0))
        return static_cast<void*>(const_cast< SlideDialogBox*>(this));
    return QDialog::qt_metacast(_clname);
}

int SlideDialogBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SlideDialogBox::changeMassCenter(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SlideDialogBox::changeRectAngle(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SlideDialogBox::changePJointConnectingId(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SlideDialogBox::changeRectColor(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
