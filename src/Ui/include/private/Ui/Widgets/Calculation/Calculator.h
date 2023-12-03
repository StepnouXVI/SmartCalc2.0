#pragma once

#include <Ui/Controllers/ICalculationController.h>

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QStack>
#include <QWidget>
#include <memory>

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
    shared_ptr<QLineEdit> createInputLine();
    shared_ptr<QLabel> createOutputLine();

  public:
    Calculator(CalculationControllerPtr controller, QWidget *pwgt = 0);
};
} // namespace Ui
