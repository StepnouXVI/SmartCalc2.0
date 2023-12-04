#pragma once

#include <Ui/Controllers/ICalculationController.h>
#include <Ui/Controllers/ICreditController.h>
#include <Ui/Controllers/IDepositController.h>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QTabWidget>
#include <QWidget>
#include <memory>

namespace Ui {

using namespace std;

class MainWindow : public QWidget {
  Q_OBJECT

 private:
  shared_ptr<ICalculationController> _CalcController = nullptr;
  shared_ptr<IDepositController> _DepositController = nullptr;
  shared_ptr<ICreditController> _CreditController = nullptr;

  QLineEdit *_inputString = nullptr;
  QTabWidget *_tabWidget = nullptr;

  QLabel *createPlaceHolder(QString name);
  void createInputLine();

 public:
  MainWindow(shared_ptr<ICalculationController> calc,
             shared_ptr<IDepositController> deposit,
             shared_ptr<ICreditController> credit, QWidget *pwgt = nullptr);

  virtual ~MainWindow();
};
}  // namespace Ui
