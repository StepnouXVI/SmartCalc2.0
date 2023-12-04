#include <CalculationRpn/Equation/EquationFactory.h>
#include <CalculationRpn/LexemeParser/LexemeParser.h>
#include <CalculationRpn/Operations/NumberOperation.h>

#include <stdexcept>
namespace Equations {
using namespace Preprocessors;

EquationFactory::EquationFactory(shared_ptr<OperationsData> data) {
  _data = data;
  _parser = make_shared<LexemeParser>(_data);
}

shared_ptr<Equation> EquationFactory::CreateEquation(
    shared_ptr<string> expression) {
  auto lexemes = _parser->Preprocess(expression);
  _resultList = make_shared<std::list<OperationPtr>>();

  fillList(lexemes);
  return make_shared<Equation>(_resultList);
}

shared_ptr<EquationWithX> EquationFactory::CreateEquationWithX(
    shared_ptr<string> expression) {
  auto lexemes = _parser->Preprocess(expression);
  _resultList = make_shared<std::list<OperationPtr>>();

  fillList(lexemes);
  return make_shared<EquationWithX>(_resultList, _x);
}

void EquationFactory::fillList(shared_ptr<queue<string>> lexemes) {
  for (; lexemes->size() > 0; lexemes->pop()) {
    auto lexeme = lexemes->front();

    switch (getOperationType(lexeme)) {
      case Number:
        numberProcession(lexeme);
        break;
      case Function:
        functionAndOperator(lexeme);
        break;
      case OpenBracket:
        _tmpStack->push(_openBracket);
        break;
      case CloseBracket:
        closeBracketProcession();
        break;
      case X:
        xProcession();
        break;
    }
  }

  while (!_tmpStack->empty()) {
    _resultList->push_front(_tmpStack->top());
    _tmpStack->pop();
  }
}

EquationFactory::OperationType EquationFactory::getOperationType(
    string &current) {
  if (current == "(") return OpenBracket;
  if (current == ")") return CloseBracket;
  if (current == "x") return X;

  if (current[0] >= '0' && current[0] <= '9') return Number;

  return Function;
}

void EquationFactory::closeBracketProcession() {
  while (!_tmpStack->empty() &&
         _tmpStack->top()->GetPriority() != Priority::OpenBracket) {
    _resultList->push_front(_tmpStack->top());
    _tmpStack->pop();
  }

  if (_tmpStack->empty()) {
    throw runtime_error("Invalid equation. Bracket error.");
  }

  _tmpStack->pop();
}

void EquationFactory::numberProcession(string &current) {
  double number = stod(current);
  _resultList->push_front(make_shared<NumberOperation>(number));
}

void EquationFactory::functionAndOperator(string &current) {
  auto operationPair = _data->Operations->find(current);

  if (operationPair == _data->Operations->end()) {
    throw runtime_error("Invalid function or operator in equation.");
  }

  auto operation = operationPair->second;

  if (operation->GetAssociativity() == Associativity::Left) {
    leftAssociativeProcession(operation);
  } else {
    rightAssociativeProcession(operation);
  }
}

void EquationFactory::xProcession() { _resultList->push_front(_x); }
}  // namespace Equations

void Equations::EquationFactory::leftAssociativeProcession(
    shared_ptr<IOperation> operation) {
  while (!_tmpStack->empty() &&
         operation->GetPriority() < _tmpStack->top()->GetPriority()) {
    _resultList->push_front(_tmpStack->top());
    _tmpStack->pop();
  }

  _tmpStack->push(operation);
}

void Equations::EquationFactory::rightAssociativeProcession(
    shared_ptr<IOperation> operation) {
  while (!_tmpStack->empty() &&
         operation->GetPriority() <= _tmpStack->top()->GetPriority()) {
    _resultList->push_front(_tmpStack->top());
    _tmpStack->pop();
  }

  _tmpStack->push(operation);
}
