
TEMPLATE = subdirs

SUBDIRS = src

dbus.path = /etc/dbus-1/system.d/
dbus.files = config/net.sourceforge.userdatadefence.avcbus.conf

systemd.target = systemd
systemd.path = /etc/systemd/system/
systemd.files = config/UDDaemon.service

start_service.path = /etc/systemd/system/
start_service.files = config/UDDaemon.service
start_service.extra =  systemctl enable UDDaemon.service
start_service.depends = systemd

INSTALLS += dbus systemd start_service 

QMAKE_EXTRA_TARGETS += systemd
