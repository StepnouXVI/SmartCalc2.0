#include <Ui/Consts/Consts.h>
#include <Ui/Settings.h>
#include <Ui/Styles/NumpadStyles.h>
#include <Ui/Styles/Styles.h>
#include <Ui/Widgets/Calculation/FunctionMenu.h>
#include <Ui/Widgets/Calculation/Numpad.h>
using namespace Ui;
using namespace std;

void FunctionMenu::ButtonClicked() {
  _inputString->setText(_inputString->text() +
                        ((QPushButton *)sender())->text());
}

QPushButton *FunctionMenu::createFucntionButton(const std::string &name) {
  auto but = new QPushButton(QString::fromStdString(name), this);
  but->setStyleSheet(Styles::FunctionsMenuButtonStyle);
  connect(but, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
  return but;
}

FunctionMenu::FunctionMenu(QLineEdit *inputString,
                           const std::set<std::string> &functions,
                           QWidget *parent) {
  _inputString = inputString;
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setWidgetResizable(true);
  setStyleSheet(Styles::ScrollAreaStyle);

  auto layout = new QVBoxLayout(this);
  for (auto &name : functions) {
    auto but = createFucntionButton(name);
    layout->addWidget(but);
  }
  auto central = new QWidget(this);
  central->setLayout(layout);
  setWidget(central);
}
