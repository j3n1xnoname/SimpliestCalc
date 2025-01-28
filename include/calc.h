#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QToolButton>
#include <QPushButton>
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

    void changeTheme();

signals:

private:
    template <typename PointerToSlot>
    QToolButton* createButton(const QString& text, const PointerToSlot& slot);
    void addButtonToHistory(const double resultDouble, const QString& textExpression);
    void setUpStyle();

    enum {countButtons = 10};
    QToolButton* digitButtons[countButtons];
    QLineEdit* display;
    QLabel* correctExp;

    QVBoxLayout* buttonLayout;
    QWidget* buttonContainer;
    QScrollArea* scrollArea;

    bool isWhiteTheme;
    QPushButton* themeButton;
};

#endif // CALC_H
