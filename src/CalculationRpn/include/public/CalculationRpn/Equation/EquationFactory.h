#pragma once

#include <CalculationRpn/Equation/Equation>
#include <CalculationRpn/Equation/EquationX>
#include <CalculationRpn/OperationData.h>

#include <queue>
#include <stack>

namespace Preprocessor
{
class LexemeParser;
}

namespace Equations
{
using namespace Operations;
using namespace Calculation;
using namespace std;
class EquationFactory
{
  public:
    using OperationPtr = shared_ptr<IOperation>;
    using OperationsListPtr = shared_ptr<std::list<OperationPtr>>;
    using OperationsStackPtr = shared_ptr<std::stack<OperationPtr>>;

  private:
    enum OperationType
    {
        Number,
        Function,
        OpenBracket,
        CloseBracket,
        X
    };

  private:
    shared_ptr<Preprocessor::LexemeParser> _parser;
    shared_ptr<OperationsData> _data;

    OperationsListPtr _resultList;
    OperationsStackPtr _tmpStack = make_shared<std::stack<OperationPtr>>();

    shared_ptr<NumberOperation> _x = make_shared<NumberOperation>(0);
    shared_ptr<NumberOperation> _openBracket =
        make_shared<NumberOperation>(0, Priority::OpenBracket, Associativity::Left);

  private:
    void fillList(shared_ptr<queue<string>> lexemes);

    OperationType getOperationType(string &current);

    void closeBracketProcession();
    void numberProcession(string &current);
    void functionAndOperator(string &current);
    void xProcession();

    void leftAssociativeProcession(shared_ptr<IOperation> operation);
    void rightAssociativeProcession(shared_ptr<IOperation> operation);

  public:
    EquationFactory(shared_ptr<OperationsData> data);

    shared_ptr<Equation> CreateEquation(shared_ptr<string> expression);
    shared_ptr<EquationWithX> CreateEquationWithX(shared_ptr<string> expression);
};
} // namespace Equations
