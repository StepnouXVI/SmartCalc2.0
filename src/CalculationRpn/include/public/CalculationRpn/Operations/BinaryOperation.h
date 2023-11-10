#pragma once
#include <CalculationRpn/Operations/IOperation.h>

#include <functional>

namespace Operations {
class BinaryOperation : public IOperation {
  std::function<double(double, double)> _func;
  Associativity _associativity;
  Priority _priority;

 public:
  Priority GetPriority() const override;
  Associativity GetAssociativity() const override;
  BinaryOperation(std::function<double(double, double)> func,
                  Associativity associativity, Priority priority);
  void operator()(std::list<double> &stack) override;
  ~BinaryOperation();
};
}  // namespace Operations
