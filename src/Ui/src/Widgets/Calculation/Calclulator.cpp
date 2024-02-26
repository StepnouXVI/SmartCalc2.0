#include <Ui/Consts/Consts>
#include <Ui/Settings>
#include <Ui/Styles/Styles>
#include <Ui/Widgets/Calculation/Calculator>
#include <Ui/Widgets/Calculation/Numpad>
#include <Ui/Widgets/Calculation/FunctionMenu>
#include <QLabel>
#include <QLineEdit>
#include <set>
#include <memory>
#include <QShortcut>
#include <Ui/Synchronizer>

namespace Ui
{
    Calculator::Calculator(CalculationControllerPtr controller, std::set<string> &functions, QWidget *pwgt) : QWidget(pwgt), _controller(controller)
    {
        // set hotkey (numpad enter and basic enter)
        QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
        connect(shortcut, &QShortcut::activated, this, &Calculate);
        shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
        connect(shortcut, &QShortcut::activated, this, &Calculate);

        _inputString = Synchronizer::GetNewLine();
        _outputString = createOutputLine();

        auto numpad = new Numpad(_inputString, this);
        connect(numpad, SIGNAL(Calculate()), this, SLOT(Calculate()));
        auto menu = new FunctionMenu(_inputString, functions, this);

        auto layout = new QGridLayout(this);
        layout->addWidget(_inputString.get(), 0, 0, 1, 2);
        layout->addWidget(_outputString.get(), 1, 1, 1, 1);
        layout->addWidget(numpad, 2, 1, 1, 1);
        layout->addWidget(menu, 1, 0, 2, 1);

        setLayout(layout);
    }

    shared_ptr<QLabel> Calculator::createOutputLine()
    {
        _outputString = std::make_shared<QLabel>(this);
        _outputString->setMinimumSize(10 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
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

    void Calculator::Calculate()
    {
        auto text = _inputString->text();
        if (text.contains("x"))
        {
            emit CalculateWithX();
            return;
        }
        auto expression = std::make_shared<string>(std::move(text.toStdString()));

        try
        {
            double result = _controller->Execute(expression);
            _outputString->setText(QString::number(result));
        }
        catch (const std::exception &e)
        {
            _outputString->setText(QString::fromStdString(e.what()));
        }
    }
} // namespace Ui
