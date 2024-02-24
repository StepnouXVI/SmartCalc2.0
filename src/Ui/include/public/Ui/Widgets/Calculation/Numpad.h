#pragma once

#include <Ui/Controllers/ICalculationController>
#include <QGridLayout>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <memory>

namespace Ui
{
using namespace std;

class Numpad : public QWidget
{
    Q_OBJECT
  private:
    shared_ptr<QLineEdit> _inputString;

  private:
    QPushButton *createButton(const QString &name, int w, int h, QString style);
    QGridLayout *createNumpad();

  public:
    Numpad(shared_ptr<QLineEdit> inputString, QWidget *pwgt = 0);

  public slots:
    void ButtonClicked();
  signals:
    void Calculate();

};
} // namespace Ui
