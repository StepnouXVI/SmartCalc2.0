#include <Ui/Main/MainWindow.h>

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Ui::MainWindow main_window(nullptr, nullptr, nullptr);

  main_window.show();
  return app.exec();
}
