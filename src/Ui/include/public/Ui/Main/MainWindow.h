#pragma once

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QTabWidget>
#include <QWidget>
#include <map>

namespace Ui {

using namespace std;

class MainWindow : public QWidget {
  Q_OBJECT

 private:
  QTabWidget *_tabWidget = nullptr;

 public:
  MainWindow(std::map<std::string, QWidget *> tabs, QWidget *pwgt = nullptr);

  virtual ~MainWindow();
};
}  // namespace Ui
