#include <Ui/Consts/Consts.h>
#include <Ui/Settings.h>
#include <Ui/Styles/NumpadStyles.h>
#include <Ui/Styles/Styles.h>
#include <Ui/Widgets/Calculation/Calculator.h>
#include <Ui/Widgets/Calculation/Numpad.h>

using namespace Ui;

Calculator::Calculator(ICalculationControllerPtr calcController,
                       QLineEdit *inputString, QWidget *functionsMenu,
                       QWidget *parent)
    : QWidget(parent) {
  _calcController = calcController;
  _inputString = inputString;
  auto layout = new QGridLayout(this);
  _outputString = createOutputString();
  layout->addWidget(_outputString, 0, 4, 2, 6);
  layout->addWidget(functionsMenu, 0, 0, 10, 4);
  layout->addWidget(
      new Numpad(calcController, _inputString, _outputString, this), 3, 4, 8,
      10);

  auto CE = new QPushButton("CE", this);
  CE->setStyleSheet(Styles::EqualBUttonStyle);
  connect(CE, SIGNAL(clicked()), this, SLOT(CEClicked()));
  layout->addWidget(CE, 0, 10, 2, 4);

  setLayout(layout);
}

QLabel *Ui::Calculator::createOutputString() {
  auto string = new QLabel("", this);
  string->setText(Consts::DEFAULT_OUTPUT_STRING_TEXT);
  string->setAlignment(Qt::AlignRight | Qt::AlignBottom);
  string->setStyleSheet(Styles::OutputLineStyle);

  auto font = string->font();
  font.setBold(true);
  font.setPixelSize(Settings::Instance().CellSetting().H);
  font.setItalic(true);
  string->setFont(font);

  return string;
}

void Calculator::CEClicked() { _inputString->setText(""); }
