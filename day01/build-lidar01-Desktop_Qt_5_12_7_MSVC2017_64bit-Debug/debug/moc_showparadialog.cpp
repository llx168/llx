/****************************************************************************
** Meta object code from reading C++ file 'showparadialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lidar01-2023-1-30/showparadialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showparadialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowParaDialog_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowParaDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowParaDialog_t qt_meta_stringdata_ShowParaDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ShowParaDialog"
QT_MOC_LITERAL(1, 15, 14), // "showParaSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "ShowPara"
QT_MOC_LITERAL(4, 40, 1), // "s"
QT_MOC_LITERAL(5, 42, 22), // "on_pushButton_released"
QT_MOC_LITERAL(6, 65, 24), // "on_pushButton_3_released"
QT_MOC_LITERAL(7, 90, 24) // "on_pushButton_2_released"

    },
    "ShowParaDialog\0showParaSignal\0\0ShowPara\0"
    "s\0on_pushButton_released\0"
    "on_pushButton_3_released\0"
    "on_pushButton_2_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowParaDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShowParaDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowParaDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showParaSignal((*reinterpret_cast< ShowPara(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_released(); break;
        case 2: _t->on_pushButton_3_released(); break;
        case 3: _t->on_pushButton_2_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShowParaDialog::*)(ShowPara );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShowParaDialog::showParaSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShowParaDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ShowParaDialog.data,
    qt_meta_data_ShowParaDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShowParaDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowParaDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowParaDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ShowParaDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ShowParaDialog::showParaSignal(ShowPara _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
