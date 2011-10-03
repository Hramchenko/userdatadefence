#include "MainWindow.h"
#include "UDDExecBus.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  app.setOrganizationName("User Data Defence");
  app.setApplicationName("UDDTray");
  UDDExecBus* udd_exec_bus = UDDExecBus::instance();
  udd_exec_bus->registerService();
  MainWindow window;
  QApplication::setQuitOnLastWindowClosed(false);
  return app.exec();
}
