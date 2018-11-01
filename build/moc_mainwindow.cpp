/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "on_toggleWFM_toggled"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "checked"
QT_MOC_LITERAL(4, 41, 20), // "on_toggleNFM_toggled"
QT_MOC_LITERAL(5, 62, 19), // "on_toggleAM_toggled"
QT_MOC_LITERAL(6, 82, 20), // "on_toggleUSB_toggled"
QT_MOC_LITERAL(7, 103, 20), // "on_toggleLSB_toggled"
QT_MOC_LITERAL(8, 124, 20), // "on_toggleRun_toggled"
QT_MOC_LITERAL(9, 145, 24), // "on_spinFreq_valueChanged"
QT_MOC_LITERAL(10, 170, 3), // "val"
QT_MOC_LITERAL(11, 174, 15), // "tmrRead_timeout"
QT_MOC_LITERAL(12, 190, 8), // "setShift"
QT_MOC_LITERAL(13, 199, 15), // "on_shiftChanged"
QT_MOC_LITERAL(14, 215, 9), // "newOffset"
QT_MOC_LITERAL(15, 225, 26), // "on_spinOffset_valueChanged"
QT_MOC_LITERAL(16, 252, 4), // "arg1"
QT_MOC_LITERAL(17, 257, 26), // "on_spinCenter_valueChanged"
QT_MOC_LITERAL(18, 284, 38), // "on_comboDirectSamp_currentInd..."
QT_MOC_LITERAL(19, 323, 5), // "index"
QT_MOC_LITERAL(20, 329, 25) // "on_toggleTransmit_toggled"

    },
    "MainWindow\0on_toggleWFM_toggled\0\0"
    "checked\0on_toggleNFM_toggled\0"
    "on_toggleAM_toggled\0on_toggleUSB_toggled\0"
    "on_toggleLSB_toggled\0on_toggleRun_toggled\0"
    "on_spinFreq_valueChanged\0val\0"
    "tmrRead_timeout\0setShift\0on_shiftChanged\0"
    "newOffset\0on_spinOffset_valueChanged\0"
    "arg1\0on_spinCenter_valueChanged\0"
    "on_comboDirectSamp_currentIndexChanged\0"
    "index\0on_toggleTransmit_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       5,    1,   90,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       7,    1,   96,    2, 0x08 /* Private */,
       8,    1,   99,    2, 0x08 /* Private */,
       9,    1,  102,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      20,    1,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toggleWFM_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_toggleNFM_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_toggleAM_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_toggleUSB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_toggleLSB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_toggleRun_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_spinFreq_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->tmrRead_timeout(); break;
        case 8: _t->setShift(); break;
        case 9: _t->on_shiftChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_spinOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_spinCenter_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_comboDirectSamp_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_toggleTransmit_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
