#include <Ui/Consts/Consts>
#include <Ui/Consts/NumpadPreset>
#include <Ui/Settings>
#include <Ui/Styles/NumpadStyles>
#include <Ui/Widgets/Calculation/Numpad>

namespace Ui
{
    Numpad::Numpad(std::shared_ptr<QLineEdit> inputString, QWidget *pwgt) : QWidget(pwgt)
    {
        _inputString = inputString;
        auto layout = createNumpad();
        setLayout(layout);
    }

    void Numpad::ButtonClicked()
    {
        QString str = ((QPushButton *)sender())->text();
        if (str == "=")
        {
            emit Calculate();
            return;
        }

        QString text = _inputString->text();
        QString last = "";
        text += str;
        _inputString->setText(text);
    }

    QPushButton *Numpad::createButton(const QString &name, int w, int h, QString style)
    {
        QPushButton *pcmd = new QPushButton(name, this);
        pcmd->setMinimumSize(w * Settings::Instance().CellSetting().W, h * Settings::Instance().CellSetting().H);
        connect(pcmd, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
        pcmd->setStyleSheet(style);

        auto font = pcmd->font();
        font.setBold(true);
        font.setPixelSize(Settings::Instance().CellSetting().H / 2);
        pcmd->setFont(font);
        return pcmd;
    }

    QGridLayout *Numpad::createNumpad()
    {
        auto layout = new QGridLayout(this);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                auto but = this->createButton(Consts::ButtonsTemplate[i][j], 2, 2, Styles::ButtonStyles[i][j]);
                layout->addWidget(but, i, j);
            }
        }

        return layout;
    }
} // namespace Ui
