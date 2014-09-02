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
    Elements/job.cpp \
    Elements/action.cpp \
    Elements/actionattack.cpp \
    Elements/skillset.cpp \
    Elements/levelups.cpp \
    Loaders/boardloader.cpp \
    Game/game.cpp \
    Game/player.cpp \
    Elements/unitset.cpp \
    Game/allegiance.cpp

HEADERS += \
    Elements/panel.h \
    Elements/unit.h \
    Elements/utilities.h \
    Elements/board.h \
    Elements/stat.h \
    Tests/test.h \
    Elements/job.h \
    Elements/action.h \
    Elements/actionattack.h \
    Elements/skillset.h \
    Elements/levelups.h \
    Loaders/boardloader.h \
    Game/game.h \
    Game/player.h \
    Elements/unitset.h \
    Game/allegiance.h \
    Expression/exprtk.hpp \
    Tests/catch.hpp

