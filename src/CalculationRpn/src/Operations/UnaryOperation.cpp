#include <CalculationRpn/Operations/UnaryOperation.h>

#include <stdexcept>
namespace Operations
{
Priority UnaryOperation::GetPriority() const
{
    return _priority;
}

Associativity UnaryOperation::GetAssociativity() const
{
    return _associativity;
}

UnaryOperation::UnaryOperation(std::function<double(double)> func, Priority priority, Associativity associativity)
    : _func(func), _priority(priority), _associativity(associativity)
{
}

void UnaryOperation::operator()(std::list<double> &stack)
{
    if (stack.empty())
    {
        throw std::runtime_error("Not enough operands on the stack");
    }

    auto number = stack.front();
    stack.pop_front();
    stack.push_front(_func(number));
}

UnaryOperation::~UnaryOperation()
{
}
} // namespace Operations
