#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>

class Calc : public QWidget
{
    Q_OBJECT
public:
    explicit Calc(QWidget *parent = nullptr);

private slots:
    void digitClicked();
    void clearClicked();
    void equalClicked();
    void anotherButtonClicked();

    void displayTextChanged();

signals:

private:
    template <typename PointerToSlot>
    QToolButton* createButton(const QString& text, const PointerToSlot& slot);

    enum {countButtons = 10};
    QToolButton* digitButtons[countButtons];
    QLineEdit* display;
    QLabel* correctExp;
};

#endif // CALC_H
