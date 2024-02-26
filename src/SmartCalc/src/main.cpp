#include <Controllers/CalculationController>
#include <CalculationOperations/OperationSet>
#include <Ui/Main/MainWindow>
#include <Ui/Settings>
#include <Ui/Widgets/Calculation/Calculator>
#include <Ui/Widgets/Chart/ChartWidget>
#include <Ui/Widgets/CalculationWithX/CalculationWithX>
#include <Ui/Widgets/Credit/CreditWidget>
#include <Controllers/CreditController>
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
    tabs["Calculation"] = calculator;
    tabs["Chart"] = chart;
    tabs["X Calculation"] = new CalculationWithX(calcController);
    tabs["Credit"] = new CreditWidget(std::make_shared<Controllers::CreditController>());
    MainWindow main_window(tabs);
    main_window.show();
    app.setStyle("fusion");
    return app.exec();
}