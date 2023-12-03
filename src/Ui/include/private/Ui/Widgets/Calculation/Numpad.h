#pragma once
#include <QGridLayout>
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
    virtual ~Numpad();

  public slots:
    void ButtonClicked();
};
} // namespace Ui
