QT       += dbus gui xml widgets

TARGET = UDDTray
TEMPLATE = app

SOURCES += main.cpp \
           MainWindow.cpp \
           KNotification.cpp \
           KNotificationMessage.cpp \
           KNotificationMessageAlert.cpp \
           AlertsWatcher.cpp \
           AVCAnalyzer.cpp \
           AVCAnalyzerState.cpp \
           AuditMessage.cpp \
           AuditMessageTimeStamp.cpp \
           AuditMessageField.cpp \
           AuditMessageViewer.cpp \
           ApplicationsParser.cpp \
           ControllableApplication.cpp \
           ApplicationsGroup.cpp \
           ApplicationsGroupMode.cpp \
           ApplicationsMenuItem.cpp \
           XMLFileElement.cpp \
           XMLFileReader.cpp \
           ApplicationsControlRoot.cpp \
           UDDExecBus.cpp \
           AuditMessageNotificationSettings.cpp \
           AuditMessageDefaultNotification.cpp \
           AuditMessageTypeFilterNotification.cpp \
           AuditMessageRegExpFilterNotification.cpp \
           NotificationConfigParser.cpp \
           AuditMessageNotification.cpp \
           AuditMessageMultipleEventsNotification.cpp \
           KNotificationMessageMultipleAlerts.cpp \
           TrayIcon.cpp \
           RawMessagesTextEdit.cpp \
           GeneratedPolicyTextEdit.cpp \
           MessagesListAnalyzer.cpp \
           UDDaemonInterface.cpp \
           AlertsListViewer.cpp \
           AlertsDepositary.cpp \
           AlertsStatistics.cpp \
           FreedesktopImageHint.cpp \
           functions.cpp \
           RawMessageViewer.cpp \
           AlertsEditor.cpp \
           MainTab.cpp \
           PolicyEditor.cpp \
           SystemMessagesViewer.cpp \
           PreferencesDialog.cpp \
           AlertSettingsBox.cpp \
           NotificationMessagesList.cpp \
           NotificationMessagesListItem.cpp \
           XMLFileWriter.cpp \
           ApplicationsSettingsList.cpp \
           ApplicationsSettingsListItem.cpp \
           ApplicationsSettingsParameter.cpp \
           ApplicationSettingsBox.cpp \
           ImageSelectionBox.cpp \
           SettingsList.cpp \
           findform.cpp \
           finddialog.cpp \
           findreplaceform.cpp \
           findreplacedialog.cpp \
           NewPolicyDialog.cpp \
           AVCVisitor.cpp \
           GlobalSettings.cpp \
           TEHighlighter.cpp \
           TEEditor.cpp \
           AboutDialog.cpp
           
           
HEADERS += MainWindow.h \
           KNotification.h \
           KNotificationMessage.h \
           KNotificationMessageAlert.h \
           AlertsWatcher.h \
           AVCAnalyzer.h \
           AVCAnalyzerState.h \
           AuditMessage.h \
           AuditMessageTimeStamp.h \
           AuditMessageField.h \
           AuditMessageViewer.h \
           ApplicationsParser.h \
           ControllableApplication.h \
           ApplicationsGroup.h \
           ApplicationsGroupMode.h \
           ApplicationsMenuItem.h \
           XMLFileElement.h \
           XMLFileReader.h \
           ApplicationsControlRoot.h \
           UDDExecBus.h \
           AuditMessageNotificationSettings.h \
           AuditMessageDefaultNotification.h \
           AuditMessageTypeFilterNotification.h \
           AuditMessageRegExpFilterNotification.h \
           NotificationConfigParser.h \
           AuditMessageNotification.h \
           AuditMessageMultipleEventsNotification.h \
           KNotificationMessageMultipleAlerts.h \
           TrayIcon.h \
           RawMessagesTextEdit.h \
           GeneratedPolicyTextEdit.h \
           MessagesListAnalyzer.h \
           UDDaemonInterface.h \
           AlertsListViewer.h \
           AlertsDepositary.h \
           AlertsStatistics.h \
           FreedesktopImageHint.h \
           functions.h \
           RawMessageViewer.h \
           AlertsEditor.h \
           MainTab.h \
           PolicyEditor.h \
           SystemMessagesViewer.h \
           PreferencesDialog.h \
           AlertSettingsBox.h \
           NotificationMessagesList.h \
           NotificationMessagesListItem.h \
           XMLFileWriter.h \
           ApplicationsSettingsList.h \
           ApplicationsSettingsListItem.h \
           ApplicationsSettingsParameter.h \
           ApplicationSettingsBox.h \
           ImageSelectionBox.h \
           SettingsList.h \
           findreplaceform.h \
           findreplacedialog.h \
           findform.h \
           finddialog.h \
           findreplace_global.h \
           NewPolicyDialog.h \
           AVCVisitor.h \
           GlobalSettings.h \
           TEHighlighter.h \
           TEEditor.h \
           AboutDialog.h

FORMS += mainwindow.ui \
         preferencesdialog.ui \
         alertsettingsbox.ui \
         notificationmessageslist.ui  \
         applicationsettingsbox.ui \
         imageselectionbox.ui \
         findreplaceform.ui \
         findreplacedialog.ui \
         newpolicydialog.ui \
         aboutdialog.ui
         

RESOURCES    = images.qrc 

LIBS += -lauparse -laudit
           
DESTDIR = ../
OBJECTS_DIR = ../build
MOC_DIR = ../build
UI_DIR = ../build

target.path = /usr/bin/

INSTALLS += target 
