#include <Ui/Synchronizer>
#include <Ui/Settings>
#include <Ui/Styles/Styles>
#include <Ui/Consts/Consts>
using namespace Ui;
Synchronizer::Synchronizer() {}

Synchronizer Synchronizer::_instance = Synchronizer();
std::list<Synchronizer::QLineEditPtr> Synchronizer::_lines = std::list<QLineEditPtr>();

void Synchronizer::AddLine(QLineEditPtr line)
{
    _lines.push_back(line);
    QObject::connect(line.get(), &QLineEdit::textChanged, &_instance, &Synchronizer::SynchronizeLines);
}

void Synchronizer::SynchronizeLines(const QString &text)
{
    for (auto &line : _lines)
    {
        line->setText(text);
    }
}

Synchronizer::QLineEditPtr Synchronizer::GetNewLine()
{
    // line settings
    auto inputString = std::make_shared<QLineEdit>();
    inputString->setMinimumSize(14 * Settings::Instance().CellSetting().W, 3 * Settings::Instance().CellSetting().H);
    inputString->setStyleSheet(Styles::InputLineStyle);
    // text style settings
    inputString->setMaxLength(256);
    inputString->setPlaceholderText(Consts::DEFAULT_INPUT_STRING_TEXT);
    inputString->setAlignment(Qt::AlignRight);
    // font settings
    auto font = inputString->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H);
    font.setItalic(true);
    inputString->setFont(font);

    AddLine(inputString);

    return inputString;
}
