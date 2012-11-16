QT       += core dbus
QT       -= gui

TARGET = UDDaemon
TEMPLATE = app

SOURCES += main.cpp  \
           UDDBusServer.cpp

HEADERS += UDDBusServer.h

DESTDIR = ../
OBJECTS_DIR = ../build
MOC_DIR = ../build
UI_DIR = ../build

target.path = /usr/sbin/

policy.path = /usr/sbin/
policy.extra = restorecon /usr/sbin/UDDaemon

INSTALLS += target policy
