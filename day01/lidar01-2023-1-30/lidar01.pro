QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    pointcloudprocdialog.cpp \
    radarimage.cpp \
    showparadialog.cpp \
    drawpointcloud.cpp \
    laserdataprocess2d.cpp \
    PointCloudProcess3D.cpp

HEADERS += \
    dialog.h \
    mainwindow.h \
    pointcloudprocdialog.h \
    radarimage.h \
    showparadialog.h \
    drawpointcloud.h \
    laserdataprocess2d.h \
    scanShadowsFilter.h \
    PointCloudProcess3D.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    pointcloudprocdialog.ui \
    showparadialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imageResource.qrc

#pcl


#INCLUDEPATH += /usr/include/eigen3

#INCLUDEPATH += /usr/include/vtk-6.3
#LIBS += /usr/lib/x86_64-linux-gnu/libvtk*.so

#INCLUDEPATH += /usr/include/boost
#LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so

#INCLUDEPATH += /usr/local/include/pcl-1.9/pcl
#LIBS += /usr/local/lib/libpcl_*.so


INCLUDEPATH += /usr/include/eigen3
INCLUDEPATH += /usr/include/vtk-6.3
LIBS += /usr/lib/x86_64-linux-gnu/libvtk*.so
INCLUDEPATH += /usr/include/boost
LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so
INCLUDEPATH += /usr/local/include/pcl-1.9
LIBS += /usr/local/lib/libpcl_*.so

