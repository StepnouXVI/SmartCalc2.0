#pragma once
#include <QString>

namespace Ui
{
namespace Styles
{

const QString NumericButtonStyle = R"(
QPushButton {
    border: none;
    border-radius: 5;
    background-color: #373b49;
    color: white;
}
QPushButton:hover { background-color: #2d3146; }
QPushButton:pressed { background-color: #232737; }
)";

const QString OperandButtonStyle = R"(
QPushButton {
    border: none;
    border-radius: 5;
    background-color: #2d3146;
    color: white;
}
QPushButton:hover { background-color: #373b49; }
QPushButton:pressed { background-color: #2d3146; }
)";
const QString EqualButtonStyle = R"(
QPushButton {
    border: none;
    border-radius: 5;
    background-color: #4cc2ff;
    color: white;
}
QPushButton:hover { background-color: #47b1e9; }
QPushButton:pressed { background-color: #41a1d5; }
)";

const QString ButtonStyles[4][5] = {
    {OperandButtonStyle, NumericButtonStyle, NumericButtonStyle, NumericButtonStyle, OperandButtonStyle},
    {OperandButtonStyle, NumericButtonStyle, NumericButtonStyle, NumericButtonStyle, OperandButtonStyle},
    {OperandButtonStyle, NumericButtonStyle, NumericButtonStyle, NumericButtonStyle, OperandButtonStyle},
    {OperandButtonStyle, OperandButtonStyle, NumericButtonStyle, EqualButtonStyle, OperandButtonStyle}};
} // namespace Styles
} // namespace Ui
