#include <Ui/Widgets/CalculationWithX/CalculationWithX>
#include <Ui/Synchronizer>

#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QRegularExpressionValidator>
#include <Ui/Consts/Consts>
#include <Ui/Settings>
#include <QLabel>
#include <QLineEdit>
#include <Ui/Styles/Styles>
#include <Ui/Styles/NumpadStyles>
#include <QShortcut>

using namespace Ui;

CalculationWithX::CalculationWithX(CalculationControllerPtr controller, QWidget *pwgt)
    : QWidget(pwgt), _controller(controller)
{
        // set hotkey (numpad enter and basic enter)
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    connect(shortcut, &QShortcut::activated, this, &Calculate);
    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated, this, &Calculate);

    _inputString = Synchronizer::GetNewLine();
    _outputString = createOutputLine();
    _xInputString = createXInputLine();

    auto layout = new QGridLayout(this);
    layout->addWidget(_inputString.get(), 0, 0, 1, 3);
    layout->addWidget(_outputString.get(), 1, 0, 1, 1);
    layout->addWidget(_xInputString.get(), 1, 1, 1, 1);
    layout->addWidget(createCalcButton(), 1, 2, 1, 1);

    setLayout(layout);
}

std::shared_ptr<QLabel> CalculationWithX::createOutputLine()
{
    _outputString = std::make_shared<QLabel>(this);
    _outputString->setMinimumSize(6 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    _outputString->setText(Consts::DEFAULT_OUTPUT_STRING_TEXT);
    _outputString->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    _outputString->setStyleSheet(Styles::OutputLineStyle);

    auto font = _outputString->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    font.setItalic(true);
    _outputString->setFont(font);

    return _outputString;
}

std::shared_ptr<QLineEdit> CalculationWithX::createXInputLine()
{
    auto inputRangeLine = std::make_shared<QLineEdit>(this);
    inputRangeLine->setPlaceholderText("X value");
    inputRangeLine->setMinimumSize(4 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    inputRangeLine->setStyleSheet(Styles::InputRangeLineStyle);
    inputRangeLine->setAlignment(Qt::AlignCenter);
    inputRangeLine->setValidator(new QRegularExpressionValidator(
        QRegularExpression(Consts::DOUBLE_REGEX), this));

    auto font = inputRangeLine->font();
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    inputRangeLine->setFont(font);

    return inputRangeLine;
}

QPushButton *CalculationWithX::createCalcButton()
{
    auto calcButton = new QPushButton("=", this);
    calcButton->setMinimumSize(4 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    calcButton->setStyleSheet(Styles::EqualButtonStyle);
    connect(calcButton, &QPushButton::clicked, this, &Calculate);

    auto font = calcButton->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    calcButton->setFont(font);
    return calcButton;
}

void CalculationWithX::Calculate()
{
    auto text = _inputString->text();
    auto expression = std::make_shared<string>(std::move(text.toStdString()));

    bool ok = false;
    double number = _xInputString->text().toDouble(&ok);
    double x = ok ? number : 1.0;

    try
    {
        double result = _controller->Execute(expression, x);
        _outputString->setText(QString::number(result));
    }
    catch (const std::exception &e)
    {
        _outputString->setText(QString::fromStdString(e.what()));
    }
}
