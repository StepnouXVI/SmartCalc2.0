#include<Ui/Consts/Consts>
#include<Ui/Settings>
#include<Ui/Styles/CalculatorStyles>
#include<Ui/Widgets/Calculation/Calculator>
#include<Ui/Widgets/Calculation/Numpad>

#include <QLabel>
#include <QLineEdit>

namespace Ui
{
Calculator::Calculator(CalculationControllerPtr controller, QWidget *pwgt) : QWidget(pwgt), _controller(controller)
{
    _inputString = createInputLine();
    _outputString = createOutputLine();

    auto _numpad = new Numpad(_inputString, this);

    auto layout = new QGridLayout(this);
    layout->addWidget(_inputString.get(), 0, 0, 14, 3);
    layout->addWidget(_outputString.get(), 4, 5, 6, 2);
    layout->addWidget(_numpad, 6, 5, 10, 8);
}

shared_ptr<QLineEdit> Calculator::createInputLine()
{
    // line settings
    _inputString = std::make_shared<QLineEdit>(this);
    _inputString->setMinimumSize(14 * Settings::Instance().CellSetting().W, 3 * Settings::Instance().CellSetting().H);
    _inputString->setStyleSheet(Styles::InputLineStyle);
    // text style settings
    _inputString->setMaxLength(256);
    _inputString->setPlaceholderText(Consts::DEFAULT_INPUT_STRING_TEXT);
    _inputString->setAlignment(Qt::AlignRight);
    // font settings
    auto font = _inputString->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    font.setItalic(true);
    _inputString->setFont(font);

    return _inputString;
}
shared_ptr<QLabel> Calculator::createOutputLine()
{
    _outputString = std::make_shared<QLabel>(this);
    _outputString->setMinimumSize(6 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    _outputString->setText(Consts::DEFAULT_OUTPUT_STRING_TEXT);
    _outputString->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    _outputString->setStyleSheet(Styles::OutputLineStyle);

    auto font = _outputString->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 4);
    font.setItalic(true);
    _outputString->setFont(font);

    return _outputString;
}

} // namespace Ui
