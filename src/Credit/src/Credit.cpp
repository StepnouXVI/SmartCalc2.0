#include <Credit/Credit>
#include <cmath>
#include <stdexcept>

namespace Credit
{

    CreditComputeInfo CreditComputation::ComputeAnnuity(CreditInfo &info)
    {
        CreditComputeInfo result;

        const double monthlyInterestRate = static_cast<double>(info.InterestRate) / 12 / 100;
        const double denominator = std::pow(1.l + monthlyInterestRate, -(static_cast<long>(info.Term)));
        result.MonthlyPayment = (info.TotalAmount * monthlyInterestRate) / (1 - denominator);
        result.TotalPayment = result.MonthlyPayment * info.Term;
        result.TotalOverpayment = result.TotalPayment - info.TotalAmount;

        result.Payments = std::make_shared<std::vector<Money>>(info.Term, result.MonthlyPayment);

        return result;
    }

    CreditComputeInfo CreditComputation::ComputeDiff(CreditInfo info)
    {
        CreditComputeInfo result;
        Money bodyPayment = info.TotalAmount / info.Term, body = info.TotalAmount;
        for (int i = 0; i < info.Term; i++)
        {
            Money payment = bodyPayment + ComputeDiffPayment(body, info.InterestRate, info.Term - i);
            result.Payments->push_back(payment);
            result.TotalPayment += payment;
            body -= bodyPayment;
        }
        result.TotalOverpayment = result.TotalPayment - info.TotalAmount;
        result.MonthlyPayment = result.TotalPayment / info.Term;
        return result;
    }

    Money CreditComputation::ComputeDiffPayment(Money remainder, Percent interestRate, Month term)
    {
        return remainder * interestRate / 12 / 100;
    }

    CreditComputeInfo CreditComputation::Compute(CreditInfo &info)
    {
        switch (info.Type)
        {
        case Type::Annuity:
            return ComputeAnnuity(info);
        case Type::Diff:
            return ComputeDiff(info);
        default:
            throw std::runtime_error("Invalid credit type");
            return CreditComputeInfo();
        }
    }
} // namespace Credit