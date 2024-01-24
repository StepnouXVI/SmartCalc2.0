#include <Controllers/CalculationController.h>

Controllers::CalculationController::CalculationController(
    std::shared_ptr<Equations::EquationFactory> factory) {
  _factory = factory;
}

double Controllers::CalculationController::Execute(
    const std::string &expression) {
  auto equation =
      _factory->CreateEquation(std::make_shared<std::string>(expression));
  if (equation) {
    return equation->Execute();
  }
  return -1;
}

double Controllers::CalculationController::Execute(
    const std::string &expression, double x) {
  auto equation =
      _factory->CreateEquationWithX(std::make_shared<std::string>(expression));
  if (equation) {
    return equation->Execute(x);
  }
  return -1;
}

std::shared_ptr<std::vector<double>>
Controllers::CalculationController::Execute(std::string &expression,
                                            double start, double end,
                                            size_t numberOfSteps) {
  auto equation =
      _factory->CreateEquationWithX(std::make_shared<std::string>(expression));
  if (equation) {
    return std::make_shared<std::vector<double>>(
        equation->Execute(start, end, numberOfSteps));
  }
  return std::shared_ptr<std::vector<double>>();
}
