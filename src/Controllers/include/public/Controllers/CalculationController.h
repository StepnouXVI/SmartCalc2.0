#include <CalculationRpn/Equation/EquationFactory.h>
#include <Ui/Controllers/ICalculationController.h>
namespace Controllers {
class CalculationController : public Ui::ICalculationController {
 private:
  std::shared_ptr<Equations::EquationFactory> _factory = nullptr;

 public:
  CalculationController(std::shared_ptr<Equations::EquationFactory> factory);
  double Execute(const std::string &expression) override;
  double Execute(const std::string &expression, double x) override;
  std::shared_ptr<std::vector<double>> Execute(std::string &expression,
                                               double start, double end,
                                               size_t numberOfSteps) override;
};
}  // namespace Controllers