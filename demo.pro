QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += console
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardpage.cpp \
    cardwidget.cpp \
    detailwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp

HEADERS += \
    cardpage.h \
    cardwidget.h \
    detailwidget.h \
    mainwindow.h \
    map.h

FORMS += \
    cardpage.ui \
    cardwidget.ui \
    detailwidget.ui \
    mainwindow.ui

INCLUDEPATH += E:\Code\Lib\opencv\install\include\opencv2 \
        E:\Code\Lib\opencv\install\include

LIBS += E:\Code\Lib\opencv\install\x64\mingw\bin\libopencv*

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    graph.qrc \
    graph.qrc
