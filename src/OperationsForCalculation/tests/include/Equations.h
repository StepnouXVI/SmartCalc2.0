#include <CalculationRpn/Equation/EquationFactory.h>
#include <OperationsForCalculation/OperationSet.h>
#include <gtest/gtest.h>
#include <math.h>

using namespace OperationsForCalculation;
using namespace Calculation;
using namespace Equations;

class OperationsTests : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        Data = OperationSet::getInstance().getData();
        Factory = make_shared<EquationFactory>(Data);
    }

    void TearDown() override
    {
    }

  public:
    std::shared_ptr<OperationsData> Data;
    std::shared_ptr<EquationFactory> Factory;
};

// std::shared_ptr<OperationsData> OperationsTests::Data = nullptr;
// std::shared_ptr<EquationFactory> OperationsTests::Factory = nullptr;

TEST_F(OperationsTests, one_plus_one_eq_2)
{
    auto expression = make_shared<string>("1+1");

    ASSERT_TRUE(Factory != nullptr);
    ASSERT_TRUE(Data != nullptr);
    ASSERT_TRUE(Data->Operations != nullptr);
    ASSERT_TRUE(Data->Operators != nullptr);

    auto equation = Factory->CreateEquation(expression);
    auto result = equation->Execute();

    ASSERT_EQ(result, 2);
}

TEST_F(OperationsTests, 2_minus_1_eq_1)
{
    auto expression = make_shared<string>("2-1");

    auto equation = Factory->CreateEquation(expression);
    auto result = equation->Execute();

    ASSERT_EQ(result, 1);
}

TEST_F(OperationsTests, 2_power_3_eq_8)
{
    auto expression = make_shared<string>("2^3");

    auto equation = Factory->CreateEquation(expression);
    auto result = equation->Execute();

    ASSERT_EQ(result, 8);
}

TEST_F(OperationsTests, simple_brackets_correct)
{
    auto expression = make_shared<string>("(2+2)*2");

    auto equation = Factory->CreateEquation(expression);
    auto result = equation->Execute();

    ASSERT_EQ(result, 8);
}

TEST_F(OperationsTests, incorrect_brackets)
{
    auto expression = make_shared<string>("(2+2()");

    auto equation = Factory->CreateEquation(expression);

    ASSERT_THROW(equation->Execute(), std::runtime_error);
}

TEST_F(OperationsTests, incorrect_expression)
{
    auto expression = make_shared<string>("sin(2)cos(4)");

    auto equation = Factory->CreateEquation(expression);

    ASSERT_THROW(equation->Execute(), std::runtime_error);
}

TEST_F(OperationsTests, success_functions)
{
    vector<string> expressions = {"sin(0.5)", "cos(0.5)", "tan(0.5)",  "asin(0.5)", "acos(0.5)", "atan(0.5)",
                                  "log(0.5)", "ln(0.5)",  "sqrt(0.5)", "abs(0.5)",  "3%2",       "3^2"};

    const double answers[] = {sin(0.5),           cos(0.5), tan(0.5),  asin(0.5), acos(0.5), atan(0.5),
                              log(0.5) / log(10), log(0.5), sqrt(0.5), fabs(0.5), 1,         9};

    for (int i = 0; i < expressions.size(); i++)
    {
        auto expression = make_shared<string>(expressions[i]);

        auto equation = Factory->CreateEquation(expression);
        auto result = equation->Execute();
        EXPECT_EQ(result, answers[i]) << "Expression: " << expressions[i];
        ASSERT_EQ(result, answers[i]);
    }
}

TEST_F(OperationsTests, success_operators)
{
    vector<string> expressions = {"2+2", "2-2", "2*2", "2/2", "-2--2", "+2"};

    const double answers[] = {4, 0, 4, 1, 0, 2};

    for (int i = 0; i < expressions.size(); i++)
    {
        auto expression = make_shared<string>(expressions[i]);

        auto equation = Factory->CreateEquation(expression);
        double result = -1;

        EXPECT_NO_THROW(result = equation->Execute()) << "Expression: " << expressions[i];
        EXPECT_EQ(result, answers[i]) << "Expression: " << expressions[i];
        ASSERT_EQ(result, answers[i]);
    }
}

TEST_F(OperationsTests, incorrect_expression_2_operators)
{
    auto expression = make_shared<string>("3+*2");

    auto equation = Factory->CreateEquation(expression);
    ASSERT_THROW(equation->Execute(), std::runtime_error);
}

TEST_F(OperationsTests, incorrect_expression_3_operators)
{
    auto expression = make_shared<string>("*2");

    auto equation = Factory->CreateEquation(expression);

    ASSERT_THROW(equation->Execute(), std::runtime_error);
}
