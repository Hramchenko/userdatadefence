
TEMPLATE = subdirs

SUBDIRS = src

dispatch_control.path = /usr/bin/
dispatch_control.files = udd_dispatch_control.py

config.path = /etc/audisp/plugins.d
config.files = config/*
config.extra = python /usr/bin/udd_dispatch_control.py --disable


INSTALLS += dispatch_control config

