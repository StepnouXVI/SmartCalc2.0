#pragma once

#include <Ui/Controllers/ICalculationController.h>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QStack>
#include <QWidget>
#include <memory>
#include <set>

namespace Ui {

class Calculation : public QWidget {

 private:
  shared_ptr<ICalculationController> _calcController = nullptr;

  QLineEdit *_inputString = nullptr;

  QLineEdit *createInputLine();

 public:
  Calculation(ICalculationControllerPtr calcController,
              std::set<std::string> &functions, QWidget *parent = nullptr);
  virtual ~Calculation();
};
}  // namespace Ui
