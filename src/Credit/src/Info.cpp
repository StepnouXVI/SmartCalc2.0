#include <Credit/Info>

namespace Credit
{

    CreditInfo::CreditInfo(Percent interestRate, Month term, Money totalAmount, Credit::Type type)
        : InterestRate(interestRate), Term(term), TotalAmount(totalAmount), Type(type) {}

    CreditComputeInfo::CreditComputeInfo(Money monthlyPayment, Money totalOverpayment, Money totalPayment)
        : MonthlyPayment(monthlyPayment), TotalOverpayment(totalOverpayment), TotalPayment(totalPayment) {}

} // namespace credit