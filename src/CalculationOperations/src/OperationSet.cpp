#include<Calculation/Operations/BinaryOperation>
#include<Calculation/Operations/UnaryOperation>
#include<CalculationOperations/OperationSet>

#include <cmath>
#include <cstring>

namespace CalculationOperations
{

OperationSet *OperationSet::_instance = nullptr;

OperationSet::OperationSet(){};

OperationSet &OperationSet::getInstance()
{
    if (!_instance)
    {
        _instance = new OperationSet();

        _instance->_data->Operations = make_shared<OperationsHashTable>();
        _instance->_data->Operators = make_shared<set<char>>();
        _instance->fillBinaryOperations();
        _instance->fillUnaryOperations();
    }

    return *_instance;
}

shared_ptr<OperationsData> OperationSet::getData()
{
    return _data;
}

void OperationSet::fillBinaryOperations()
{
    std::pair<const char *, std::function<double(double, double)>> binaryOperations[] = {
        {"+", [](double a, double b) { return a + b; }},          {"-", [](double a, double b) { return a - b; }},
        {"*", [](double a, double b) { return a * b; }},          {"/", [](double a, double b) { return a / b; }},
        {"^", [](double a, double b) { return std::pow(a, b); }}, {"%", [](double a, double b) { return fmod(a, b); }}};

    for (const auto &operation : binaryOperations)
    {
        addBinaryOperation(operation.first, operation.second, Right, operation.first == "^" ? High : Medium);
    }
}

void OperationSet::fillUnaryOperations()
{
    std::pair<const char *, std::function<double(double)>> unaryOperations[] = {
        {"~", [](double a) { return -a; }},
        {"#", [](double a) { return a; }},
        {"sin", [](double a) { return std::sin(a); }},
        {"cos", [](double a) { return std::cos(a); }},
        {"tan", [](double a) { return std::tan(a); }},
        {"asin", [](double a) { return std::asin(a); }},
        {"acos", [](double a) { return std::acos(a); }},
        {"atan", [](double a) { return std::atan(a); }},
        {"log", [](double a) { return std::log(a) / std::log(10); }},
        {"ln", [](double a) { return std::log(a); }},
        {"sqrt", [](double a) { return std::sqrt(a); }},
        {"abs", [](double a) { return std::fabs(a); }}};

    for (const auto &operation : unaryOperations)
    {
        addUnaryOperation(operation.first, operation.second, Left, High);
    }
}

void OperationSet::addBinaryOperation(const char *lexeme, function<double(double, double)> op,
                                      Associativity associativity, Priority priority)
{
    (*_data->Operations)[lexeme] = make_shared<BinaryOperation>(op, associativity, priority);
    if (strlen(lexeme) == 1)
    {
        _data->Operators->insert(lexeme[0]);
    }
}

void OperationSet::addUnaryOperation(const char *lexeme, function<double(double)> op, Associativity associativity,
                                     Priority priority)
{
    (*_data->Operations)[string(lexeme)] = make_shared<UnaryOperation>(op, priority, associativity);
    if (strlen(lexeme))
    {
        _data->Operators->insert(lexeme[0]);
    }
}
} // namespace CalculationOperations
