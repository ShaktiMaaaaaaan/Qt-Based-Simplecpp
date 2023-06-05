/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/canvas.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canvas_t {
    const uint offsetsAndSize[20];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Canvas_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 6), // "Canvas"
QT_MOC_LITERAL(7, 7), // "clicked"
QT_MOC_LITERAL(15, 0), // ""
QT_MOC_LITERAL(16, 12), // "mouseDragged"
QT_MOC_LITERAL(29, 18), // "mouseButtonPressed"
QT_MOC_LITERAL(48, 19), // "mouseButtonReleased"
QT_MOC_LITERAL(68, 10), // "keyPressed"
QT_MOC_LITERAL(79, 3), // "key"
QT_MOC_LITERAL(83, 6), // "render"
QT_MOC_LITERAL(90, 11) // "dirtyRegion"

    },
    "Canvas\0clicked\0\0mouseDragged\0"
    "mouseButtonPressed\0mouseButtonReleased\0"
    "keyPressed\0key\0render\0dirtyRegion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,
       5,    0,   53,    2, 0x06,    4 /* Public */,
       6,    1,   54,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   57,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QRegion,    9,

       0        // eod
};

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canvas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->mouseDragged(); break;
        case 2: _t->mouseButtonPressed(); break;
        case 3: _t->mouseButtonReleased(); break;
        case 4: _t->keyPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->render((*reinterpret_cast< std::add_pointer_t<QRegion>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::mouseDragged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::mouseButtonPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::mouseButtonReleased)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::keyPressed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Canvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QWindow::staticMetaObject>(),
    qt_meta_stringdata_Canvas.offsetsAndSize,
    qt_meta_data_Canvas,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Canvas_t
, QtPrivate::TypeAndForceComplete<Canvas, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QRegion &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata0))
        return static_cast<void*>(this);
    return QWindow::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Canvas::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Canvas::mouseDragged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Canvas::mouseButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Canvas::mouseButtonReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Canvas::keyPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
