/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mapper/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata[346];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "saveMap"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "loadMap"
QT_MOC_LITERAL(4, 28, 8), // "clearMap"
QT_MOC_LITERAL(5, 37, 10), // "refreshMap"
QT_MOC_LITERAL(6, 48, 22), // "on_actionClear_clicked"
QT_MOC_LITERAL(7, 71, 21), // "on_actionSave_clicked"
QT_MOC_LITERAL(8, 93, 23), // "on_actionReload_clicked"
QT_MOC_LITERAL(9, 117, 9), // "setHeight"
QT_MOC_LITERAL(10, 127, 1), // "x"
QT_MOC_LITERAL(11, 129, 1), // "y"
QT_MOC_LITERAL(12, 131, 6), // "height"
QT_MOC_LITERAL(13, 138, 9), // "setObject"
QT_MOC_LITERAL(14, 148, 6), // "object"
QT_MOC_LITERAL(15, 155, 8), // "isObject"
QT_MOC_LITERAL(16, 164, 9), // "getHeight"
QT_MOC_LITERAL(17, 174, 31), // "on_heightSelection_valueChanged"
QT_MOC_LITERAL(18, 206, 4), // "arg1"
QT_MOC_LITERAL(19, 211, 25), // "on_radioDriveable_toggled"
QT_MOC_LITERAL(20, 237, 7), // "checked"
QT_MOC_LITERAL(21, 245, 22), // "on_radioObject_toggled"
QT_MOC_LITERAL(22, 268, 25), // "on_map_currentCellChanged"
QT_MOC_LITERAL(23, 294, 10), // "currentRow"
QT_MOC_LITERAL(24, 305, 13), // "currentColumn"
QT_MOC_LITERAL(25, 319, 11), // "previousRow"
QT_MOC_LITERAL(26, 331, 14) // "previousColumn"

    },
    "MainWindow\0saveMap\0\0loadMap\0clearMap\0"
    "refreshMap\0on_actionClear_clicked\0"
    "on_actionSave_clicked\0on_actionReload_clicked\0"
    "setHeight\0x\0y\0height\0setObject\0object\0"
    "isObject\0getHeight\0on_heightSelection_valueChanged\0"
    "arg1\0on_radioDriveable_toggled\0checked\0"
    "on_radioObject_toggled\0on_map_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    3,   96,    2, 0x08 /* Private */,
      13,    3,  103,    2, 0x08 /* Private */,
      15,    2,  110,    2, 0x08 /* Private */,
      16,    2,  115,    2, 0x08 /* Private */,
      17,    1,  120,    2, 0x08 /* Private */,
      19,    1,  123,    2, 0x08 /* Private */,
      21,    1,  126,    2, 0x08 /* Private */,
      22,    4,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   10,   11,   14,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   24,   25,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->saveMap(); break;
        case 1: _t->loadMap(); break;
        case 2: _t->clearMap(); break;
        case 3: _t->refreshMap(); break;
        case 4: _t->on_actionClear_clicked(); break;
        case 5: _t->on_actionSave_clicked(); break;
        case 6: _t->on_actionReload_clicked(); break;
        case 7: _t->setHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->setObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 9: { bool _r = _t->isObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->getHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->on_heightSelection_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_radioDriveable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_radioObject_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_map_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
