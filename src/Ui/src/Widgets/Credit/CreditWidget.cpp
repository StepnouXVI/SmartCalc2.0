#include <Ui/Widgets/Credit/CreditWidget>
#include <Ui/Settings>
#include <Ui/Styles/Styles>
#include <Ui/Styles/NumpadStyles>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QRegularExpressionValidator>
#include <Ui/Consts/Consts>
using namespace Ui;

CreditWidget::CreditWidget(ICreditControllerPtr controller, QWidget *pwgt) : QWidget(pwgt), _controller(controller)
{

    // Initialize the CreditWidget and its components
    _sliderInterestRate = createSlider();
    _inputInterestRate = createInputLine();
    _inputTerm = createInputLine();
    _inputAmount = createInputLine();
    _paymentList = std::make_shared<ScrollableList>();
    _TotalOverpaymentLabel = createInfoLabelShared("Total Overpayment:", 5, 2);
    _TotalPayment = createInfoLabelShared("Total Payment:", 5, 2);

    connect(_sliderInterestRate.get(), &QSlider::valueChanged, this, &CreditWidget::SynchronizeSliderAndSpinBox);
    connect(_inputInterestRate.get(), &QLineEdit::textChanged, this, &CreditWidget::SynchronizeSliderAndSpinBox);

    _paymentList->setMinimumSize(10 * Settings::Instance().CellSetting().W, 11 * Settings::Instance().CellSetting().H);

    auto layout = new QGridLayout(this);
    layout->addWidget(_sliderInterestRate.get(), 0, 0, 1, 2);
    layout->addWidget(createInfoLabel("Interest Rate(%):", 2, 2), 1, 0, 1, 1);
    layout->addWidget(_inputInterestRate.get(), 1, 1, 1, 1);
    layout->addWidget(createInfoLabel("Term (Months):", 2, 2), 2, 0, 1, 1);
    layout->addWidget(_inputTerm.get(), 2, 1, 1, 1);
    layout->addWidget(createInfoLabel("Total Amount:", 2, 2), 3, 0, 1, 1);
    layout->addWidget(_inputAmount.get(), 3, 1, 1, 1);
    layout->addWidget(createCalcButton(), 4, 1, 1, 1);
    layout->addWidget(createCreditTypeBox().get(), 4, 0, 1, 1);
    layout->addWidget(_TotalOverpaymentLabel.get(), 4, 2, 1, 1);
    layout->addWidget(_TotalPayment.get(), 4, 3, 1, 1);
    layout->addWidget(_paymentList.get(), 0, 2, 4, 2);

    setLayout(layout);
}

QLabel *Ui::CreditWidget::createPaymentLabel(size_t month, size_t payment)
{
    auto text = QString("Month: %1 | Payment: %2").arg(month).arg(payment);
    auto label = new QLabel(text, this);
    label->setMinimumSize(10 * Settings::Instance().CellSetting().W, 1 * Settings::Instance().CellSetting().H);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet(Styles::OutputLineStyle);

    auto font = label->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 3);
    label->setFont(font);
    return label;
}

QLabel *CreditWidget::createInfoLabel(const QString &text, int w, int h)
{
    auto label = new QLabel(text, this);
    label->setMinimumSize(w * Settings::Instance().CellSetting().W, h * Settings::Instance().CellSetting().H);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet(Styles::OutputLineStyle);

    auto font = label->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H * h / 4);
    label->setFont(font);
    return label;
}

std::shared_ptr<QLabel> CreditWidget::createInfoLabelShared(const QString &text, int w, int h)
{
    auto label = std::make_shared<QLabel>(text, this);
    label->setMinimumSize(w * Settings::Instance().CellSetting().W, h * Settings::Instance().CellSetting().H);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet(Styles::OutputLineStyle);

    auto font = label->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H * h / 6);
    label->setFont(font);
    return label;
}

std::shared_ptr<QLineEdit> CreditWidget::createInputLine()
{
    auto inputRangeLine = std::make_shared<QLineEdit>(this);
    inputRangeLine->setMinimumSize(2 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);

    inputRangeLine->setStyleSheet(Styles::InputRangeLineStyle);
    inputRangeLine->setAlignment(Qt::AlignCenter);
    inputRangeLine->setValidator(new QRegularExpressionValidator(
        QRegularExpression(Consts::UNSIGNED_INT_REGEX), this));

    auto font = inputRangeLine->font();
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    inputRangeLine->setFont(font);

    return inputRangeLine;
}

std::shared_ptr<QSlider> CreditWidget::createSlider()
{
    auto slider = std::make_shared<QSlider>(Qt::Horizontal, this);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(0);
    slider->setMinimumSize(4 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);

    slider->setStyleSheet(Styles::SliderStyle);
    return slider;
}

QPushButton *CreditWidget::createCalcButton()
{
    auto calcButton = new QPushButton("=", this);
    calcButton->setMinimumSize(2 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    calcButton->setStyleSheet(Styles::EqualButtonStyle);
    connect(calcButton, &QPushButton::clicked, this, &UpdatePaymentList);

    auto font = calcButton->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    calcButton->setFont(font);
    return calcButton;
}

std::shared_ptr<QCheckBox> CreditWidget::createCreditTypeBox()
{
    auto checkBox = std::make_shared<QCheckBox>("Is Annuity", this);
    checkBox->setMinimumSize(2 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);

    auto font = checkBox->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    checkBox->setFont(font);

    checkBox->setStyleSheet(Styles::CheckBoxStyle);

    _creditTypeBox = checkBox;
    return checkBox;
}

void CreditWidget::UpdatePaymentList()
{
    _paymentList->ClearItems();
    size_t totalAmount = _inputAmount->text().toULong();
    size_t interestRate = _inputInterestRate->text().toULong();
    size_t term = _inputTerm->text().toULong();
    bool isAnnuity = _creditTypeBox->isChecked();
    auto result = _controller->ComputeCreditInfo(totalAmount, interestRate, term, isAnnuity);

    for (int i = 0; i < result.Payments->size(); i++)
    {
        _paymentList->AddItem(createPaymentLabel(i + 1, result.Payments->at(i)));
    }
    _TotalOverpaymentLabel->setText(QString("Total Overpayment: %1").arg(result.TotalOverpayment));
    _TotalPayment->setText(QString("Total Payment: %1").arg(result.TotalPayment));
}

void CreditWidget::SynchronizeSliderAndSpinBox()
{
    QObject *sender = QObject::sender();
    if (sender == _sliderInterestRate.get())
    {
        _inputInterestRate->setText(QString::number(_sliderInterestRate->value()));
    }
    else
    {
        _sliderInterestRate->setValue(_inputInterestRate->text().toInt());
    }
}
