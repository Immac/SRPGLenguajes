TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += C:\\SFML2.1\\include

LIBS += C:\\SFML2.1\\lib\\libsfml-system.a\
C:\\SFML2.1\\lib\\libsfml-window.a\
C:\\SFML2.1\\lib\\libsfml-graphics.a\
C:\\SFML2.1\\lib\\libsfml-audio.a\
C:\\SFML2.1\\lib\\libsfml-network.a\

DEFINES += SFML_STATIC

SOURCES += \
    Elements/skillset.cpp \
    Elements/panel.cpp \
    Elements/unit.cpp \
    Elements/utilities.cpp \
    main.cpp \
    Elements/board.cpp \
    Elements/stat.cpp \
    Elements/job.cpp \
    Elements/action.cpp \
    Elements/actionattack.cpp \
    Game/game.cpp \
    Game/player.cpp \
    Elements/unitset.cpp \
    Game/allegiance.cpp \
    Elements/statsystem.cpp \
    Elements/actionset.cpp \
    Elements/actionerror.cpp \
    XML/loader.cpp \
    XML/tinyxml2.cpp \
    Expression/except.cpp \
    Expression/expr.cpp \
    Expression/func.cpp \
    Expression/funclist.cpp \
    Expression/node.cpp \
    Expression/parser.cpp \
    Expression/vallist.cpp \
    Console/consolehelper.cpp \
    DemoComponents/demounit.cpp

HEADERS += \
    Elements/skillset.h \
    Elements/panel.h \
    Elements/unit.h \
    Elements/utilities.h \
    Elements/board.h \
    Elements/stat.h \
    Elements/job.h \
    Elements/action.h \
    Elements/actionattack.h \
    Game/game.h \
    Game/player.h \
    Elements/unitset.h \
    Game/allegiance.h \
    Tests/catch.hpp \
    Elements/statsystem.h \
    Elements/actionset.h \
    Elements/actionerror.h \
    XML/loader.h \
    XML/tinyxml2.h \
    Expression/defs.h \
    Expression/except.h \
    Expression/expr.h \
    Expression/expreval.h \
    Expression/funclist.h \
    Expression/node.h \
    Expression/parser.h \
    Expression/vallist.h \
    Console/consolehelper.h \
    DemoComponents/demounit.h

