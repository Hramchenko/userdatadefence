QT       -= gui core

CONFIG = release

TARGET = UDDBus

TEMPLATE = app

SOURCES += uddbus.c \
           main.c
           
HEADERS += uddbus.h

LIBS += -lauparse -lselinux -ldbus-1

INCLUDEPATH += /usr/lib64/dbus-1.0/include /usr/include/dbus-1.0
 

DESTDIR = ../
OBJECTS_DIR = ../build

target.path = /usr/sbin/

policy.path = /usr/sbin/
policy.extra = restorecon /usr/sbin/UDDBus

INSTALLS += target policy            


