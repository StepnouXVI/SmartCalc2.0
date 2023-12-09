#pragma once

#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <set>
#include <string>
namespace Ui {
class FunctionMenu : public QScrollArea {
  Q_OBJECT

 private:
  QLineEdit *_inputString = nullptr;

  QPushButton *createFucntionButton(const std::string &name);

 public:
  FunctionMenu(QLineEdit *inputString, const std::set<std::string> &functions,
               QWidget *parent = nullptr);
  virtual ~FunctionMenu();

 public slots:
  void ButtonClicked();
};
}  // namespace Ui
