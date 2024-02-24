#include <Controllers/CalculationController>
#include <CalculationOperations/OperationSet>
#include <Ui/Main/MainWindow>
#include <Ui/Settings>
#include <Ui/Widgets/Calculation/Calculator>
#include <Ui/Widgets/Chart/ChartWidget>

#include <QApplication>

using namespace Ui;

int main(int argc, char *argv[])
{
    Settings::Instance().CellSetting().W = 50;
    Settings::Instance().CellSetting().H = 50;

    auto calcController = make_shared<Controllers::CalculationController>(
        CalculationOperations::OperationSet::getInstance().getData());

    QApplication app(argc, argv);

    std::set<std::string> functions = {"sin", "cos", "tan", "asin",
                                       "acos", "atan", "sqrt", "ln",
                                       "log", "exp", "abs"};

    auto tabs = map<string, QWidget *>();
    auto calculator = new Calculator(calcController, functions);
    auto chart = new ChartWidget(calcController);
    QObject::connect(calculator, SIGNAL(CalculateWithX), chart, SLOT(Draw));
    tabs["Calculation"] = calculator;
    tabs["Chart"] = chart;
    MainWindow main_window(tabs);

    QObject::connect(calculator, SIGNAL(CalculateWithX), &main_window, SLOT(OpenTab("Chart")));

    main_window.show();
    app.setStyle("fusion");
    return app.exec();
}