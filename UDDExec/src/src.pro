QT       += core dbus
QT       -= gui

TARGET = UDDExec
TEMPLATE = app

SOURCES += main.cpp 

DESTDIR = ../
OBJECTS_DIR = ../build
MOC_DIR = ../build

target.path = /usr/bin/

INSTALLS += target 