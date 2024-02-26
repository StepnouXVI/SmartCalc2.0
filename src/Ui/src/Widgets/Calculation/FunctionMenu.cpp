#include <Ui/Consts/Consts>
#include <Ui/Settings>
#include <Ui/Styles/NumpadStyles>
#include <Ui/Styles/Styles>
#include <Ui/Widgets/Calculation/FunctionMenu>
#include <Ui/Widgets/Calculation/Numpad>

using namespace Ui;
using namespace std;

void FunctionMenu::ButtonClicked()
{
  _inputString->setText(_inputString->text() +
                        ((QPushButton *)sender())->text());
}

QPushButton *FunctionMenu::createFunctionButton(const std::string &name)
{
  auto but = new QPushButton(QString::fromStdString(name), this);
  but->setMinimumHeight(Settings::Instance().CellSetting().H * 2);
  but->setStyleSheet(Styles::FunctionsMenuButtonStyle);
  auto font = but->font();
  font.setBold(true);
  font.setPixelSize(Settings::Instance().CellSetting().H / 2);
  but->setFont(font);
  connect(but, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
  return but;
}

FunctionMenu::FunctionMenu(std::shared_ptr<QLineEdit> inputString,
                           const std::set<std::string> &functions,
                           QWidget *parent)
{
  _inputString = inputString;
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setWidgetResizable(true);
  setStyleSheet(Styles::ScrollAreaStyle);

  auto layout = new QVBoxLayout(this);
  for (auto &name : functions)
  {
    auto but = createFunctionButton(name);
    layout->addWidget(but);
  }
  auto central = new QWidget(this);
  central->setLayout(layout);
  setWidget(central);
  setMinimumSize(4 * Settings::Instance().CellSetting().W, 10 * Settings::Instance().CellSetting().H);
}

// Ui::FunctionMenu::~FunctionMenu() {}