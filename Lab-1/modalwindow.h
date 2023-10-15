#ifndef MODALWINDOW_H
#define MODALWINDOW_H

#include <QtWidgets>

class ModalWindow : public QGroupBox
{
    Q_OBJECT

    public:
        ModalWindow(QWidget*, QString);
        ~ModalWindow();

    public:
        void                        ReceiveColor();
        void                        ReceiveColor(QColor);

    signals:
        void                        SendColor(QColor);
        void                        SliderMoved(QColor);

    protected slots:
        void                        LineEdit_1_Changed(bool = false);
        void                        LineEdit_2_Changed(bool = false);
        void                        LineEdit_3_Changed(bool = false);
        void                        LineEdit_4_Changed(bool = false);
        void                        Slider_1_Moved();
        void                        Slider_2_Moved();
        void                        Slider_3_Moved();
        void                        Slider_4_Moved();

    protected:
        void                        LineEdit_Changed(QLineEdit*, qint16, qint16, bool);
        void                        RecalculateColor(QColor);

    private:
        QLineEdit*                  LineEdit_1;
        QLineEdit*                  LineEdit_2;
        QLineEdit*                  LineEdit_3;
        QLineEdit*                  LineEdit_4;
        QSlider*                    Slider_1;
        QSlider*                    Slider_2;
        QSlider*                    Slider_3;
        QSlider*                    Slider_4;
        QLabel*                     Label_1;
        QLabel*                     Label_2;
        QLabel*                     Label_3;
        QLabel*                     Label_4;
        QLabel*                     Title;
        QColor                      CurrentColor;
        double                      Red;
        double                      Green;
        double                      Blue;
        double                      Cyan;
        double                      Magenta;
        double                      Yellow;
        double                      Key;
        double                      Hue_1;
        double                      Saturation_1;
        double                      Value;
        double                      Hue_2;
        double                      Saturation_2;
        double                      Lightness;
        double                      X;
        double                      Y;
        double                      Z;
        double                      L;
        double                      A;
        double                      B;
        bool                        SliderRecalculation = false;

};

#endif
