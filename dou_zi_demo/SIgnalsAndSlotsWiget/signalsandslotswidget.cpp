#include "signalsandslotswidget.h"
#include "ui_signalsandslotswidget.h"

SignalsAndSlotsWidget::SignalsAndSlotsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignalsAndSlotsWidget)
{
    ui->setupUi(this);
    int max = 100;
    int min = 0;
    ui->horizontalSlider->setMaximum(max);
    ui->horizontalSlider->setMinimum(min);


    QIntValidator *validator = new QIntValidator(min, max, this);
    ui->lineEdit->setValidator(validator);

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &SignalsAndSlotsWidget::sltLineEditChange);
    connect(this, SIGNAL(sigShowVal(QString)), ui->label, SLOT(setText(QString)));
}

SignalsAndSlotsWidget::~SignalsAndSlotsWidget()
{
    delete ui;
}

void SignalsAndSlotsWidget::sltLineEditChange(const QString &text)
{

    int val = text.toInt();
    ui->horizontalSlider->setValue(val);
    emit sigShowVal(text);
}

