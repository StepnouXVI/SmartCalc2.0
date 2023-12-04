#ifndef STYLES_H
#define STYLES_H

#include <QString>

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
const QString EqualBUttonStyle = R"(
QPushButton { 
    border: none;
    border-radius: 5;
    background-color: #4cc2ff;
    color: white;
}
QPushButton:hover { background-color: #47b1e9; }
QPushButton:pressed { background-color: #41a1d5; }
)";

const QString FunctionsMenuButtonStyle = R"(
QPushButton { 
    border: none;
    border-radius: 5px;
    background-color: #1A2030;
    color: white;
}
QPushButton:hover { background-color: #2d3146; }
QPushButton:pressed { background-color: #373b49; }
)";

const QString FunctionMenuStyle = R"(
  QMenu {
    border-radius: 5px;
    border:#2d3146;
    background-color: #2d3146;
    margin: 2px; /* some spacing around the menu */
}

QMenu::item {
  background-color: #373b49;
    padding: 2px 25px 2px 232px;
    border: 1px solid #2d3146;
    border-radius: 5px; /* reserve space for selection border */
}

QMenu::item:selected {
    border-color: #2d3146;
    background: #2d3146;
    border-radius: 5px;
}

QMenu::icon:checked { /* appearance of a 'checked' icon */
    background: #373b49;
    border: #2d3146;
    border-radius: 5px;
    position: absolute;
    top: 1px;
    right: 1px;
    bottom: 1px;
    left: 1px;
}

QMenu::separator {
    height: 2px;
    background: #2d3146;
    margin-left: 10px;
    margin-right: 5px;
}

QMenu::indicator {
    width: 13px;
    height: 13px;
})";

const QString ButtonStyles[4][5] = {
    {OperandButtonStyle, NumericButtonStyle, NumericButtonStyle,
     NumericButtonStyle, OperandButtonStyle},
    {OperandButtonStyle, NumericButtonStyle, NumericButtonStyle,
     NumericButtonStyle, OperandButtonStyle},
    {OperandButtonStyle, NumericButtonStyle, NumericButtonStyle,
     NumericButtonStyle, OperandButtonStyle},
    {OperandButtonStyle, OperandButtonStyle, NumericButtonStyle,
     EqualBUttonStyle, OperandButtonStyle}};

const QString TabWidgetStyle = R"(
    QTabWidget::pane{
        border: none;
        background-color: #1A2030;
      }
    QTabBar::tab{
        color: white
    }
    )";

const QString InputLineStyle = R"(
    QLineEdit {
      color: white;
      border-bottom: 1px solid #373b49;
      background-color: #1A2030;
      margin-left: 7;
      margin-right: 7;
    })";

const QString OutputLineStyle = R"(
    QLabel {
      color: #ffffff;
      border-bottom: 1px solid #373b49;
      border-top: 1px solid #373b49;
      background-color: #1A2030;
      margin-bottom: 0;
    })";

const QString InputRangeLineStyle = R"(
    QLineEdit {
      color: white;
      border: 1px solid #373b49;
      background-color: #1A2030;
    })";

#endif  // STYLES_H