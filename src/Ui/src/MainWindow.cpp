#include <Ui/Consts/Consts>
#include <Ui/Main/MainWindow>
#include <Ui/Settings>
#include <Ui/Styles/Styles>
#include <QGridLayout>

using namespace Ui;

MainWindow::MainWindow(map<string, QWidget *> tabs, QWidget *pwgt)
    : QWidget(pwgt)
{
  auto mainTabWidget = new QTabWidget(this);
  mainTabWidget->setTabPosition(QTabWidget::North);
  mainTabWidget->setStyleSheet(Styles::TabWidgetStyle);

  for (auto tab : tabs)
  {
    mainTabWidget->addTab(tab.second, tab.first.c_str());
    _tabIds[tab.first] = mainTabWidget->count() - 1;
  }

  auto layout = new QGridLayout(this);
  layout->addWidget(mainTabWidget, 0, 0);

  this->setStyleSheet("border-radius: 5px;  background-color: #1A2030;");

  setLayout(layout);
}

void MainWindow::OpenTab(string &name)
{
  _tabWidget->setCurrentIndex(_tabIds[name]);
}

// Ui::MainWindow::~MainWindow() {}