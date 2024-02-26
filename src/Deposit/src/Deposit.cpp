#include <Deposit/DepositCompute>

namespace Deposit
{

    DepositComputer::DepositComputer(const DepositInfo &info) : _currentState(info)
    {
    }

    DepositComputer::DepositComputer(const DepositInfo &info, std::queue<Payment> &&inputPayments, std::queue<Payment> &&outputPayments) : _currentState(info),
                                                                                                                                           _inputPayments(std::move(inputPayments)),
                                                                                                                                           _outputPayments(std::move(outputPayments))
    {
    }

    EndStatistic DepositComputer::ComputeEndStatistic()
    {

        EndStatistic result = {.Amount = _currentState.InitialAmount, .AccruedInterest = 0, .TotalTax = 0};
        Day currentDay = 1;
        while (currentDay <= _currentState.Term)
        {

            if (!_inputPayments.empty() && _inputPayments.front().DayOfPayment == currentDay)
            {
                result.Amount += _inputPayments.front().Amount;
                _inputPayments.pop();
            }

            if (!_outputPayments.empty() && _outputPayments.front().DayOfPayment == currentDay)
            {
                result.Amount -= _outputPayments.front().Amount;
                _outputPayments.pop();
            }

            if (currentDay % _currentState.PeriodOfPayment == 0)
            {
                Money percent = result.Amount * _currentState.InterestRate / 365.0 * _currentState.PeriodOfPayment;
                if (_currentState.Capitalization)
                {
                    percent += result.AccruedInterest * _currentState.InterestRate / 365.0 * _currentState.PeriodOfPayment;
                }
                result.TotalTax += percent * _currentState.TaxRate;
                result.AccruedInterest += percent * (1.0 - _currentState.TaxRate);
            }
            currentDay++;
        }

        result.Amount += result.AccruedInterest;

        return result;
    }
}
