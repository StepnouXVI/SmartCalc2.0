#include <Controllers/CalculationController.h>
#include <OperationsForCalculation/OperationSet.h>
#include <Ui/Main/MainWindow.h>
#include <Ui/Settings.h>
#include <Ui/Widgets/Calculation.h>

#include <QApplication>

using namespace Ui;

int main(int argc, char *argv[]) {
  Settings::Instance().CellSetting().W = 120;
  Settings::Instance().CellSetting().H = 80;

  auto calcController = make_shared<Controllers::CalculationController>(
      make_shared<Equations::EquationFactory>(
          OperationsForCalculation::OperationSet::getInstance().getData()));

  QApplication app(argc, argv);

  std::set<std::string> functions = {"sin",  "cos",  "tan",  "asin",
                                     "acos", "atan", "sqrt", "ln",
                                     "log",  "exp",  "abs"};

  auto tabs = map<string, QWidget *>();
  tabs["Calculation"] = new Ui::Calculation(calcController, functions);
  MainWindow main_window(tabs);

  main_window.show();
  return app.exec();
}
