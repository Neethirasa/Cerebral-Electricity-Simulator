/****************************************************************************
** Meta object code from reading C++ file 'cestests.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Comp3004Project/cestests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cestests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CESTests_t {
    QByteArrayData data[13];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CESTests_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CESTests_t qt_meta_stringdata_CESTests = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CESTests"
QT_MOC_LITERAL(1, 9, 12), // "initTestCase"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "ampTest"
QT_MOC_LITERAL(4, 31, 12), // "waveformTest"
QT_MOC_LITERAL(5, 44, 13), // "frequencyTest"
QT_MOC_LITERAL(6, 58, 11), // "earNodeTest"
QT_MOC_LITERAL(7, 70, 8), // "timeTest"
QT_MOC_LITERAL(8, 79, 11), // "batteryTest"
QT_MOC_LITERAL(9, 91, 16), // "availabilityTest"
QT_MOC_LITERAL(10, 108, 15), // "cleanupTestCase"
QT_MOC_LITERAL(11, 124, 4), // "init"
QT_MOC_LITERAL(12, 129, 7) // "cleanup"

    },
    "CESTests\0initTestCase\0\0ampTest\0"
    "waveformTest\0frequencyTest\0earNodeTest\0"
    "timeTest\0batteryTest\0availabilityTest\0"
    "cleanupTestCase\0init\0cleanup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CESTests[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CESTests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CESTests *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->ampTest(); break;
        case 2: _t->waveformTest(); break;
        case 3: _t->frequencyTest(); break;
        case 4: _t->earNodeTest(); break;
        case 5: _t->timeTest(); break;
        case 6: _t->batteryTest(); break;
        case 7: _t->availabilityTest(); break;
        case 8: _t->cleanupTestCase(); break;
        case 9: _t->init(); break;
        case 10: _t->cleanup(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CESTests::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CESTests.data,
    qt_meta_data_CESTests,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CESTests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CESTests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CESTests.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CESTests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
