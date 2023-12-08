#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Ui {
using namespace std;

class ICalculationController {
 public:
  virtual double Execute(const string &expression) = 0;
  virtual double Execute(const string &expression, double x) = 0;
  virtual shared_ptr<vector<double>> Execute(string &expression, double start,
                                             double end,
                                             size_t numberOfSteps) = 0;

 protected:
  virtual ~ICalculationController() = default;
};

using ICalculationControllerPtr = shared_ptr<ICalculationController>;
}  // namespace Ui
