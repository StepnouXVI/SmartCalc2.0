#pragma once

#include <QWidget>
#include <QListWidget>
#include <QScrollArea>
#include <QVBoxLayout>

#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <set>
#include <string>
#include <QObject>

namespace Ui
{
  class ScrollableList : public QScrollArea
  {
    Q_OBJECT
  private:
    std::shared_ptr<QLineEdit> _inputString = nullptr;

  public:
    ScrollableList(QWidget *parent = nullptr);
    void AddItem(QWidget* item);
    void ClearItems();
  };
} // namespace Ui