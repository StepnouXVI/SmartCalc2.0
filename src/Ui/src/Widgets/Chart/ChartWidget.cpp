#include <Ui/Widgets/Chart/ChartWidget>
#include <QGridLayout>
#include <Ui/Settings>
#include <Ui/Consts/Consts>
#include <QRegularExpressionValidator>
#include <Ui/Styles/NumpadStyles>
#include <Ui/Styles/Styles>
#include <Ui/Synchronizer>

using namespace Ui;

ChartWidget::ChartWidget(CalculationControllerPtr controller, QWidget *pwgt)
    : QWidget(pwgt), _controller(controller)
{

    // set hotkey (numpad enter and basic enter)
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    connect(shortcut, &QShortcut::activated, this, &Draw);
    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated, this, &Draw);

    _inputString = Synchronizer::GetNewLine();
    // Create output display line
    _outputString = createOutputLine();
    auto layout = new QGridLayout(this);

    // Create input range lines
    for (int i = 0; i < 4; ++i)
    {
        _rangeInputStrings[i] = createInputRangeLine(Consts::DEFAULT_INPUT_RANGE_LINES_TEXT[i]);
        layout->addWidget(_rangeInputStrings[i].get(), i, 0, 1, 1);
    }
    layout->addWidget(_outputString.get(), 4, 1, 1, 1);
    layout->addWidget(createDrawButton(), 4, 0, 1, 1);
    layout->addWidget(createPlot().get(), 0, 1, 4, 1);
    layout->addWidget(_inputString.get(), 5, 0, 1, 2);

    setLayout(layout);
    Draw();
}

std::shared_ptr<QLabel> ChartWidget::createOutputLine()
{
    _outputString = std::make_shared<QLabel>(this);
    _outputString->setMinimumSize(10 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    _outputString->setText(Consts::DEFAULT_OUTPUT_STRING_TEXT);
    _outputString->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    _outputString->setStyleSheet(Styles::OutputLineStyle);

    auto font = _outputString->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    font.setItalic(true);
    _outputString->setFont(font);

    return _outputString;
}

std::shared_ptr<QLineEdit> ChartWidget::createInputRangeLine(QString placeHolder)
{
    auto inputRangeLine = std::make_shared<QLineEdit>(this);
    inputRangeLine->setPlaceholderText(placeHolder);
    inputRangeLine->setMinimumSize(2 * Settings::Instance().CellSetting().W, 1 * Settings::Instance().CellSetting().H);
    inputRangeLine->setStyleSheet(Styles::InputRangeLineStyle);
    inputRangeLine->setAlignment(Qt::AlignCenter);
    inputRangeLine->setValidator(new QRegularExpressionValidator(
        QRegularExpression(Consts::DOUBLE_REGEX), this));

    auto font = inputRangeLine->font();
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    inputRangeLine->setFont(font);

    return inputRangeLine;
}

QPushButton *ChartWidget::createDrawButton()
{
    auto drawButton = new QPushButton("Draw", this);
    drawButton->setMinimumSize(4 * Settings::Instance().CellSetting().W, 2 * Settings::Instance().CellSetting().H);
    drawButton->setStyleSheet(Styles::OperandButtonStyle);

    auto font = drawButton->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    drawButton->setFont(font);
    connect(drawButton, &QPushButton::clicked, this, &Draw);
    return drawButton;
}

std::shared_ptr<QCustomPlot> ChartWidget::createPlot()
{
    this->_plot = std::make_shared<QCustomPlot>(this);
    _plot->setMinimumSize(10 * Settings::Instance().CellSetting().W, 8 * Settings::Instance().CellSetting().H);
    _plot->addGraph();
    _plot->setBackground(QColor("#1A2030"));
    _plot->setBaseSize(10 * Settings::Instance().CellSetting().W, 8 * Settings::Instance().CellSetting().H);
    _plot->xAxis->setLabel("x");
    _plot->graph()->setBrush(QBrush(QColor("#4cc2ff")));
    _plot->yAxis->setLabel("y");
    auto pen = QPen(QColor("#ffffff"));
    pen.setWidth(2);
    _plot->graph(0)->setPen(pen);
    _plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    return _plot;
}

void ChartWidget::getRanges(double *ranges)
{
    for (int i = 0; i < 4; i++)
    {
        bool ok = false;
        double number = _rangeInputStrings[i]->text().toDouble(&ok);
        ranges[i] = ok ? number : Consts::DEFAULT_INPUT_RANGE_VALUES[i];
    }
}

void ChartWidget::Draw()
{
    double ranges[4];
    getRanges(ranges);

    _plot->xAxis->setRange(ranges[0], ranges[1]);
    _plot->yAxis->setRange(ranges[2], ranges[3]);

    double y[1000];
    QVector<double> x(1000);
    for (int i = 0; i < 1000; i++)
    {
        x[i] = ranges[0] + i * (ranges[1] - ranges[0]) / 1000.0;
    }

    auto text = _inputString->text();
    if (text.isEmpty())
    {
        text = "sin(x)/x";
    }

    try
    {
        auto y_vec = _controller->Execute(std::make_shared<std::string>(text.toStdString()), ranges[0], ranges[1], 1000);
        QVector<double> v_y(y_vec->begin(), y_vec->end());
        _outputString->setText("Success");
        _plot->graph(0)->setData(x, v_y);
        _plot->replot();
    }
    catch (const std::exception &e)
    {
        _outputString->setText(QString::fromStdString(e.what()));
    }
}
