#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    protected slots:
        void MenuInfo_Slot();
        void MenuColor_Slot();
        void MenuOption_Slot();

    private:
        QGroupBox*      Tab;
        QLabel*         Title;

        QGroupBox*      Menu;
        QPushButton*    MenuOption;
        QPushButton*    MenuColor;
        QPushButton*    MenuInfo;

        QGroupBox*      States;
        QLabel*         CurrentState;

        QGroupBox*      Info;
        QLabel*         InfoTitle;
        QLabel*         InfoText;

        QGroupBox*      Options;

        QColor          CurrentColor;











        /*QGroupBox*    Game;
        QLabel*       InputDescription;
        QLineEdit*    Input;
        QPushButton*  SendInput;
        QTableWidget* GameStory;
        QGroupBox*    GameStoryWrapper;
        QGroupBox*    SetRecord;
        QLabel*       SetRecordText;
        QLabel*       SetRecordTitle;
        QLineEdit*    SetRecordForm;
        QPushButton*  SetRecordButton;
        QGroupBox*    Finish;
        QPushButton*  FinishSave;
        QPushButton*  FinishCancel;
        QLabel*       FinishTitle;
        QLabel*       FinishText;
        QGroupBox*    AlertMenu;
        QLabel*       AlertMenuTitle;
        QLabel*       AlertMenuText;
        QPushButton*  AlertBack;*/
};

#endif
