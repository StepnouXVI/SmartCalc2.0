#pragma once
#include <QWidget>
#include <QObject>
#include <Ui/Controllers/ICalculationController>
#include <memory>
#include <QLineEdit>
#include <QLabel>
#include <QCustomPlot>

namespace Ui
{
    class ChartWidget : public QWidget
    {
        Q_OBJECT
    public:
        using CalculationControllerPtr = std::shared_ptr<ICalculationController>;

    private:
        CalculationControllerPtr _controller;
        std::shared_ptr<QLineEdit> _inputString;
        std::shared_ptr<QLabel> _outputString;
        std::shared_ptr<QCustomPlot> _plot;
        std::shared_ptr<QLineEdit> _rangeInputStrings[4];

    private:
        std::shared_ptr<QLabel> createOutputLine();
        std::shared_ptr<QLineEdit> createInputRangeLine(QString placeHolder = "0");
        std::shared_ptr<QCustomPlot> createPlot();

        void getRanges(double* ranges);

        QPushButton* createDrawButton();

    public:
        ChartWidget(CalculationControllerPtr controller, QWidget *pwgt = 0);
    public slots:
        void Draw();
    };
} // namespace Ui