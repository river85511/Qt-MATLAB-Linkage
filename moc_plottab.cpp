/****************************************************************************
** Meta object code from reading C++ file 'plottab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plottab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plottab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlotTab_t {
    QByteArrayData data[24];
    char stringdata0[480];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlotTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlotTab_t qt_meta_stringdata_PlotTab = {
    {
QT_MOC_LITERAL(0, 0, 7), // "PlotTab"
QT_MOC_LITERAL(1, 8, 29), // "passDisplacementTitlesToGraph"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "QVector<QString>"
QT_MOC_LITERAL(4, 56, 19), // "_displacementTitles"
QT_MOC_LITERAL(5, 76, 25), // "passVelocityTitlesToGraph"
QT_MOC_LITERAL(6, 102, 15), // "_velocityTitles"
QT_MOC_LITERAL(7, 118, 29), // "passAccelerationTitlesToGraph"
QT_MOC_LITERAL(8, 148, 19), // "_accelerationTitles"
QT_MOC_LITERAL(9, 168, 28), // "passDisplacementYAxisToGraph"
QT_MOC_LITERAL(10, 197, 18), // "_displacementYAxis"
QT_MOC_LITERAL(11, 216, 24), // "passVelocityYAxisToGraph"
QT_MOC_LITERAL(12, 241, 14), // "_velocityYAxis"
QT_MOC_LITERAL(13, 256, 28), // "passAccelerationYAxisToGraph"
QT_MOC_LITERAL(14, 285, 18), // "_accelerationYAxis"
QT_MOC_LITERAL(15, 304, 27), // "passDisplacementDataToGraph"
QT_MOC_LITERAL(16, 332, 15), // "QVector<double>"
QT_MOC_LITERAL(17, 348, 17), // "_displacementData"
QT_MOC_LITERAL(18, 366, 23), // "passVelocityDataToGraph"
QT_MOC_LITERAL(19, 390, 13), // "_velocityData"
QT_MOC_LITERAL(20, 404, 27), // "passAccelerationDataToGraph"
QT_MOC_LITERAL(21, 432, 17), // "_accelerationData"
QT_MOC_LITERAL(22, 450, 19), // "passTimeDataToGraph"
QT_MOC_LITERAL(23, 470, 9) // "_timeData"

    },
    "PlotTab\0passDisplacementTitlesToGraph\0"
    "\0QVector<QString>\0_displacementTitles\0"
    "passVelocityTitlesToGraph\0_velocityTitles\0"
    "passAccelerationTitlesToGraph\0"
    "_accelerationTitles\0passDisplacementYAxisToGraph\0"
    "_displacementYAxis\0passVelocityYAxisToGraph\0"
    "_velocityYAxis\0passAccelerationYAxisToGraph\0"
    "_accelerationYAxis\0passDisplacementDataToGraph\0"
    "QVector<double>\0_displacementData\0"
    "passVelocityDataToGraph\0_velocityData\0"
    "passAccelerationDataToGraph\0"
    "_accelerationData\0passTimeDataToGraph\0"
    "_timeData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       9,    1,   73,    2, 0x06 /* Public */,
      11,    1,   76,    2, 0x06 /* Public */,
      13,    1,   79,    2, 0x06 /* Public */,
      15,    1,   82,    2, 0x06 /* Public */,
      18,    1,   85,    2, 0x06 /* Public */,
      20,    1,   88,    2, 0x06 /* Public */,
      22,    1,   91,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,   12,
    QMetaType::Void, 0x80000000 | 3,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   19,
    QMetaType::Void, 0x80000000 | 16,   21,
    QMetaType::Void, 0x80000000 | 16,   23,

       0        // eod
};

void PlotTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotTab *_t = static_cast<PlotTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->passDisplacementTitlesToGraph((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 1: _t->passVelocityTitlesToGraph((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 2: _t->passAccelerationTitlesToGraph((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 3: _t->passDisplacementYAxisToGraph((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 4: _t->passVelocityYAxisToGraph((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 5: _t->passAccelerationYAxisToGraph((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 6: _t->passDisplacementDataToGraph((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 7: _t->passVelocityDataToGraph((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 8: _t->passAccelerationDataToGraph((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 9: _t->passTimeDataToGraph((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlotTab::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passDisplacementTitlesToGraph)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passVelocityTitlesToGraph)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passAccelerationTitlesToGraph)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passDisplacementYAxisToGraph)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passVelocityYAxisToGraph)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passAccelerationYAxisToGraph)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passDisplacementDataToGraph)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passVelocityDataToGraph)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passAccelerationDataToGraph)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (PlotTab::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotTab::passTimeDataToGraph)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject PlotTab::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_PlotTab.data,
      qt_meta_data_PlotTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlotTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlotTab.stringdata0))
        return static_cast<void*>(const_cast< PlotTab*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int PlotTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PlotTab::passDisplacementTitlesToGraph(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlotTab::passVelocityTitlesToGraph(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlotTab::passAccelerationTitlesToGraph(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlotTab::passDisplacementYAxisToGraph(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlotTab::passVelocityYAxisToGraph(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlotTab::passAccelerationYAxisToGraph(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PlotTab::passDisplacementDataToGraph(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PlotTab::passVelocityDataToGraph(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PlotTab::passAccelerationDataToGraph(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PlotTab::passTimeDataToGraph(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
