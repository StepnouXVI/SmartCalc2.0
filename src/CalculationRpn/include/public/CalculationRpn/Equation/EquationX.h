#pragma once

#include <CalculationRpn/Equation/Equation>
#include <CalculationRpn/OperationData.h>
#include <CalculationRpn/Operations/IOperation.h>
#include <CalculationRpn/Operations/NumberOperation.h>

#include <vector>

namespace Equations
{
class EquationWithX : private Equation
{
  private:
    std::shared_ptr<Operations::NumberOperation> _x = nullptr;

  public:
    EquationWithX(std::shared_ptr<std::list<std::shared_ptr<Operations::IOperation>>> operations,
                  std::shared_ptr<Operations::NumberOperation> x);

    double Execute(double x);
    std::vector<double> Execute(double start, double end, size_t numberOfSteps);
    void Execute(double start, double end, size_t numberOfSteps, std::vector<double> &result);

    double operator()(double x);
    std::vector<double> operator()(double start, double end, size_t numberOfSteps);
    void operator()(double start, double end, size_t numberOfSteps, std::vector<double> &result);
};
} // namespace Equations
