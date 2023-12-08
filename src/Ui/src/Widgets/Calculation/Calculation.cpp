#include <Ui/Consts/Consts.h>
#include <Ui/Settings.h>
#include <Ui/Styles/CalculatorStyles.h>
#include <Ui/Widgets/Calculation.h>
#include <Ui/Widgets/Calculation/Calculator.h>
#include <Ui/Widgets/Calculation/FunctionMenu.h>
#include <Ui/Widgets/Calculation/Numpad.h>

#include <QLabel>
#include <QLineEdit>
#include <QTabWidget>
#include <QWidget>

namespace Ui {
Calculation::Calculation(ICalculationControllerPtr calcController,
                         std::set<std::string> &functions, QWidget *parent)
    : QWidget(parent) {
  _inputString = createInputLine();
  _calcController = calcController;

  auto layout = new QGridLayout(this);

  auto tabWidget = new QTabWidget(this);
  tabWidget->setStyleSheet(Styles::TabWidgetStyle);
  tabWidget->setMinimumSize(14 * Settings::Instance().CellSetting().W,
                            10 * Settings::Instance().CellSetting().H);
  tabWidget->setTabPosition(QTabWidget::West);

  tabWidget->addTab(
      new Calculator(_calcController, _inputString,
                     new FunctionMenu(_inputString, functions, this), this),
      "Calculation");

  layout->addWidget(_inputString, 0, 0, 3, 14);
  layout->addWidget(tabWidget, 3, 0, 10, 14);

  setLayout(layout);
}
QLineEdit *Calculation::createInputLine() {
  auto inputString = new QLineEdit(this);
  inputString->setMaxLength(256);
  inputString->setPlaceholderText(Consts::DEFAULT_INPUT_STRING_TEXT);
  inputString->setMinimumSize(14 * Settings::Instance().CellSetting().W,
                              3 * Settings::Instance().CellSetting().H);
  inputString->setStyleSheet(Styles::InputLineStyle);
  inputString->setAlignment(Qt::AlignRight);
  auto font = inputString->font();
  font.setBold(true);
  font.setPixelSize(Settings::Instance().CellSetting().H / 4);
  font.setItalic(true);
  inputString->setFont(font);

  return inputString;
}
Calculation::~Calculation() {}
}  // namespace Ui
