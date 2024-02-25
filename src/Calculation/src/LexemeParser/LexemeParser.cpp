#include <Calculation/LexemeParser>

#include <stdexcept>
using namespace Preprocessor;

Preprocessor::LexemeParser::LexemeParser(OperationDataPtr data)
{
    _operationData = data;
}

std::shared_ptr<std::queue<std::string>> LexemeParser::Preprocess(std::shared_ptr<std::string> expression)
{
    _lastSymbolType = operand;
    _result = std::make_shared<std::queue<std::string>>();
    _expression = expression;
    _currentSymbol = _expression->begin();

    while (_currentSymbol != _expression->end())
    {
        getLexeme();
    }

    return _result;
}

void LexemeParser::getLexeme()
{
    auto first = _currentSymbol;

    auto type = getTypeOfSymbol(*_currentSymbol);
    switch (type)
    {
    case digit:
        digitProcession();
        break;
    case letter:
        if (*_currentSymbol == 'e')
            exponentProcession();
        else
            lettersProcession();
        break;
    case operand:
        operatorProcession();
        break;
    case bracket:
        _result->push(std::string(1, *_currentSymbol));
        _currentSymbol++;
        break;
    default:
        _currentSymbol++;
        break;
    }
    _lastSymbolType = type;
}

bool Preprocessor::LexemeParser::isLetter(char symbol)
{
    return symbol >= 'a' && symbol <= 'z';
}
bool Preprocessor::LexemeParser::isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

LexemeParser::SymbolType Preprocessor::LexemeParser::getTypeOfSymbol(char symbol)
{
    if (symbol == ' ')
        return space;

    if (isDigit(symbol))
        return digit;

    if (isLetter(symbol))
        return letter;

    if (symbol == '(' || symbol == ')')
        return bracket;

    if (_operationData->Operators->find(symbol) != _operationData->Operators->end())
        return operand;

    throw std::runtime_error("Unknown symbol in equation.");
}

void Preprocessor::LexemeParser::operatorProcession()
{
    if (_lastSymbolType == operand)
    {
        if (*_currentSymbol == '-')
            _result->push(std::string(1, '~'));
        else if (*_currentSymbol == '+')
            _result->push(std::string(1, '#'));
        else
            _result->push(std::string(1, *_currentSymbol));
    }
    else
    {
        _result->push(std::string(1, *_currentSymbol));
    }
    _currentSymbol++;
}

void Preprocessor::LexemeParser::lettersProcession()
{
    auto start = _currentSymbol;

    while (isLetter(*_currentSymbol))
        _currentSymbol++;

    _result->push(std::string(start, _currentSymbol));
}

void Preprocessor::LexemeParser::exponentProcession()
{
    _result->push(std::string("*"));
    _result->push(std::string("10"));
    _result->push(std::string("^"));
    _currentSymbol++;
}

void Preprocessor::LexemeParser::digitProcession()
{
    auto start = _currentSymbol;
    int dotAmount = 0;

    while (*_currentSymbol == '.' || isDigit(*_currentSymbol))
    {
        dotAmount += *_currentSymbol == '.';

        _currentSymbol++;
    }

    if (dotAmount > 1)
        throw std::runtime_error("Invalid digit.");

    _result->push(std::string(start, _currentSymbol));
}
