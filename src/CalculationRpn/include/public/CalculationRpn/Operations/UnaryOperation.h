#pragma once
#include <CalculationRpn/Operations/IOperation.h>

#include <functional>
namespace Operations {
class UnaryOperation : public IOperation {
  std::function<double(double)> _func;

  Associativity _associativity;
  Priority _priority;

 public:
  Priority GetPriority() const override;
  Associativity GetAssociativity() const override;
  UnaryOperation(std::function<double(double)> func, Priority priority,
                 Associativity associativity);
  void operator()(std::list<double> &stack) override;
  ~UnaryOperation();
};
}  // namespace Operations
