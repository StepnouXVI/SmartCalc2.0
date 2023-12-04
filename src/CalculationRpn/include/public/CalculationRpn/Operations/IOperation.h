#pragma once
#include <CalculationRpn/Operations/Associativity.h>
#include <CalculationRpn/Operations/Priority.h>

#include <list>

namespace Operations {
class IOperation {
 public:
  virtual Priority GetPriority() const = 0;
  virtual Associativity GetAssociativity() const = 0;
  virtual void operator()(std::list<double> &) = 0;

 protected:
  virtual ~IOperation() = default;
};
}  // namespace Operations
