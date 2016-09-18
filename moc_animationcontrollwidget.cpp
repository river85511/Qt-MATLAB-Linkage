/****************************************************************************
** Meta object code from reading C++ file 'animationcontrollwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "animationcontrollwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animationcontrollwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimationControllWidget_t {
    QByteArrayData data[27];
    char stringdata0[516];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimationControllWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimationControllWidget_t qt_meta_stringdata_AnimationControllWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "AnimationControllWidget"
QT_MOC_LITERAL(1, 24, 12), // "runAnimation"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 14), // "pauseAnimation"
QT_MOC_LITERAL(4, 53, 13), // "stopAnimation"
QT_MOC_LITERAL(5, 67, 7), // "speedUp"
QT_MOC_LITERAL(6, 75, 11), // "speedNormal"
QT_MOC_LITERAL(7, 87, 9), // "speedDown"
QT_MOC_LITERAL(8, 97, 9), // "timerTick"
QT_MOC_LITERAL(9, 107, 9), // "updatePos"
QT_MOC_LITERAL(10, 117, 12), // "_sliderValue"
QT_MOC_LITERAL(11, 130, 37), // "getFileNamefromAnimationContr..."
QT_MOC_LITERAL(12, 168, 9), // "_fileName"
QT_MOC_LITERAL(13, 178, 42), // "getReal4BarsListfromAnimation..."
QT_MOC_LITERAL(14, 221, 14), // "QList<NewBar*>"
QT_MOC_LITERAL(15, 236, 10), // "_real4Bars"
QT_MOC_LITERAL(16, 247, 45), // "getReal4BarsPosListfromAnimat..."
QT_MOC_LITERAL(17, 293, 14), // "QList<QPointF>"
QT_MOC_LITERAL(18, 308, 13), // "_real4BarsPos"
QT_MOC_LITERAL(19, 322, 47), // "getReal4BarsAngleListfromAnim..."
QT_MOC_LITERAL(20, 370, 13), // "QList<double>"
QT_MOC_LITERAL(21, 384, 15), // "_real4BarsAngle"
QT_MOC_LITERAL(22, 400, 39), // "getRJointListfromAnimationCon..."
QT_MOC_LITERAL(23, 440, 23), // "QList<RevolutionJoint*>"
QT_MOC_LITERAL(24, 464, 11), // "_RJointList"
QT_MOC_LITERAL(25, 476, 33), // "getTimefromAnimationControllp..."
QT_MOC_LITERAL(26, 510, 5) // "_time"

    },
    "AnimationControllWidget\0runAnimation\0"
    "\0pauseAnimation\0stopAnimation\0speedUp\0"
    "speedNormal\0speedDown\0timerTick\0"
    "updatePos\0_sliderValue\0"
    "getFileNamefromAnimationControllpanel\0"
    "_fileName\0getReal4BarsListfromAnimationControllpanel\0"
    "QList<NewBar*>\0_real4Bars\0"
    "getReal4BarsPosListfromAnimationControllpanel\0"
    "QList<QPointF>\0_real4BarsPos\0"
    "getReal4BarsAngleListfromAnimationControllpanel\0"
    "QList<double>\0_real4BarsAngle\0"
    "getRJointListfromAnimationControllpanel\0"
    "QList<RevolutionJoint*>\0_RJointList\0"
    "getTimefromAnimationControllpanel\0"
    "_time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationControllWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    1,   91,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      19,    1,  103,    2, 0x0a /* Public */,
      22,    1,  106,    2, 0x0a /* Public */,
      25,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void AnimationControllWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimationControllWidget *_t = static_cast<AnimationControllWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->runAnimation(); break;
        case 1: _t->pauseAnimation(); break;
        case 2: _t->stopAnimation(); break;
        case 3: _t->speedUp(); break;
        case 4: _t->speedNormal(); break;
        case 5: _t->speedDown(); break;
        case 6: _t->timerTick(); break;
        case 7: _t->updatePos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->getFileNamefromAnimationControllpanel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getReal4BarsListfromAnimationControllpanel((*reinterpret_cast< QList<NewBar*>(*)>(_a[1]))); break;
        case 10: _t->getReal4BarsPosListfromAnimationControllpanel((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 11: _t->getReal4BarsAngleListfromAnimationControllpanel((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 12: _t->getRJointListfromAnimationControllpanel((*reinterpret_cast< QList<RevolutionJoint*>(*)>(_a[1]))); break;
        case 13: _t->getTimefromAnimationControllpanel((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<NewBar*> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<RevolutionJoint*> >(); break;
            }
            break;
        }
    }
}

const QMetaObject AnimationControllWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AnimationControllWidget.data,
      qt_meta_data_AnimationControllWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnimationControllWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationControllWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationControllWidget.stringdata0))
        return static_cast<void*>(const_cast< AnimationControllWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AnimationControllWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
