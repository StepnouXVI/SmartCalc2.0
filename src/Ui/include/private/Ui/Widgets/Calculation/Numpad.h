#pragma once
#include <Ui/Controllers/ICalculationController.h>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <memory>

namespace Ui {
using namespace std;

class Numpad : public QWidget {
 private:
  QLineEdit *_inputString = nullptr;
  QLabel *_outputString = nullptr;
  ICalculationControllerPtr _CalcController = nullptr;

  QLabel *createOutPutLine();
  QPushButton *createButton(const QString &name, int w, int h, QString style);
  QGridLayout *createNumpad();

 public:
  Numpad(ICalculationControllerPtr calcController, QLineEdit *inputString,
         QLabel *outputString, QWidget *parent = nullptr);
  virtual ~Numpad();

 public slots:
  void ButtonClicked();
};
}  // namespace Ui
