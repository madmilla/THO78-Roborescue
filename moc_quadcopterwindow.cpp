/****************************************************************************
** Meta object code from reading C++ file 'quadcopterwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/gui/mission-gui/quadcopter-gui/quadcopterwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quadcopterwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuadcopterWindow_t {
    QByteArrayData data[7];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuadcopterWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuadcopterWindow_t qt_meta_stringdata_QuadcopterWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QuadcopterWindow"
QT_MOC_LITERAL(1, 17, 32), // "on_sendMaxAltitudeButton_clicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 20), // "on_armButton_clicked"
QT_MOC_LITERAL(4, 72, 29), // "on_takeOff_LandButton_clicked"
QT_MOC_LITERAL(5, 102, 24), // "on_restartButton_clicked"
QT_MOC_LITERAL(6, 127, 22) // "on_abortButton_clicked"

    },
    "QuadcopterWindow\0on_sendMaxAltitudeButton_clicked\0"
    "\0on_armButton_clicked\0"
    "on_takeOff_LandButton_clicked\0"
    "on_restartButton_clicked\0"
    "on_abortButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuadcopterWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuadcopterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuadcopterWindow *_t = static_cast<QuadcopterWindow *>(_o);
        switch (_id) {
        case 0: _t->on_sendMaxAltitudeButton_clicked(); break;
        case 1: _t->on_armButton_clicked(); break;
        case 2: _t->on_takeOff_LandButton_clicked(); break;
        case 3: _t->on_restartButton_clicked(); break;
        case 4: _t->on_abortButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QuadcopterWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QuadcopterWindow.data,
      qt_meta_data_QuadcopterWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QuadcopterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuadcopterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QuadcopterWindow.stringdata))
        return static_cast<void*>(const_cast< QuadcopterWindow*>(this));
    if (!strcmp(_clname, "Listener"))
        return static_cast< Listener*>(const_cast< QuadcopterWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QuadcopterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
