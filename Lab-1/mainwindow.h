#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "modalwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        QColor                      getColor();
        void                        setColor(QColor);
        void                        GenerateModals();

    protected slots:
        void                        MenuModals_Slot();
        void                        MenuModalsOptions_Slot();
        void                        MenuInfo_Slot();
        void                        MenuColor_Slot();

    private:
        QColor                      CurrentColor;

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
};

#endif
