#ifndef STYLES_H
#define STYLES_H

#include <QString>
namespace Ui::Styles
{

  const QString ScrollAreaStyle = R"(
QScrollArea {
    background-color: #2d3146;
}

QScrollArea QWidget {
    background-color: transparent;
}
)";
  const QString FunctionsMenuButtonStyle = R"(
QPushButton { 
    border: none;
    border-radius: 5px;
    background-color: #1A2030;
    color: white;
}
QPushButton:hover { 
    background-color: #4cc2ff;
    color: #1A2030;
}
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

  const QString SliderStyle = R"(
QSlider::groove:horizontal {
  border: 1px solid #1A2030;
  height: 8px;
  background: #373b49;
  margin: 2px 0;
  border-radius: 4px;
}

QSlider::handle:horizontal {
  background: #2d3146;
  border: 1px solid #47b1e9;
  width: 18px;
  height: 18px;
  margin: -5px 0;
  border-radius: 9px;
}

QSlider::sub-page:horizontal {
  background: #4cc2ff;
  border: 1px solid #47b1e9;
  height: 8px;
  border-radius: 4px;
}

QSlider::add-page:horizontal {
  background: #1A2030;
  border: 1px solid #373b49;
  height: 8px;
  border-radius: 4px;
}
)";

const QString CheckBoxStyle = R"(
QCheckBox::indicator {
  width: 36px;
  height: 36px;
}


)";
}

#endif // STYLES_H