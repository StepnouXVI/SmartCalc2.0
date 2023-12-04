#include <Ui/Consts/Consts.h>
#include <Ui/Main/MainWindow.h>
#include <Ui/Settings.h>
#include <Ui/Styles/styles.h>

using namespace Ui;
QLabel *MainWindow::createPlaceHolder(QString name) {
  auto placeHolder = new QLabel();
  placeHolder->setText(name);
  placeHolder->setStyleSheet(Styles::OutputLineStyle);

  auto label = new QLabel(name, this);
  auto font = label->font();
  font.setBold(true);
  font.setPixelSize(Settings::Instance().CellSetting().H);
  font.setItalic(true);
  label->setFont(font);

  label->setAlignment(Qt::AlignCenter);

  return nullptr;
}

void MainWindow::createInputLine() {
  _inputString = new QLineEdit(this);
  _inputString->setMaxLength(256);
  _inputString->setPlaceholderText(Consts::DEFAULT_INPUT_STRING_TEXT);
  _inputString->setMinimumSize(14 * Settings::Instance().CellSetting().W,
                               2 * Settings::Instance().CellSetting().H);
  _inputString->setStyleSheet(Styles::InputLineStyle);
  _inputString->setAlignment(Qt::AlignRight);
  auto font = _inputString->font();
  font.setBold(true);
  font.setPixelSize(Settings::Instance().CellSetting().H / 2);
  font.setItalic(true);
  _inputString->setFont(font);
}

MainWindow::MainWindow(shared_ptr<ICalculationController> calc,
                       shared_ptr<IDepositController> deposit,
                       shared_ptr<ICreditController> credit, QWidget *pwgt)
    : QWidget(pwgt) {
  createInputLine();

  auto mainTabWidget = new QTabWidget(this);
  mainTabWidget->setStyleSheet(Styles::TabWidgetStyle);

  mainTabWidget->addTab(createPlaceHolder("Calculation"), "Calculation");
  mainTabWidget->addTab(createPlaceHolder("Deposit"), "Deposit");
  mainTabWidget->addTab(createPlaceHolder("Credit"), "Credit");
  mainTabWidget->addTab(createPlaceHolder("Settings"), "Settings");

  auto layout = new QGridLayout(this);
  layout->addWidget(_inputString, 0, 0);
  layout->addWidget(mainTabWidget, 1, 0);
  setLayout(layout);

  this->setStyleSheet("border-radius: 5px;  background-color: #1A2030;");
}

Ui::MainWindow::~MainWindow() {}
