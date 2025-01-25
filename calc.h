#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calc;
}
QT_END_NAMESPACE

class Calc : public QWidget
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

private slots:
    void on_Button_0_clicked();
    void on_Button_Comma_clicked();
    void on_ButtonClear_clicked();
    void on_Button_3_clicked();
    void on_Button_2_clicked();
    void on_Button_1_clicked();
    void on_Button_6_clicked();
    void on_Button_5_clicked();
    void on_Button_4_clicked();
    void on_Button_9_clicked();
    void on_Button_8_clicked();
    void on_Button_7_clicked();
    void on_ButtonSub_clicked();
    void on_ButtonAdd_clicked();
    void on_ButtonMult_clicked();
    void on_ButtonDiv_clicked();
    void on_ButtonResult_clicked();

    void buttonClickedCommon();

    void on_Button_rightB_clicked();

    void on_Button_leftB_clicked();

private:
    Ui::Calc *ui;

    void addToExpression(const QString& sign);
    QString resultOfExpression();
};
#endif // CALC_H
