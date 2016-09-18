/****************************************************************************
** Meta object code from reading C++ file 'anchor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "anchor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anchor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Anchor_t {
    QByteArrayData data[19];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Anchor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Anchor_t qt_meta_stringdata_Anchor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Anchor"
QT_MOC_LITERAL(1, 7, 12), // "createRJoint"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "PinHole*"
QT_MOC_LITERAL(4, 30, 4), // "pinA"
QT_MOC_LITERAL(5, 35, 4), // "pinB"
QT_MOC_LITERAL(6, 40, 11), // "jointCenter"
QT_MOC_LITERAL(7, 52, 17), // "changeAnchorAngle"
QT_MOC_LITERAL(8, 70, 12), // "_anchorAngle"
QT_MOC_LITERAL(9, 83, 22), // "changeAnchorMassCenter"
QT_MOC_LITERAL(10, 106, 11), // "_massCenter"
QT_MOC_LITERAL(11, 118, 19), // "getAnchorMassCenter"
QT_MOC_LITERAL(12, 138, 15), // "getAnchorRadius"
QT_MOC_LITERAL(13, 154, 17), // "getAnchorDiameter"
QT_MOC_LITERAL(14, 172, 14), // "getAnchorAngle"
QT_MOC_LITERAL(15, 187, 12), // "getAbsPinPos"
QT_MOC_LITERAL(16, 200, 4), // "hole"
QT_MOC_LITERAL(17, 205, 17), // "collisionDetected"
QT_MOC_LITERAL(18, 223, 11) // "collideItem"

    },
    "Anchor\0createRJoint\0\0PinHole*\0pinA\0"
    "pinB\0jointCenter\0changeAnchorAngle\0"
    "_anchorAngle\0changeAnchorMassCenter\0"
    "_massCenter\0getAnchorMassCenter\0"
    "getAnchorRadius\0getAnchorDiameter\0"
    "getAnchorAngle\0getAbsPinPos\0hole\0"
    "collisionDetected\0collideItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Anchor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,
      13,    0,   74,    2, 0x0a /* Public */,
      14,    0,   75,    2, 0x0a /* Public */,
      15,    1,   76,    2, 0x0a /* Public */,
      17,    2,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::QPointF,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QPointF,   10,
    QMetaType::QPointF,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::QPointF, 0x80000000 | 3,   16,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   16,   18,

       0        // eod
};

void Anchor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Anchor *_t = static_cast<Anchor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createRJoint((*reinterpret_cast< PinHole*(*)>(_a[1])),(*reinterpret_cast< PinHole*(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 1: _t->changeAnchorAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeAnchorMassCenter((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: { QPointF _r = _t->getAnchorMassCenter();
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->getAnchorRadius();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = _t->getAnchorDiameter();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->getAnchorAngle();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { QPointF _r = _t->getAbsPinPos((*reinterpret_cast< PinHole*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = _r; }  break;
        case 8: _t->collisionDetected((*reinterpret_cast< PinHole*(*)>(_a[1])),(*reinterpret_cast< PinHole*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PinHole* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PinHole* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PinHole* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Anchor::*_t)(PinHole * , PinHole * , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Anchor::createRJoint)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Anchor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Anchor.data,
      qt_meta_data_Anchor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Anchor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Anchor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Anchor.stringdata0))
        return static_cast<void*>(const_cast< Anchor*>(this));
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(const_cast< Anchor*>(this));
    return QObject::qt_metacast(_clname);
}

int Anchor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Anchor::createRJoint(PinHole * _t1, PinHole * _t2, QPointF _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
