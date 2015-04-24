/****************************************************************************
** Meta object code from reading C++ file 'simulatemapwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../environment_test/simulatemapwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulatemapwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SimulateMapWindow_t {
    QByteArrayData data[6];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimulateMapWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimulateMapWindow_t qt_meta_stringdata_SimulateMapWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SimulateMapWindow"
QT_MOC_LITERAL(1, 18, 25), // "on_simulateButton_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 21), // "on_noneButton_clicked"
QT_MOC_LITERAL(4, 67, 27), // "on_checkpointButton_clicked"
QT_MOC_LITERAL(5, 95, 23) // "on_savePcButton_clicked"

    },
    "SimulateMapWindow\0on_simulateButton_clicked\0"
    "\0on_noneButton_clicked\0"
    "on_checkpointButton_clicked\0"
    "on_savePcButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulateMapWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SimulateMapWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimulateMapWindow *_t = static_cast<SimulateMapWindow *>(_o);
        switch (_id) {
        case 0: _t->on_simulateButton_clicked(); break;
        case 1: _t->on_noneButton_clicked(); break;
        case 2: _t->on_checkpointButton_clicked(); break;
        case 3: _t->on_savePcButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SimulateMapWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SimulateMapWindow.data,
      qt_meta_data_SimulateMapWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SimulateMapWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulateMapWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SimulateMapWindow.stringdata))
        return static_cast<void*>(const_cast< SimulateMapWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SimulateMapWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
