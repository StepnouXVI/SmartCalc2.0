#pragma once
#include <QTabWidget>
#include <QObject>
#include <QWidget>
#include <map>

namespace Ui
{

  using namespace std;

  class MainWindow : public QWidget
  {
    Q_OBJECT

  private:
    QTabWidget *_tabWidget = nullptr;
    std::map<std::string, int> _tabIds = {};

  public:
    MainWindow(std::map<std::string, QWidget *> tabs, QWidget *pwgt = nullptr);
  public slots:
    void OpenTab(std::string &name);
  };
} // namespace Ui
