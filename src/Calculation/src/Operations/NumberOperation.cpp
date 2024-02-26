#include <Calculation/Operations/NumberOperation>

namespace Operations
{
    void NumberOperation::SetNumber(double number)
    {
        _n = number;
    }

    Priority NumberOperation::GetPriority() const
    {
        return _priority;
    }

    Associativity NumberOperation::GetAssociativity() const
    {
        return _associativity;
    }

    NumberOperation::NumberOperation(double number)
        : _n(number), _priority(Priority::Low), _associativity(Associativity::Left)
    {
        // Здесь можно добавить логику инициализации объекта NumberOperation
    }

    NumberOperation::NumberOperation(double number, Priority priority, Associativity associativity)
        : _n(number), _priority(priority), _associativity(associativity)
    {
    }

    void NumberOperation::operator()(std::list<double> &stack)
    {
        stack.push_front(_n);
    }

    NumberOperation::~NumberOperation()
    {
    }
} // namespace Operations
