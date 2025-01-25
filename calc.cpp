#include "calc.h"
#include "./ui_calc.h"

#include <stdexcept>

#include <QJSEngine>
#include <QDebug>
#include <QPalette>

Calc::Calc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calc)
{
    ui->setupUi(this);
    ui->ButtonResult->setPalette(QPalette(Qt::blue));

    connect(ui->Button_0, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_1, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_2, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_3, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_4, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_5, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_6, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_7, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_8, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->Button_9, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->ButtonDiv, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->ButtonMult, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->ButtonSub, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->ButtonAdd, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
    connect(ui->ButtonClear, &QPushButton::clicked, this, &Calc::buttonClickedCommon);
}

Calc::~Calc()
{
    delete ui;
}

void Calc::buttonClickedCommon()
{
    if (!ui->label->text().isEmpty())
    {
        ui->label->setText(QString());
    }
}

void Calc::addToExpression(const QString& sign)
{
    ui->expressionLine->setText(ui->expressionLine->text() + sign);
}


void Calc::on_Button_0_clicked()
{
    addToExpression("0");
}



void Calc::on_Button_Comma_clicked()
{
    addToExpression(",");
}


void Calc::on_ButtonClear_clicked()
{
    ui->expressionLine->clear();
}


void Calc::on_Button_3_clicked()
{
    addToExpression("3");
}


void Calc::on_Button_2_clicked()
{
    addToExpression("2");
}


void Calc::on_Button_1_clicked()
{
    addToExpression("1");
}


void Calc::on_Button_6_clicked()
{
    addToExpression("6");
}


void Calc::on_Button_5_clicked()
{
    addToExpression("5");
}


void Calc::on_Button_4_clicked()
{
    addToExpression("4");
}


void Calc::on_Button_9_clicked()
{
    addToExpression("9");
}


void Calc::on_Button_8_clicked()
{
    addToExpression("8");
}


void Calc::on_Button_7_clicked()
{
    addToExpression("7");
}


void Calc::on_ButtonSub_clicked()
{
    addToExpression("-");
}


void Calc::on_ButtonAdd_clicked()
{
    addToExpression("+");
}


void Calc::on_ButtonMult_clicked()
{
    addToExpression("×");
}


void Calc::on_ButtonDiv_clicked()
{
    addToExpression("÷");
}


void Calc::on_ButtonResult_clicked()
{
    try
    {
        QString result = resultOfExpression();
        if (!result.isEmpty() && result != "nan")
        {
            ui->expressionLine->setText(result);
        }
    }
    catch (const std::exception& e)
    {
        ui->label->setText(e.what());
    }
}

QString Calc::resultOfExpression()
{
    QJSEngine engine;
    QString expression = ui->expressionLine->text();
    expression.replace("÷", "/");
    expression.replace("×", "*");
    expression.replace(',', '.');
    QJSValue result = engine.evaluate(expression);
    if (result.isError())
    {
        throw std::runtime_error("Недопустимое выражение!");
    }
    return QString::number(result.toNumber()).replace('.', ',');
}


void Calc::on_Button_rightB_clicked()
{
    addToExpression(")");
}


void Calc::on_Button_leftB_clicked()
{
    addToExpression("(");
}

