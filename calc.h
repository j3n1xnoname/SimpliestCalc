#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QToolButton>
#include <QLineEdit>

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

signals:

private:
    template <typename PointerToSlot>
    QToolButton* createButton(const QString& text, const PointerToSlot& slot);

    enum {countButtons = 10};
    QToolButton* digitButtons[countButtons];
    QLineEdit* display;
};

#endif // CALC_H
