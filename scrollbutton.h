#ifndef SCROLLBUTTON_H
#define SCROLLBUTTON_H

#include <QToolButton>

class ScrollButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ScrollButton(QWidget* parent = nullptr, double res_ = 0, QString exp_ = "");

    double getResult() const {return result;}

private:
    double result;
    QString expression;
};

#endif // SCROLLBUTTON_H
