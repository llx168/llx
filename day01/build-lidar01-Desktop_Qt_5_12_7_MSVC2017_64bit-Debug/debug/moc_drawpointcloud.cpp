/****************************************************************************
** Meta object code from reading C++ file 'drawpointcloud.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lidar01-2023-1-30/drawpointcloud.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawpointcloud.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawPointCloud_t {
    QByteArrayData data[5];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawPointCloud_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawPointCloud_t qt_meta_stringdata_DrawPointCloud = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DrawPointCloud"
QT_MOC_LITERAL(1, 15, 16), // "updatePointCloud"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 35), // "pcl::PointCloud<pcl::PointXYZ..."
QT_MOC_LITERAL(4, 69, 5) // "cloud"

    },
    "DrawPointCloud\0updatePointCloud\0\0"
    "pcl::PointCloud<pcl::PointXYZ>::Ptr\0"
    "cloud"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawPointCloud[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void DrawPointCloud::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawPointCloud *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePointCloud((*reinterpret_cast< pcl::PointCloud<pcl::PointXYZ>::Ptr(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DrawPointCloud::*)(pcl::PointCloud<pcl::PointXYZ>::Ptr );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawPointCloud::updatePointCloud)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DrawPointCloud::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DrawPointCloud.data,
    qt_meta_data_DrawPointCloud,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawPointCloud::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawPointCloud::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawPointCloud.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DrawPointCloud::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DrawPointCloud::updatePointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE