#pragma once

#include <Ui/Controllers/ICalculationController>

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QStack>
#include <QWidget>
#include <memory>
#include <set>
#include <QObject>

namespace Ui
{
  class Calculator : public QWidget
  {
    Q_OBJECT

  public:
    using CalculationControllerPtr = std::shared_ptr<ICalculationController>;

  private:
    shared_ptr<QLineEdit> _inputString;
    shared_ptr<QLabel> _outputString;
    CalculationControllerPtr _controller;

  private:
    shared_ptr<QLabel> createOutputLine();

  public slots:
    void Calculate();

  public:
    Calculator(CalculationControllerPtr controller, std::set<string> &functions, QWidget *pwgt = 0);
  signals:
    void CalculateWithX();
  };
} // namespace Ui
