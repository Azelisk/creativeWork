QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendardelegate.cpp \
    centeredtextdelegate.cpp \
    checkboxdelegate.cpp \
    comboboxdelegate.cpp \
    firsttable.cpp \
    fourthtable.cpp \
    main.cpp \
    mainwindow.cpp \
    secondtable.cpp \
    thirdtable.cpp

HEADERS += \
    calendardelegate.h \
    centeredtextdelegate.h \
    checkboxdelegate.h \
    comboboxdelegate.h \
    firsttable.h \
    fourthtable.h \
    mainwindow.h \
    secondtable.h \
    thirdtable.h

FORMS += \
    firsttable.ui \
    fourthtable.ui \
    mainwindow.ui \
    secondtable.ui \
    thirdtable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
