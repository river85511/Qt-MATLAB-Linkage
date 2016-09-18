/****************************************************************************
** Meta object code from reading C++ file 'animationcontrollpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "animationcontrollpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animationcontrollpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimationControllPanel_t {
    QByteArrayData data[24];
    char stringdata0[587];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimationControllPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimationControllPanel_t qt_meta_stringdata_AnimationControllPanel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AnimationControllPanel"
QT_MOC_LITERAL(1, 23, 33), // "passTimeToAnimationControllWi..."
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 5), // "_time"
QT_MOC_LITERAL(4, 64, 37), // "passFileNameToAnimationContro..."
QT_MOC_LITERAL(5, 102, 9), // "_fileName"
QT_MOC_LITERAL(6, 112, 42), // "passReal4BarsListToAnimationC..."
QT_MOC_LITERAL(7, 155, 14), // "QList<NewBar*>"
QT_MOC_LITERAL(8, 170, 10), // "_real4Bars"
QT_MOC_LITERAL(9, 181, 45), // "passReal4BarsPosListToAnimati..."
QT_MOC_LITERAL(10, 227, 14), // "QList<QPointF>"
QT_MOC_LITERAL(11, 242, 13), // "_real4BarsPos"
QT_MOC_LITERAL(12, 256, 47), // "passReal4BarsAngleListToAnima..."
QT_MOC_LITERAL(13, 304, 13), // "QList<double>"
QT_MOC_LITERAL(14, 318, 15), // "_real4BarsAngle"
QT_MOC_LITERAL(15, 334, 39), // "passRJointListToAnimationCont..."
QT_MOC_LITERAL(16, 374, 23), // "QList<RevolutionJoint*>"
QT_MOC_LITERAL(17, 398, 11), // "_RJointList"
QT_MOC_LITERAL(18, 410, 25), // "getFileNamefromChooseFile"
QT_MOC_LITERAL(19, 436, 30), // "getReal4BarsListfromChooseFile"
QT_MOC_LITERAL(20, 467, 33), // "getReal4BarsPosListfromChoose..."
QT_MOC_LITERAL(21, 501, 35), // "getReal4BarsAngleListfromChoo..."
QT_MOC_LITERAL(22, 537, 27), // "getRJointListfromChooseFile"
QT_MOC_LITERAL(23, 565, 21) // "getTimefromChooseFile"

    },
    "AnimationControllPanel\0"
    "passTimeToAnimationControllWidget\0\0"
    "_time\0passFileNameToAnimationControllWidget\0"
    "_fileName\0passReal4BarsListToAnimationControllWidget\0"
    "QList<NewBar*>\0_real4Bars\0"
    "passReal4BarsPosListToAnimationControllWidget\0"
    "QList<QPointF>\0_real4BarsPos\0"
    "passReal4BarsAngleListToAnimationControllWidget\0"
    "QList<double>\0_real4BarsAngle\0"
    "passRJointListToAnimationControllWidget\0"
    "QList<RevolutionJoint*>\0_RJointList\0"
    "getFileNamefromChooseFile\0"
    "getReal4BarsListfromChooseFile\0"
    "getReal4BarsPosListfromChooseFile\0"
    "getReal4BarsAngleListfromChooseFile\0"
    "getRJointListfromChooseFile\0"
    "getTimefromChooseFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationControllPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       9,    1,   83,    2, 0x06 /* Public */,
      12,    1,   86,    2, 0x06 /* Public */,
      15,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,   92,    2, 0x0a /* Public */,
      19,    1,   95,    2, 0x0a /* Public */,
      20,    1,   98,    2, 0x0a /* Public */,
      21,    1,  101,    2, 0x0a /* Public */,
      22,    1,  104,    2, 0x0a /* Public */,
      23,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void AnimationControllPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimationControllPanel *_t = static_cast<AnimationControllPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->passTimeToAnimationControllWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->passFileNameToAnimationControllWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->passReal4BarsListToAnimationControllWidget((*reinterpret_cast< QList<NewBar*>(*)>(_a[1]))); break;
        case 3: _t->passReal4BarsPosListToAnimationControllWidget((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 4: _t->passReal4BarsAngleListToAnimationControllWidget((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 5: _t->passRJointListToAnimationControllWidget((*reinterpret_cast< QList<RevolutionJoint*>(*)>(_a[1]))); break;
        case 6: _t->getFileNamefromChooseFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->getReal4BarsListfromChooseFile((*reinterpret_cast< QList<NewBar*>(*)>(_a[1]))); break;
        case 8: _t->getReal4BarsPosListfromChooseFile((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 9: _t->getReal4BarsAngleListfromChooseFile((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 10: _t->getRJointListfromChooseFile((*reinterpret_cast< QList<RevolutionJoint*>(*)>(_a[1]))); break;
        case 11: _t->getTimefromChooseFile((*reinterpret_cast< int(*)>(_a[1]))); break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<NewBar*> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<RevolutionJoint*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AnimationControllPanel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationControllPanel::passTimeToAnimationControllWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AnimationControllPanel::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationControllPanel::passFileNameToAnimationControllWidget)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AnimationControllPanel::*_t)(QList<NewBar*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationControllPanel::passReal4BarsListToAnimationControllWidget)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AnimationControllPanel::*_t)(QList<QPointF> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationControllPanel::passReal4BarsPosListToAnimationControllWidget)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AnimationControllPanel::*_t)(QList<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationControllPanel::passReal4BarsAngleListToAnimationControllWidget)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AnimationControllPanel::*_t)(QList<RevolutionJoint*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationControllPanel::passRJointListToAnimationControllWidget)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject AnimationControllPanel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AnimationControllPanel.data,
      qt_meta_data_AnimationControllPanel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnimationControllPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationControllPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationControllPanel.stringdata0))
        return static_cast<void*>(const_cast< AnimationControllPanel*>(this));
    return QDialog::qt_metacast(_clname);
}

int AnimationControllPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void AnimationControllPanel::passTimeToAnimationControllWidget(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnimationControllPanel::passFileNameToAnimationControllWidget(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AnimationControllPanel::passReal4BarsListToAnimationControllWidget(QList<NewBar*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AnimationControllPanel::passReal4BarsPosListToAnimationControllWidget(QList<QPointF> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AnimationControllPanel::passReal4BarsAngleListToAnimationControllWidget(QList<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AnimationControllPanel::passRJointListToAnimationControllWidget(QList<RevolutionJoint*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
