#include <Ui/Widgets/ScrollableList>
#include <Ui/Styles/Styles>
#include <QVBoxLayout>

namespace Ui
{
    ScrollableList::ScrollableList(QWidget *parent)
        : QScrollArea(parent)
    {
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setWidgetResizable(true);
        setStyleSheet(Styles::ScrollAreaStyle);
    }

    void ScrollableList::AddItem(QWidget *item)
    {
        // Implementation for adding an item to the ScrollableList
        auto container = dynamic_cast<QWidget *>(this->widget());
        if (!container)
        {
            container = new QWidget();
            auto layout = new QVBoxLayout(container);
            container->setLayout(layout);
            this->setWidget(container);
        }

        auto layout = dynamic_cast<QVBoxLayout *>(container->layout());
        if (layout && item)
        {
            layout->addWidget(item);
        }
    }
    void ScrollableList::ClearItems()
    {
        auto container = dynamic_cast<QWidget *>(this->widget());
        if (container)
        {
            delete container;
        }

        this->setWidget(nullptr);
    }
} // namespace Ui
