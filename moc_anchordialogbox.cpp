/****************************************************************************
** Meta object code from reading C++ file 'anchordialogbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "anchordialogbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anchordialogbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnchorDialogBox_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnchorDialogBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnchorDialogBox_t qt_meta_stringdata_AnchorDialogBox = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AnchorDialogBox"
QT_MOC_LITERAL(1, 16, 15), // "changeRectAngle"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 9), // "rectAngle"
QT_MOC_LITERAL(4, 43, 16), // "changeMassCenter"
QT_MOC_LITERAL(5, 60, 10), // "massCenter"
QT_MOC_LITERAL(6, 71, 15), // "okButtonClicked"
QT_MOC_LITERAL(7, 87, 15), // "changeAngleUnit"
QT_MOC_LITERAL(8, 103, 5) // "index"

    },
    "AnchorDialogBox\0changeRectAngle\0\0"
    "rectAngle\0changeMassCenter\0massCenter\0"
    "okButtonClicked\0changeAngleUnit\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnchorDialogBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QPointF,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void AnchorDialogBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnchorDialogBox *_t = static_cast<AnchorDialogBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeRectAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changeMassCenter((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->okButtonClicked(); break;
        case 3: _t->changeAngleUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AnchorDialogBox::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnchorDialogBox::changeRectAngle)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AnchorDialogBox::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnchorDialogBox::changeMassCenter)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AnchorDialogBox::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AnchorDialogBox.data,
      qt_meta_data_AnchorDialogBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnchorDialogBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnchorDialogBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnchorDialogBox.stringdata0))
        return static_cast<void*>(const_cast< AnchorDialogBox*>(this));
    return QDialog::qt_metacast(_clname);
}

int AnchorDialogBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void AnchorDialogBox::changeRectAngle(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnchorDialogBox::changeMassCenter(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
