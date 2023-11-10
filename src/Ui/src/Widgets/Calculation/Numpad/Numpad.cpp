#include <Ui/Consts/Consts.h>
#include <Ui/Consts/NumpadPreset.h>
#include <Ui/Settings.h>
#include <Ui/Styles/NumpadStyles.h>
#include <Ui/Widgets/Calculation/Numpad.h>

namespace Ui {
Numpad::Numpad(std::shared_ptr<QLineEdit> inputString, QWidget *pwgt)
    : QWidget(pwgt) {
  _inputString = inputString;
  auto layout = createNumpad();
  setLayout(layout);
}

void Numpad::ButtonClicked() {
  QString str = ((QPushButton *)sender())->text();
  if (str == "=") {
    //      calculate();
    return;
  }

  QString text = _inputString->text();
  QString last = "";
  text += str;
  _inputString->setText(text);
}

QPushButton *Numpad::createButton(const QString &name, int w, int h,
                                  QString style) {
  QPushButton *pcmd = new QPushButton(name, this);
  pcmd->setMinimumSize(w * Settings::Instance().CellSetting().W,
                       h * Settings::Instance().CellSetting().H);
  connect(pcmd, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
  pcmd->setStyleSheet(style);
  return pcmd;
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
}  // namespace Ui
