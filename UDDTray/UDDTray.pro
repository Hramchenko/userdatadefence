
TEMPLATE = subdirs

SUBDIRS = src

share.path = /usr/share/UDDTray/
share.files = data/*

share_chmod.path = /usr/share/UDDTray/
share_chmod.extra = chmod -R ugoa+r /usr/share/UDDTray/

icon_file.path = /usr/share/icons/hicolor/48x48/apps/
icon_file.files = config/UDDTray.png

icon_desktop.path = /usr/share/applications/
icon_desktop.files = config/UDDTray.desktop

notifyrc.path = /usr/share/kde4/apps/UDDTray
notifyrc.files = config/UDDTray.notifyrc

autostart.path = /usr/share/autostart
autostart.files = config/UDDTray.desktop

autostart_home.path = /home/*/.config/autostart/
autostart_home.files = config/UDDTray.desktop

udd.path = /usr/share/UDDTray/templates/
udd.files = ../UDDPolicy/udd.*

INSTALLS += share icon_file icon_desktop notifyrc autostart autostart_home share_chmod udd

