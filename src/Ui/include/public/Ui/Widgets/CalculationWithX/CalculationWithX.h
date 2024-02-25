#pragma once
#include <QWidget>
#include <memory>
#include <QLineEdit>
#include <QLabel>
#include <Ui/Controllers/ICalculationController>
#include <QPushButton>

namespace Ui
{
    class CalculationWithX : public QWidget
    {
        Q_OBJECT
    public:
        using CalculationControllerPtr = std::shared_ptr<ICalculationController>;

    private:
        std::shared_ptr<QLineEdit> _inputString;
        std::shared_ptr<QLabel> _outputString;
        std::shared_ptr<QLineEdit> _xInputString;
        CalculationControllerPtr _controller;

        std::shared_ptr<QLabel> createOutputLine();
        std::shared_ptr<QLineEdit> createXInputLine();
        QPushButton* createCalcButton();

    public:
        CalculationWithX(CalculationControllerPtr controller, QWidget *pwgt = 0);

    public slots:
        void Calculate();
    };

} // namespace Ui
