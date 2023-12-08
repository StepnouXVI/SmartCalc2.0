#pragma once
#include <QString>

namespace Ui {
namespace Styles {
const QString InputLineStyle = R"(
    QLineEdit {
      color: white;
      border-bottom: 1px solid #373b49;
      border-top: 1px solid #373b49;
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
const QString TabWidgetStyle = R"(
    QTabWidget::pane{
        border: none;
        background-color: #1A2030;
      }
    QTabBar::tab{
        color: white
    }
    )";
}  // namespace Styles
}  // namespace Ui
