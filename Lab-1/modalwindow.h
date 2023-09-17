#ifndef MODALWINDOW_H
#define MODALWINDOW_H

#include <QtWidgets>

class ModalWindow : public QGroupBox
{
    Q_OBJECT

public:
    explicit ModalWindow(QWidget *parent = 0, QString Type = "");
    ~ModalWindow();

    void       ReceiveColor();
    void       SendColor(QColor*);
    void       RecalculateColor(QColor);

protected slots:
    void       RecalculateColor_Slot();

private:
    QColor     CurrentColor;
    QColor     NewColor;

    QLineEdit* RedInput;
    QLineEdit* GreenInput;
    QLineEdit* BlueInput;
    QLineEdit* CyanInput;
    QLineEdit* MagentaInput;
    QLineEdit* YellowInput;
    QLineEdit* KeyInput;
    QLineEdit* HueInput_1;
    QLineEdit* SaturationInput_1;
    QLineEdit* ValueInput;
    QLineEdit* HueInput_2;
    QLineEdit* SaturationInput_2;
    QLineEdit* LightnessInput;
    QLineEdit* XInput;
    QLineEdit* YInput;
    QLineEdit* ZInput;
    QLineEdit* LInput;
    QLineEdit* AInput;
    QLineEdit* BInput;

    double Red;
    double Green;
    double Blue;
    double Cyan;
    double Magenta;
    double Yellow;
    double Key;
    double Hue_1;
    double Saturation_1;
    double Value;
    double Hue_2;
    double Saturation_2;
    double Lightness;
    double X;
    double Y;
    double Z;
    double L;
    double A;
    double B;
};

#endif
