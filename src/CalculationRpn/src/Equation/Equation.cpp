#include <CalculationRpn/Equation/Equation>

#include <stdexcept>

namespace Equations
{
Equation::Equation(std::shared_ptr<std::list<std::shared_ptr<Operations::IOperation>>> operations)
{
    _operations = operations;
    operations->reverse();
}

double Equation::Execute()
{
    std::list<double> numeric = {};

    for (auto operation : *_operations)
    {
        (*operation)(numeric);
    }

    if (numeric.size() == 1)
    {
        return numeric.front();
    }

    throw std::runtime_error("Invalid equation");
}

double Equation::operator()()
{
    return Execute();
}
} // namespace Equations
