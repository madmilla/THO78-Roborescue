/****************************************************************************
** Meta object code from reading C++ file 'displaymap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MapGrid/displaymap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaymap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DisplayMap_t {
    QByteArrayData data[14];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplayMap_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplayMap_t qt_meta_stringdata_DisplayMap = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DisplayMap"
QT_MOC_LITERAL(1, 11, 18), // "currentCellChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "currentRow"
QT_MOC_LITERAL(4, 42, 13), // "currentColumn"
QT_MOC_LITERAL(5, 56, 18), // "on_isGrass_toggled"
QT_MOC_LITERAL(6, 75, 7), // "checked"
QT_MOC_LITERAL(7, 83, 21), // "on_isConcrete_toggled"
QT_MOC_LITERAL(8, 105, 17), // "on_isDirt_toggled"
QT_MOC_LITERAL(9, 123, 18), // "on_isWater_toggled"
QT_MOC_LITERAL(10, 142, 16), // "on_isATV_toggled"
QT_MOC_LITERAL(11, 159, 19), // "on_isRosbee_toggled"
QT_MOC_LITERAL(12, 179, 18), // "on_isEmpty_toggled"
QT_MOC_LITERAL(13, 198, 23) // "on_isQuadcopter_toggled"

    },
    "DisplayMap\0currentCellChanged\0\0"
    "currentRow\0currentColumn\0on_isGrass_toggled\0"
    "checked\0on_isConcrete_toggled\0"
    "on_isDirt_toggled\0on_isWater_toggled\0"
    "on_isATV_toggled\0on_isRosbee_toggled\0"
    "on_isEmpty_toggled\0on_isQuadcopter_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x08 /* Private */,
       5,    1,   64,    2, 0x08 /* Private */,
       7,    1,   67,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,
      10,    1,   76,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void DisplayMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplayMap *_t = static_cast<DisplayMap *>(_o);
        switch (_id) {
        case 0: _t->currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_isGrass_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_isConcrete_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_isDirt_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_isWater_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_isATV_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_isRosbee_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_isEmpty_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_isQuadcopter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DisplayMap::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_DisplayMap.data,
      qt_meta_data_DisplayMap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DisplayMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayMap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayMap.stringdata))
        return static_cast<void*>(const_cast< DisplayMap*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int DisplayMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
