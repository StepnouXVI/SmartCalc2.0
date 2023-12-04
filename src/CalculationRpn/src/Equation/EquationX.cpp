#include <CalculationRpn/Equation/EquationX.h>

namespace Equations {
EquationWithX::EquationWithX(
    std::shared_ptr<std::list<std::shared_ptr<Operations::IOperation>>>
        operations,
    std::shared_ptr<Operations::NumberOperation> x)
    : Equation(operations) {
  _x = x;
}

double EquationWithX::Execute(double x) {
  _x->SetNumber(x);
  Equation &equation = *this;
  return equation();
}

std::vector<double> EquationWithX::Execute(double start, double end,
                                           size_t numberOfSteps) {
  std::vector<double> result = {};
  Execute(start, end, numberOfSteps, result);

  return std::move(result);
}

void EquationWithX::Execute(double start, double end, size_t numberOfSteps,
                            std::vector<double> &result) {
  if (start >= end) {
    return;
  }

  if (result.size() < numberOfSteps) {
    result.resize(numberOfSteps);
  }

  for (int i = 0; i < numberOfSteps; i++) {
    (result)[i] = Execute(i * (end - start) / (numberOfSteps) + start);
  }
}

double EquationWithX::operator()(double x) { return Execute(x); }

std::vector<double> EquationWithX::operator()(double start, double end,
                                              size_t numberOfSteps) {
  return Execute(start, end, numberOfSteps);
}
void EquationWithX::operator()(double start, double end, size_t numberOfSteps,
                               std::vector<double> &result) {
  Execute(start, end, numberOfSteps, result);
}
}  // namespace Equations
