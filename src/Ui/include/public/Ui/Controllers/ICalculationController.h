#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Ui {
using namespace std;

class ICalculationController {
 public:
  void Execute(shared_ptr<string> expression);
  double Execute(shared_ptr<string> expression, double x);
  shared_ptr<vector<double>> Execute(shared_ptr<string> expression,
                                     double start, double end,
                                     size_t numberOfSteps);

 protected:
  virtual ~ICalculationController() = default;
};
}  // namespace Ui
