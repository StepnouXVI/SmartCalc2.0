#include <CalculationRpn/Equation/Equation>
#include <CalculationRpn/Equation/EquationX>
#include <CalculationRpn/Operations/BinaryOperation.h>
#include <CalculationRpn/Operations/NumberOperation.h>
#include <CalculationRpn/Operations/UnaryOperation.h>
#include <gtest/gtest.h>

using namespace std;
using namespace Operations;
using namespace Equations;

class EquationTests : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        auto add =
            make_shared<BinaryOperation>([](double a, double b) { return a + b; }, Associativity::Left, Priority::Low);
        auto negate = make_shared<UnaryOperation>([](double a) { return -a; }, Priority::Low, Associativity::Left);

        auto n1 = make_shared<NumberOperation>(1);
        auto n2 = make_shared<NumberOperation>(2);

        correctData->push_back(add);
        correctData->push_back(negate);
        correctData->push_back(n1);
        correctData->push_back(n2);

        correctDataWithX->push_back(add);
        correctDataWithX->push_back(negate);
        correctDataWithX->push_back(x);
        correctDataWithX->push_back(n2);

        incorrectData->push_back(n2);
        incorrectData->push_back(n1);

        incorrectSizeData->push_back(add);
    }
    void TearDown() override
    {
        correctData->clear();
        correctDataWithX->clear();
        incorrectData->clear();
        incorrectSizeData->clear();
    }

  public:
    static shared_ptr<NumberOperation> x;
    static shared_ptr<list<shared_ptr<Operations::IOperation>>> correctDataWithX;
    static shared_ptr<list<shared_ptr<Operations::IOperation>>> correctData;
    static double correctDataResult;
    static shared_ptr<list<shared_ptr<Operations::IOperation>>> incorrectSizeData;
    static shared_ptr<list<shared_ptr<Operations::IOperation>>> emptyData;
    static shared_ptr<list<shared_ptr<Operations::IOperation>>> incorrectData;
};

shared_ptr<NumberOperation> EquationTests::x = make_shared<NumberOperation>(1);
shared_ptr<list<shared_ptr<Operations::IOperation>>> EquationTests::correctDataWithX =
    make_shared<list<shared_ptr<Operations::IOperation>>>();
shared_ptr<list<shared_ptr<Operations::IOperation>>> EquationTests::correctData =
    make_shared<list<shared_ptr<Operations::IOperation>>>();
double EquationTests::correctDataResult = 1;
shared_ptr<list<shared_ptr<Operations::IOperation>>> EquationTests::incorrectSizeData =
    make_shared<list<shared_ptr<Operations::IOperation>>>();
shared_ptr<list<shared_ptr<Operations::IOperation>>> EquationTests::emptyData =
    make_shared<list<shared_ptr<Operations::IOperation>>>();
shared_ptr<list<shared_ptr<Operations::IOperation>>> EquationTests::incorrectData =
    make_shared<list<shared_ptr<Operations::IOperation>>>();

TEST_F(EquationTests, Correct)
{
    auto equation = make_shared<Equation>(correctData);
    ASSERT_EQ(equation->Execute(), correctDataResult);
}

TEST_F(EquationTests, IncorrectSize)
{
    auto equation = make_shared<Equation>(incorrectSizeData);
    ASSERT_THROW(equation->Execute(), std::runtime_error);
}

TEST_F(EquationTests, Empty)
{
    auto equation = make_shared<Equation>(emptyData);
    ASSERT_THROW(equation->Execute(), std::runtime_error);
}

TEST_F(EquationTests, Incorrect)
{
    auto equation = make_shared<Equation>(incorrectData);
    ASSERT_THROW(equation->Execute(), std::runtime_error);
}

TEST_F(EquationTests, CorrectWithX)
{
    auto equation = make_shared<EquationWithX>(correctDataWithX, x);
    ASSERT_EQ(equation->Execute(1), correctDataResult);
}

TEST_F(EquationTests, CorrectWithX2)
{
    auto equation = make_shared<EquationWithX>(correctDataWithX, x);
    ASSERT_EQ(equation->Execute(2), correctDataResult - 1);
}
