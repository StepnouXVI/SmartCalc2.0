#pragma once

#include <CalculationRpn/OperationData.h>
#include <CalculationRpn/Operations/IOperation.h>
namespace Equations {
class Equation {
 private:
  std::shared_ptr<std::list<std::shared_ptr<Operations::IOperation>>>
      _operations;

 public:
  Equation(std::shared_ptr<std::list<std::shared_ptr<Operations::IOperation>>>);
  double Execute();
  double operator()();
};
}  // namespace Equations
