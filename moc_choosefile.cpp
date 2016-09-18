/****************************************************************************
** Meta object code from reading C++ file 'choosefile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "choosefile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choosefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChooseFile_t {
    QByteArrayData data[28];
    char stringdata0[587];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChooseFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChooseFile_t qt_meta_stringdata_ChooseFile = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChooseFile"
QT_MOC_LITERAL(1, 11, 12), // "removeItself"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 36), // "passFileNameToAnimationContro..."
QT_MOC_LITERAL(4, 62, 9), // "_fileName"
QT_MOC_LITERAL(5, 72, 41), // "passReal4BarsListToAnimationC..."
QT_MOC_LITERAL(6, 114, 14), // "QList<NewBar*>"
QT_MOC_LITERAL(7, 129, 10), // "_real4Bars"
QT_MOC_LITERAL(8, 140, 44), // "passReal4BarsPosListToAnimati..."
QT_MOC_LITERAL(9, 185, 14), // "QList<QPointF>"
QT_MOC_LITERAL(10, 200, 13), // "_real4BarsPos"
QT_MOC_LITERAL(11, 214, 46), // "passReal4BarsAngleListToAnima..."
QT_MOC_LITERAL(12, 261, 13), // "QList<double>"
QT_MOC_LITERAL(13, 275, 15), // "_real4BarsAngle"
QT_MOC_LITERAL(14, 291, 38), // "passRJointListToAnimationCont..."
QT_MOC_LITERAL(15, 330, 23), // "QList<RevolutionJoint*>"
QT_MOC_LITERAL(16, 354, 11), // "_RJointList"
QT_MOC_LITERAL(17, 366, 32), // "passTimeToAnimationControllpanel"
QT_MOC_LITERAL(18, 399, 5), // "_time"
QT_MOC_LITERAL(19, 405, 27), // "getTotalItemListFromDisplay"
QT_MOC_LITERAL(20, 433, 21), // "QList<QGraphicsItem*>"
QT_MOC_LITERAL(21, 455, 15), // "_totalItemsList"
QT_MOC_LITERAL(22, 471, 25), // "getTotalRBListFromDisplay"
QT_MOC_LITERAL(23, 497, 12), // "_totalRBList"
QT_MOC_LITERAL(24, 510, 29), // "getRigidBodyIDListFromDisplay"
QT_MOC_LITERAL(25, 540, 10), // "QList<int>"
QT_MOC_LITERAL(26, 551, 16), // "_rigidBodyIDList"
QT_MOC_LITERAL(27, 568, 18) // "getTimeFromDisplay"

    },
    "ChooseFile\0removeItself\0\0"
    "passFileNameToAnimationControllpanel\0"
    "_fileName\0passReal4BarsListToAnimationControllpanel\0"
    "QList<NewBar*>\0_real4Bars\0"
    "passReal4BarsPosListToAnimationControllpanel\0"
    "QList<QPointF>\0_real4BarsPos\0"
    "passReal4BarsAngleListToAnimationControllpanel\0"
    "QList<double>\0_real4BarsAngle\0"
    "passRJointListToAnimationControllpanel\0"
    "QList<RevolutionJoint*>\0_RJointList\0"
    "passTimeToAnimationControllpanel\0_time\0"
    "getTotalItemListFromDisplay\0"
    "QList<QGraphicsItem*>\0_totalItemsList\0"
    "getTotalRBListFromDisplay\0_totalRBList\0"
    "getRigidBodyIDListFromDisplay\0QList<int>\0"
    "_rigidBodyIDList\0getTimeFromDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChooseFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       8,    1,   76,    2, 0x06 /* Public */,
      11,    1,   79,    2, 0x06 /* Public */,
      14,    1,   82,    2, 0x06 /* Public */,
      17,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,   88,    2, 0x0a /* Public */,
      22,    1,   91,    2, 0x0a /* Public */,
      24,    1,   94,    2, 0x0a /* Public */,
      27,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Int,   18,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void ChooseFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChooseFile *_t = static_cast<ChooseFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeItself(); break;
        case 1: _t->passFileNameToAnimationControllpanel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->passReal4BarsListToAnimationControllpanel((*reinterpret_cast< QList<NewBar*>(*)>(_a[1]))); break;
        case 3: _t->passReal4BarsPosListToAnimationControllpanel((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 4: _t->passReal4BarsAngleListToAnimationControllpanel((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 5: _t->passRJointListToAnimationControllpanel((*reinterpret_cast< QList<RevolutionJoint*>(*)>(_a[1]))); break;
        case 6: _t->passTimeToAnimationControllpanel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->getTotalItemListFromDisplay((*reinterpret_cast< QList<QGraphicsItem*>(*)>(_a[1]))); break;
        case 8: _t->getTotalRBListFromDisplay((*reinterpret_cast< QList<QGraphicsItem*>(*)>(_a[1]))); break;
        case 9: _t->getRigidBodyIDListFromDisplay((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 10: _t->getTimeFromDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<NewBar*> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<RevolutionJoint*> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QGraphicsItem*> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QGraphicsItem*> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChooseFile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::removeItself)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChooseFile::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::passFileNameToAnimationControllpanel)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChooseFile::*_t)(QList<NewBar*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::passReal4BarsListToAnimationControllpanel)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChooseFile::*_t)(QList<QPointF> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::passReal4BarsPosListToAnimationControllpanel)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ChooseFile::*_t)(QList<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::passReal4BarsAngleListToAnimationControllpanel)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ChooseFile::*_t)(QList<RevolutionJoint*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::passRJointListToAnimationControllpanel)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ChooseFile::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChooseFile::passTimeToAnimationControllpanel)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject ChooseFile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChooseFile.data,
      qt_meta_data_ChooseFile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChooseFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChooseFile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChooseFile.stringdata0))
        return static_cast<void*>(const_cast< ChooseFile*>(this));
    return QObject::qt_metacast(_clname);
}

int ChooseFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ChooseFile::removeItself()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ChooseFile::passFileNameToAnimationControllpanel(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChooseFile::passReal4BarsListToAnimationControllpanel(QList<NewBar*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChooseFile::passReal4BarsPosListToAnimationControllpanel(QList<QPointF> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ChooseFile::passReal4BarsAngleListToAnimationControllpanel(QList<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChooseFile::passRJointListToAnimationControllpanel(QList<RevolutionJoint*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ChooseFile::passTimeToAnimationControllpanel(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
