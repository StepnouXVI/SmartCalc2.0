#include <Controllers/CreditController>
#include <Credit/Credit>
using namespace Credit;

Ui::TotalCreditInfo Controllers::CreditController::ComputeCreditInfo(size_t totalAmount, size_t interestRate, size_t term, bool isAnnuity)
{
    CreditInfo info;
    info.InterestRate = 0 <= interestRate && interestRate <= 100 ? interestRate : 0;
    info.Term = term;
    info.TotalAmount = totalAmount;
    info.Type = isAnnuity ? Type::Annuity : Type::Diff;
    auto computed = CreditComputation::Compute(info);

    Ui::TotalCreditInfo result;
    result.TotalPayment = computed.TotalPayment;
    result.TotalOverpayment = computed.TotalOverpayment;
    result.Payments = computed.Payments;
    return result;
}
