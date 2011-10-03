
TEMPLATE = subdirs

SUBDIRS = src

control.path = /usr/sbin/
control.files = udd_daemon_control.py
control.extra = python ./udd_daemon_control.py --enable

config.path = /etc/dbus-1/system.d/
config.files = config/*

INSTALLS += config control 

