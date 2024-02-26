#include <Controllers\CalculationController>
namespace Controllers
{
    using namespace std;
    using namespace Calculation;
    using namespace Equations;

    CalculationController::CalculationController(shared_ptr<OperationsData> _data)
        : Data(_data), Factory(make_shared<EquationFactory>(_data)) {}

    double CalculationController::Execute(shared_ptr<string> expression)
    {
        auto equation = Factory->CreateEquation(expression);
        return equation->Execute();
    }

    double CalculationController::Execute(shared_ptr<string> expression, double x)
    {
        auto equationWithX = Factory->CreateEquationWithX(expression);
        return equationWithX->Execute(x);
    }

    shared_ptr<vector<double>> CalculationController::Execute(shared_ptr<string> expression, double start, double end, size_t numberOfSteps)
    {
        auto equationWithX = Factory->CreateEquationWithX(expression);
        auto results = make_shared<vector<double>>();
        equationWithX->Execute(start, end, numberOfSteps, *results);
        return results;
    }
}
