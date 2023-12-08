#include <Ui/Consts/Consts.h>
#include <Ui/Consts/NumpadPreset.h>
#include <Ui/Settings.h>
#include <Ui/Styles/NumpadStyles.h>
#include <Ui/Styles/Styles.h>
#include <Ui/Widgets/Calculation/Numpad.h>

namespace Ui {

QPushButton *Numpad::createButton(const QString &name, int w, int h,
                                  QString style) {
  QPushButton *pcmd = new QPushButton(name, this);
  pcmd->setMinimumSize(w * Settings::Instance().CellSetting().W,
                       h * Settings::Instance().CellSetting().H);
  connect(pcmd, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
  pcmd->setStyleSheet(style);
  return pcmd;
}

Numpad::Numpad(ICalculationControllerPtr calcController, QLineEdit *inputString,
               QLabel *outputString, QWidget *parent)
    : QWidget(parent) {
  _inputString = inputString;
  _outputString = outputString;
  _CalcController = calcController;

  auto layout = createNumpad();
  setLayout(layout);
}

QGridLayout *Numpad::createNumpad() {
  auto layout = new QGridLayout(this);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      auto but = this->createButton(Consts::ButtonsTemplate[i][j], 2, 2,
                                    Styles::ButtonStyles[i][j]);
      layout->addWidget(but, i, j);
    }
  }

  return layout;
}

void Numpad::ButtonClicked() {
  QString str = ((QPushButton *)sender())->text();
  if (str == "=") {
    _outputString->setText("HeHeHaHa");
    // double res = _CalcController->Execute(str.toStdString());
    return;
  }

  QString text = _inputString->text();
  QString last = "";
  text += str;
  _inputString->setText(text);
}
Numpad::~Numpad() {}
}  // namespace Ui
