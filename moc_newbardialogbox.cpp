/****************************************************************************
** Meta object code from reading C++ file 'newbardialogbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newbardialogbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newbardialogbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewBarDialogBox_t {
    QByteArrayData data[24];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewBarDialogBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewBarDialogBox_t qt_meta_stringdata_NewBarDialogBox = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewBarDialogBox"
QT_MOC_LITERAL(1, 16, 16), // "changeMassCenter"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "massCenter"
QT_MOC_LITERAL(4, 45, 15), // "changeRectWidth"
QT_MOC_LITERAL(5, 61, 9), // "rectWidth"
QT_MOC_LITERAL(6, 71, 15), // "changeRectAngle"
QT_MOC_LITERAL(7, 87, 9), // "rectAngle"
QT_MOC_LITERAL(8, 97, 15), // "changeRectColor"
QT_MOC_LITERAL(9, 113, 9), // "rectColor"
QT_MOC_LITERAL(10, 123, 16), // "setAsDrivingLink"
QT_MOC_LITERAL(11, 140, 13), // "isDirvingLink"
QT_MOC_LITERAL(12, 154, 16), // "changeAngularVel"
QT_MOC_LITERAL(13, 171, 10), // "angularVel"
QT_MOC_LITERAL(14, 182, 16), // "changeAngularAcc"
QT_MOC_LITERAL(15, 199, 10), // "angularAcc"
QT_MOC_LITERAL(16, 210, 9), // "okClicked"
QT_MOC_LITERAL(17, 220, 12), // "colorClicked"
QT_MOC_LITERAL(18, 233, 14), // "setButtonColor"
QT_MOC_LITERAL(19, 248, 6), // "_color"
QT_MOC_LITERAL(20, 255, 18), // "drivingLinkChecked"
QT_MOC_LITERAL(21, 274, 8), // "_checked"
QT_MOC_LITERAL(22, 283, 15), // "changeAngleUnit"
QT_MOC_LITERAL(23, 299, 5) // "index"

    },
    "NewBarDialogBox\0changeMassCenter\0\0"
    "massCenter\0changeRectWidth\0rectWidth\0"
    "changeRectAngle\0rectAngle\0changeRectColor\0"
    "rectColor\0setAsDrivingLink\0isDirvingLink\0"
    "changeAngularVel\0angularVel\0"
    "changeAngularAcc\0angularAcc\0okClicked\0"
    "colorClicked\0setButtonColor\0_color\0"
    "drivingLinkChecked\0_checked\0changeAngleUnit\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewBarDialogBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       8,    1,   83,    2, 0x06 /* Public */,
      10,    1,   86,    2, 0x06 /* Public */,
      12,    1,   89,    2, 0x06 /* Public */,
      14,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,   95,    2, 0x0a /* Public */,
      17,    0,   96,    2, 0x0a /* Public */,
      18,    1,   97,    2, 0x0a /* Public */,
      20,    1,  100,    2, 0x0a /* Public */,
      22,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void NewBarDialogBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewBarDialogBox *_t = static_cast<NewBarDialogBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeMassCenter((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->changeRectWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeRectAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changeRectColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->setAsDrivingLink((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->changeAngularVel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->changeAngularAcc((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->okClicked(); break;
        case 8: _t->colorClicked(); break;
        case 9: _t->setButtonColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 10: _t->drivingLinkChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->changeAngleUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewBarDialogBox::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::changeMassCenter)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NewBarDialogBox::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::changeRectWidth)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NewBarDialogBox::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::changeRectAngle)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NewBarDialogBox::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::changeRectColor)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NewBarDialogBox::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::setAsDrivingLink)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (NewBarDialogBox::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::changeAngularVel)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (NewBarDialogBox::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBarDialogBox::changeAngularAcc)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject NewBarDialogBox::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewBarDialogBox.data,
      qt_meta_data_NewBarDialogBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewBarDialogBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewBarDialogBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewBarDialogBox.stringdata0))
        return static_cast<void*>(const_cast< NewBarDialogBox*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewBarDialogBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void NewBarDialogBox::changeMassCenter(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NewBarDialogBox::changeRectWidth(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NewBarDialogBox::changeRectAngle(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NewBarDialogBox::changeRectColor(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NewBarDialogBox::setAsDrivingLink(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NewBarDialogBox::changeAngularVel(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NewBarDialogBox::changeAngularAcc(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
