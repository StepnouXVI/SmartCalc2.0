#pragma once

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLineEdit>
#include <memory>
#include <QCheckBox>
#include <Ui/Widgets/ScrollableList>
#include <Ui/Controllers/ICreditController>

namespace Ui
{
    class CreditWidget : public QWidget
    {
        Q_OBJECT

    private:
        std::shared_ptr<QSlider> _sliderInterestRate;
        std::shared_ptr<QLineEdit> _inputInterestRate;
        std::shared_ptr<QLineEdit> _inputTerm;
        std::shared_ptr<QLineEdit> _inputAmount;
        std::shared_ptr<ScrollableList> _paymentList;
        std::shared_ptr<QCheckBox> _creditTypeBox;
        std::shared_ptr<QLabel> _TotalOverpaymentLabel;
        std::shared_ptr<QLabel> _TotalPayment;


        QLabel* createPaymentLabel(size_t month, size_t payment);

        ICreditControllerPtr _controller;

        QLabel *createInfoLabel(const QString &text, int w, int h);
        std::shared_ptr<QLineEdit> createInputLine();
        std::shared_ptr<QSlider> createSlider();
        QPushButton *createCalcButton();
        std::shared_ptr<QCheckBox> createCreditTypeBox();

    public:
        explicit CreditWidget(ICreditControllerPtr controller, QWidget *pwgt = nullptr);

    public slots:
        void UpdatePaymentList();
        void SynchronizeSliderAndSpinBox();
    };
} // namespace Ui