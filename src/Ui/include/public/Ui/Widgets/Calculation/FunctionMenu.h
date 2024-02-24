#pragma once

#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <set>
#include <string>
#include <QObject>

namespace Ui
{
  class FunctionMenu : public QScrollArea
  {
    Q_OBJECT
  private:
    std::shared_ptr<QLineEdit> _inputString = nullptr;

    QPushButton *createFunctionButton(const std::string &name);

  public:
    FunctionMenu(std::shared_ptr<QLineEdit> inputString, const std::set<std::string> &functions,
                 QWidget *parent = nullptr);
    // virtual ~FunctionMenu();

  public slots:
    void ButtonClicked();
  };
} // namespace Ui