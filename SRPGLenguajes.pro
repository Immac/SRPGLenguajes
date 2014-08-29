TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    Elements/panel.cpp \
    Elements/unit.cpp \
    Elements/utilities.cpp \
    main.cpp \
    Elements/board.cpp \
    Elements/stat.cpp \
    Tests/test.cpp \
    Makers/maker.cpp \
    Elements/job.cpp \
    Elements/action.cpp \
    Elements/actionattack.cpp

HEADERS += \
    Elements/panel.h \
    Elements/unit.h \
    Elements/utilities.h \
    Elements/board.h \
    Elements/stat.h \
    Tests/test.h \
    Makers/maker.h \
    Elements/job.h \
    Elements/action.h \
    Elements/actionattack.h

