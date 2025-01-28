#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

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
    void showResultOfExpression();

signals:

private:
    template <typename PointerToSlot>
    QToolButton* createButton(const QString& text, const PointerToSlot& slot);
    void addButtonToHistory(const double resultDouble, const QString& textExpression);

    enum {countButtons = 10};
    QToolButton* digitButtons[countButtons];
    QLineEdit* display;
    QLabel* correctExp;

    QVBoxLayout* buttonLayout;
    QWidget* buttonContainer;
    QScrollArea* scrollArea;
};

#endif // CALC_H
