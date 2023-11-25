#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets>

enum dialogType{
    segment,
    circle
};

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(dialogType, QWidget*pwgt = 0);
    QPointF getP0(){
        return p0;
    }
    QPointF getP1(){
        return p1;
    }
    int getRadius(){
        return radius;
    }
private:
    QGridLayout * l;
    QPointF p0;
    QPointF p1;
    int radius;
    dialogType type;
    QLineEdit *leX0 = new QLineEdit;
    QLineEdit *leY0 = new QLineEdit;
    QLineEdit *leX1 = new QLineEdit;
    QLineEdit *leY1 = new QLineEdit;
    QLineEdit *leRadius = new QLineEdit;
private slots:
    void setX0(){
        if (leX0->text().toInt() > 9) {
            p0.setX(9);
            return;
        }
        if (leX0->text().toInt() < -9) {
            p0.setX(-9);
            return;
        }
        p0.setX(leX0->text().toInt());
    }
    void setX1(){
        if (leX1->text().toInt() > 9) {
            p1.setX(9);
            return;
        }
        if (leX1->text().toInt() < -9) {
            p1.setX(-9);
            return;
        }
        p1.setX(leX1->text().toInt());
    }
    void setY0(){
        if (leY0->text().toInt() > 9) {
            p0.setY(9);
            return;
        }
        if (leY0->text().toInt() < -9) {
            p0.setY(-9);
            return;
        }
        p0.setY(leY0->text().toInt());
    }
    void setY1(){
        if (leY1->text().toInt() > 9) {
            p1.setY(9);
            return;
        }
        if (leY1->text().toInt() < -9) {
            p1.setY(-9);
            return;
        }
        p1.setY(leY1->text().toInt());
    }
    void setRadius(){
        if (leRadius->text().toInt() > 7) {
            radius = 7;
            return;
        }
        if (leY0->text().toInt() < 0) {
            radius = 0;
            return;
        }
        radius = leRadius->text().toInt();
    }
};

#endif
