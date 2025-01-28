#include "calc.h"
#include <QGridLayout>
#include <QJSEngine>

#include <QShortcut>

Calc::Calc(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("QWidget {"
                        "font-size: 18px;"
                        "color: black;"
                        "background-color: white;"
                        "}");

    this->setWindowTitle("Calculator");
    this->resize(400, 580);
    this->setMinimumSize(400, 580);
    this->setMaximumSize(1920, 1080);

    QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    QObject::connect(shortcut, &QShortcut::activated, this, &Calc::clearClicked);

    display = new QLineEdit;
    display->setAlignment(Qt::AlignLeft);
    display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QObject::connect(display, &QLineEdit::textChanged, this, &Calc::displayTextChanged);
    QObject::connect(display, &QLineEdit::returnPressed, this, &Calc::equalClicked);

    correctExp = new QLabel();

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

    equalButton->setStyleSheet("QToolButton {"
                               "font-size: 18px;"
                               "color: white;"
                               "background-color: blue;"
                               "}");

    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->addWidget(display, 0, 0, 1, 5);
    mainLayout->addWidget(correctExp, 1, 0, 1, 5);
    mainLayout->addWidget(digitButtons[7], 2, 0);
    mainLayout->addWidget(digitButtons[8], 2, 1);
    mainLayout->addWidget(digitButtons[9], 2, 2);
    mainLayout->addWidget(multButton, 2, 3);
    mainLayout->addWidget(equalButton, 2, 4, 2, 1);
    mainLayout->addWidget(digitButtons[4], 3, 0);
    mainLayout->addWidget(digitButtons[5], 3, 1);
    mainLayout->addWidget(digitButtons[6], 3, 2);
    mainLayout->addWidget(divButton, 3, 3);
    mainLayout->addWidget(digitButtons[1], 4, 0);
    mainLayout->addWidget(digitButtons[2], 4, 1);
    mainLayout->addWidget(digitButtons[3], 4, 2);
    mainLayout->addWidget(addButton, 4, 3);
    mainLayout->addWidget(clearButton, 4, 4);
    mainLayout->addWidget(digitButtons[0], 5, 0);
    mainLayout->addWidget(leftBracketButton, 5, 1);
    mainLayout->addWidget(rightBracketButton, 5, 2);
    mainLayout->addWidget(subButton, 5, 3);
    mainLayout->addWidget(pointButton, 5, 4);

    this->setLayout(mainLayout);
}

void Calc::equalClicked()
{
    QJSEngine engine;
    QJSValue result = engine.evaluate(display->text());
    if (result.isError() || result.toString() == "nan")
    {
        correctExp->setText("Некорректное выражение");
        return;
    }
    display->setText(QString::number(result.toNumber()));
}

void Calc::displayTextChanged()
{
    correctExp->setText("");
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
