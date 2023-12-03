#include <Ui/Widgets/Calculation/Numpad.h>

using namespace Ui;
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto line = make_shared<QLineEdit>();
    Numpad numpad(line);

    numpad.show();
    return app.exec();
}
