#include "calc.h"
#include <QGridLayout>
#include <QJSEngine>

#include <QDebug>

Calc::Calc(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("Calculator");
    this->resize(400, 580);
    this->setMinimumSize(400, 580);
    this->setMaximumSize(1920, 1080);

    display = new QLineEdit;
    display->setAlignment(Qt::AlignLeft);
    display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    for (std::size_t i = 0; i < countButtons; i++)
    {
        digitButtons[i] = createButton(QString::number(i), &Calc::digitClicked);
    }

    QToolButton* clearButton = createButton("C", &Calc::clearClicked);
    QToolButton* leftBracketButton = createButton("(", &Calc::anotherButtonClicked);
    QToolButton* rightBracketButton = createButton(")", &Calc::anotherButtonClicked);
    QToolButton* pointButton = createButton(".", &Calc::anotherButtonClicked);
    QToolButton* divButton = createButton("/", &Calc::anotherButtonClicked);
    QToolButton* multButton = createButton("*", &Calc::anotherButtonClicked);
    QToolButton* subButton = createButton("-", &Calc::anotherButtonClicked);
    QToolButton* addButton = createButton("+", &Calc::anotherButtonClicked);
    QToolButton* equalButton = createButton("=", &Calc::equalClicked);

    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->addWidget(display, 0, 0, 1, 5);
    mainLayout->addWidget(digitButtons[7], 1, 0);
    mainLayout->addWidget(digitButtons[8], 1, 1);
    mainLayout->addWidget(digitButtons[9], 1, 2);
    mainLayout->addWidget(multButton, 1, 3);
    mainLayout->addWidget(equalButton, 1, 4, 2, 1);
    mainLayout->addWidget(digitButtons[4], 2, 0);
    mainLayout->addWidget(digitButtons[5], 2, 1);
    mainLayout->addWidget(digitButtons[6], 2, 2);
    mainLayout->addWidget(divButton, 2, 3);
    mainLayout->addWidget(digitButtons[1], 3, 0);
    mainLayout->addWidget(digitButtons[2], 3, 1);
    mainLayout->addWidget(digitButtons[3], 3, 2);
    mainLayout->addWidget(addButton, 3, 3);
    mainLayout->addWidget(clearButton, 3, 4);
    mainLayout->addWidget(digitButtons[0], 4, 0);
    mainLayout->addWidget(leftBracketButton, 4, 1);
    mainLayout->addWidget(rightBracketButton, 4, 2);
    mainLayout->addWidget(subButton, 4, 3);
    mainLayout->addWidget(pointButton, 4, 4);

    this->setLayout(mainLayout);
}

void Calc::equalClicked()
{
    QJSEngine engine;
    QJSValue result = engine.evaluate(display->text());
    if (result.isError())
    {
        // pass
    }
    display->setText(QString::number(result.toNumber()));
}

void Calc::anotherButtonClicked()
{
    QToolButton* button = qobject_cast<QToolButton*>(sender());
    if (!button)
    {
        return;
    }
    display->setText(display->text() + button->text());
}

void Calc::clearClicked()
{
    display->setText("");
}

template <typename PointerToSlot>
QToolButton* Calc::createButton(const QString& text, const PointerToSlot& slot)
{
    QToolButton* button = new QToolButton();
    QObject::connect(button, &QToolButton::clicked, this, slot);
    button->setText(text);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return button;
}

void Calc::digitClicked()
{
    QToolButton* button = qobject_cast<QToolButton*>(sender());
    if (!button)
    {
        return;
    }
    int valueOfButton = button->text().toInt();
    display->setText(display->text() + QString::number(valueOfButton));
}
