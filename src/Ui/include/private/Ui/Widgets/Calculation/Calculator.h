#pragma once
#include <Ui/Controllers/ICalculationController.h>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <memory>
#include <set>

namespace Ui {
using namespace std;
class Calculator : public QWidget {
  Q_OBJECT
 private:
  shared_ptr<ICalculationController> _calcController = nullptr;
  QLineEdit *_inputString = nullptr;
  QLabel *_outputString = nullptr;

  QLabel *createOutputString();

 public:
  Calculator(ICalculationControllerPtr calcController, QLineEdit *inputString,
             QWidget *functionsMenu, QWidget *parent = nullptr);
  virtual ~Calculator();

 public slots:
  void CEClicked();
};
}  // namespace Ui
