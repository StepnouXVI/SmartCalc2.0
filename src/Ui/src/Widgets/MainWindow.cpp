#include <Ui/Consts/Consts.h>
#include <Ui/Main/MainWindow.h>
#include <Ui/Settings.h>
#include <Ui/Styles/Styles.h>

using namespace Ui;
// QLabel *MainWindow::createPlaceHolder(QString name) {
//   auto placeHolder = new QLabel();
//   placeHolder->setText(name);

//   auto label = new QLabel(name, this);
//   auto font = label->font();
//   font.setBold(true);
//   font.setPixelSize(Settings::Instance().CellSetting().H);
//   font.setItalic(true);
//   label->setFont(font);

//   label->setAlignment(Qt::AlignCenter);

//   return nullptr;
// }

// void MainWindow::createInputLine() {
//   _inputString = new QLineEdit(this);
//   _inputString->setMaxLength(256);
//   _inputString->setPlaceholderText(Consts::DEFAULT_INPUT_STRING_TEXT);
//   _inputString->setMinimumSize(14 * Settings::Instance().CellSetting().W,
//                                3 * Settings::Instance().CellSetting().H);
//   _inputString->setStyleSheet(Styles::InputLineStyle);
//   _inputString->setAlignment(Qt::AlignRight);
//   auto font = _inputString->font();
//   font.setBold(true);
//   font.setPixelSize(Settings::Instance().CellSetting().H / 4);
//   font.setItalic(true);
//   _inputString->setFont(font);
// }

MainWindow::MainWindow(map<string, QWidget *> tabs, QWidget *pwgt)
    : QWidget(pwgt) {
  auto mainTabWidget = new QTabWidget(this);
  mainTabWidget->setTabPosition(QTabWidget::North);
  mainTabWidget->setStyleSheet(Styles::TabWidgetStyle);

  for (auto tab : tabs) {
    mainTabWidget->addTab(tab.second, tab.first.c_str());
  }

  auto layout = new QGridLayout(this);
  layout->addWidget(mainTabWidget, 0, 0);

  this->setStyleSheet("border-radius: 5px;  background-color: #1A2030;");

  setLayout(layout);
}

Ui::MainWindow::~MainWindow() {}
