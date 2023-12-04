#include <CalculationRpn/Operations/BinaryOperation.h>

#include <stdexcept>

namespace Operations {
Priority BinaryOperation::GetPriority() const { return _priority; }

Associativity BinaryOperation::GetAssociativity() const {
  return _associativity;
}

BinaryOperation::BinaryOperation(std::function<double(double, double)> func,
                                 Associativity associativity, Priority priority)
    : _func(func), _associativity(associativity), _priority(priority) {}

void BinaryOperation::operator()(std::list<double> &stack) {
  if (stack.size() < 2) {
    throw std::runtime_error("Not enough operands on the stack");
  }

  auto number1 = stack.front();
  stack.pop_front();
  auto number2 = stack.front();
  stack.pop_front();
  stack.push_front(_func(number2, number1));
}

BinaryOperation::~BinaryOperation() {}
}  // namespace Operations
