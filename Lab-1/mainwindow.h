#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "modalwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public:
        QColor                      SendColor();

    protected slots:
        void                        MenuModals_Slot();
        void                        MenuModalsOptions_Slot();
        void                        MenuInfo_Slot();
        void                        MenuColor_Slot();
        void                        ReceiveColor(QColor);

    protected:
        void                        GenerateModals();

    private:
        QColor                      CurrentColor = QColor(0,0,0);
        QGroupBox*                  CurrentColorBox;

        QGroupBox*                  Tab;
        QLabel*                     Title;

        QGroupBox*                  Menu;
        QPushButton*                MenuModals;
        QPushButton*                MenuColor;
        QPushButton*                MenuInfo;

        QGroupBox*                  Info;
        QLabel*                     InfoTitle;
        QLabel*                     InfoText;

        QGroupBox*                  MenuModalsOptions;
        QPushButton*                MenuModalsOptionsRGB;
        QPushButton*                MenuModalsOptionsCMYK;
        QPushButton*                MenuModalsOptionsHSV;
        QPushButton*                MenuModalsOptionsHLS;
        QPushButton*                MenuModalsOptionsXYZ;
        QPushButton*                MenuModalsOptionsLAB;

        QGroupBox*                  Modals;
        QVector<QString>*           ModalList = new QVector<QString>;
        QHBoxLayout*                ModalLayout;
        ModalWindow*                Modal_1;
        ModalWindow*                Modal_2;
        ModalWindow*                Modal_3;

};

#endif
