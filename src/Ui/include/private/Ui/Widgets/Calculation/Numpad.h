#pragma once
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <memory>

namespace Ui {
using namespace std;

class Numpad : public QWidget {
  Q_OBJECT

 public:
  Numpad(QWidget *parent = nullptr);
  ~Numpad();
};
}  // namespace Ui
