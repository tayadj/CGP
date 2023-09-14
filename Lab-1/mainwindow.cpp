#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(QSize(1440,900));
    setWindowTitle(QString("CGP-1"));

    Tab = new QGroupBox(this);
    Tab->setGeometry(QRect(0,0,1440,80));
    Tab->setStyleSheet(QString("background-color: #ffffff;"
                               "border-radius: 0px;"));

    Title = new QLabel(Tab);
    Title->setText(QString("Lab #1"));
    Title->setFont(QFont("Segoe UI Black",32));
    Title->setGeometry(QRect(120,6,400,68));

    Menu = new QGroupBox(this);
    Menu->setGeometry(QRect(120,140,400,220));
    Menu->setStyleSheet(QString("border-radius: 10px;"));

    MenuOption = new QPushButton(Menu);
    MenuOption->setObjectName(QString("MenuOption"));
    MenuOption->setText(QString("Edit models"));
    MenuOption->setFont(QFont("Segoe UI Black",16));
    MenuOption->setGeometry(QRect(0,0,196,60));
    MenuOption->setStyleSheet(QString("#MenuOption:hover {"
                                      "    background-color: #f8f8f8;"
                                      "}"));
    connect(MenuOption,SIGNAL(clicked()),this,SLOT(MenuOption_Slot()));

    MenuColor = new QPushButton(Menu);
    MenuColor->setObjectName(QString("MenuColor"));
    MenuColor->setText(QString("Choose color"));
    MenuColor->setFont(QFont("Segoe UI Black",16));
    MenuColor->setGeometry(QRect(0,80,212,60));
    MenuColor->setStyleSheet(QString("#MenuColor:hover {"
                                     "    background-color: #f8f8f8;"
                                     "}"));
    connect(MenuColor,SIGNAL(clicked()),this,SLOT(MenuColor_Slot()));

    MenuInfo = new QPushButton(Menu);
    MenuInfo->setObjectName(QString("MenuInfo"));
    MenuInfo->setText(QString("FAQ"));
    MenuInfo->setFont(QFont("Segoe UI Black",16));
    MenuInfo->setGeometry(QRect(0,160,80,60));
    MenuInfo->setStyleSheet(QString("#MenuInfo:hover {"
                                    "    background-color: #f8f8f8;"
                                    "}"));
    connect(MenuInfo,SIGNAL(clicked()),this,SLOT(MenuInfo_Slot()));

    Info = new QGroupBox(this);
    Info->setVisible(false);
    Info->setGeometry(QRect(520,120,800,300));
    Info->setStyleSheet(QString("background-color: #f8f8f8;"
                                "border-radius: 10px;"));

    InfoTitle = new QLabel(Info);
    InfoTitle->setGeometry(QRect(20,20,760,80));
    InfoTitle->setText(QString("Guide on this project"));
    InfoTitle->setAlignment(Qt::AlignHCenter);
    InfoTitle->setWordWrap(true);
    InfoTitle->setFont(QFont("Segoe UI Black",16));

    InfoText = new QLabel(Info);
    InfoText->setGeometry(QRect(20,100,760,200));
    InfoText->setText(QString("This program is used to work with various representations of color in the computer. In it, you can choose a color by directly clicking on the \"Choose color\" button, change the current color representation models by directly clicking on the \"Change model\" button."));
    InfoText->setAlignment(Qt::AlignJustify);
    InfoText->setWordWrap(true);
    InfoText->setFont(QFont("Segoe UI Black",12));


    States = new QGroupBox(this);
    States->setGeometry(QRect(120,380,300,100));
    States->setStyleSheet(QString("background-color: #f8f8f8;"
                                 "border-radius: 10px;"));

    CurrentState = new QLabel(States);
    CurrentState->setGeometry(QRect(20,20,260,80));
    CurrentState->setText(QString("No model is selected in the program."));
    CurrentState->setAlignment(Qt::AlignHCenter);
    CurrentState->setWordWrap(true);
    CurrentState->setFont(QFont("Segoe UI Black",12));

    Options = new QGroupBox(this);
    Options->setVisible(false);
    Options->setGeometry(QRect(520,120,800,360));
    Options->setStyleSheet(QString("background-color: #f8f8f8;"
                                   "border-radius: 10px;"));

    OptionRGB = new QPushButton(Options);
    OptionRGB->setObjectName("OptionRGB");
    OptionRGB->setGeometry(QRect(20,20,180,80));
    OptionRGB->setFont(QFont("Segoe UI Black",12));
    OptionRGB->setText("RGB");
    OptionRGB->setStyleSheet(QString("#OptionRGB {"
                                     "  background-color: #fdfdfd;"
                                     "  border-radius: 10px;"
                                     "}"
                                     "#OptionRGB:hover {"
                                     "  background-color: #fbfbfb;"
                                     "}"));
    connect(OptionRGB,SIGNAL(clicked()),this,SLOT(OptionRGB_Slot()));



    /*AlertMenu = new QGroupBox(this);
    AlertMenu->setVisible(false);
    AlertMenu->setGeometry(QRect(520,120,800,280));
    AlertMenu->setStyleSheet(QString("background-color: #f8f8f8;"
                                     "border-radius: 10px;"));

    AlertMenuTitle = new QLabel(AlertMenu);
    AlertMenuTitle->setGeometry(QRect(20,20,760,80));
    AlertMenuTitle->setText(QString("Oops!"));
    AlertMenuTitle->setAlignment(Qt::AlignHCenter);
    AlertMenuTitle->setWordWrap(true);
    AlertMenuTitle->setFont(QFont("Segoe UI Black",16));

    AlertMenuText = new QLabel(AlertMenu);
    AlertMenuText->setGeometry(QRect(20,100,760,360));
    AlertMenuText->setAlignment(Qt::AlignJustify);
    AlertMenuText->setWordWrap(true);
    AlertMenuText->setFont(QFont("Segoe UI Black",12));

    AlertBack = new QPushButton(AlertMenu);
    AlertBack->setObjectName("SendInput");
    AlertBack->setGeometry(QRect(340,200,120,60));
    AlertBack->setFont(QFont("Segoe UI Black",12));
    AlertBack->setText("Got it");
    AlertBack->setStyleSheet(QString("#SendInput {"
                                     "  background-color: #ffffff;"
                                     "  border-radius: 10px;"
                                     "}"
                                     "#SendInput:hover {"
                                     "  background-color: #fcfcfc;"
                                     "  border: 0px;"
                                     "}"));

    Game = new QGroupBox(this);
    Game->setVisible(false);
    Game->setGeometry(QRect(520,120,800,680));
    Game->setStyleSheet(QString("background-color: #f8f8f8;"
                                "border-radius: 10px;"));

    Input = new QLineEdit(Game);
    Input->setGeometry(QRect(270,20,290,60));
    Input->setFont(QFont("Segoe UI Black",16));
    Input->setInputMask("9999");
    Input->setStyleSheet(QString("background-color: #ffffff;"
                                 "border-radius: 10px;"
                                 "padding-left: 10px;"));

    InputDescription = new QLabel(Game);
    InputDescription->setGeometry(QRect(20,20,240,60));
    InputDescription->setFont(QFont("Segoe UI Black",16));
    InputDescription->setText(QString("Input number:"));

    SendInput = new QPushButton(Game);
    SendInput->setObjectName("SendInput");
    SendInput->setGeometry(QRect(580,20,200,60));
    SendInput->setFont(QFont("Segoe UI Black",16));
    SendInput->setText("Attempt");
    SendInput->setStyleSheet(QString("#SendInput {"
                                     "  background-color: #ffffff;"
                                     "  border-radius: 10px;"
                                     "}"
                                     "#SendInput:hover {"
                                     "  background-color: #fcfcfc;"
                                     "  border: 0px;"
                                     "}"));

    GameStoryWrapper = new QGroupBox(Game);
    GameStoryWrapper->setGeometry(QRect(20,100,760,560));
    GameStoryWrapper->setStyleSheet(QString("background-color: #ffffff;"
                                            "border-radius: 10px;"));

    GameStory = new QTableWidget(GameStoryWrapper);
    GameStory->setObjectName("GameStory");
    GameStory->setGeometry(QRect(20,20,720,520));
    GameStory->setFont(QFont("Segoe UI Black",12));
    GameStory->setColumnCount(2);
    GameStory->setColumnWidth(0,340);
    GameStory->setColumnWidth(1,340);
    GameStory->setHorizontalHeaderItem(0,new QTableWidgetItem("Attempt's number"));
    GameStory->setHorizontalHeaderItem(1,new QTableWidgetItem("Result"));
    GameStory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    GameStory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    GameStory->horizontalHeaderItem(0)->setFont(QFont("Segoe UI Black",12));
    GameStory->horizontalHeaderItem(1)->setFont(QFont("Segoe UI Black",12));

    Finish = new QGroupBox(this);
    Finish->setVisible(false);
    Finish->setGeometry(QRect(520,120,800,280));
    Finish->setStyleSheet(QString("background-color: #f8f8f8;"
                                  "border-radius: 10px;"));

    FinishTitle = new QLabel(Finish);
    FinishTitle->setGeometry(QRect(20,20,760,80));
    FinishTitle->setText(QString("Congratulations!"));
    FinishTitle->setAlignment(Qt::AlignHCenter);
    FinishTitle->setWordWrap(true);
    FinishTitle->setFont(QFont("Segoe UI Black",16));

    FinishText = new QLabel(Finish);
    FinishText->setGeometry(QRect(20,80,760,100));
    FinishText->setAlignment(Qt::AlignJustify);
    FinishText->setWordWrap(true);
    FinishText->setFont(QFont("Segoe UI Black",12));

    FinishCancel = new QPushButton(Finish);
    FinishCancel->setObjectName("FinishCancel");
    FinishCancel->setGeometry(QRect(220,200,160,60));
    FinishCancel->setFont(QFont("Segoe UI Black",16));
    FinishCancel->setText("Cancel");
    FinishCancel->setStyleSheet(QString("#FinishCancel {"
                                        "  background-color: #ffffff;"
                                        "  border-radius: 10px;"
                                        "}"
                                        "#FinishCancel:hover {"
                                        "  background-color: #fcfcfc;"
                                        "  border: 0px;"
                                        "}"));

    FinishSave = new QPushButton(Finish);
    FinishSave->setObjectName("FinishSave");
    FinishSave->setGeometry(QRect(420,200,160,60));
    FinishSave->setFont(QFont("Segoe UI Black",16));
    FinishSave->setText("Save");
    FinishSave->setStyleSheet(QString("#FinishSave {"
                                      "  background-color: #ffffff;"
                                      "  border-radius: 10px;"
                                      "}"
                                      "#FinishSave:hover {"
                                      "  background-color: #fcfcfc;"
                                      "  border: 0px;"
                                      "}"));

    SetRecord = new QGroupBox(this);
    SetRecord->setVisible(false);
    SetRecord->setGeometry(QRect(520,120,800,280));
    SetRecord->setStyleSheet(QString("background-color: #f8f8f8;"
                                     "border-radius: 10px;"));

    SetRecordTitle = new QLabel(SetRecord);
    SetRecordTitle->setGeometry(QRect(20,20,760,80));
    SetRecordTitle->setText(QString("One last moment"));
    SetRecordTitle->setAlignment(Qt::AlignHCenter);
    SetRecordTitle->setWordWrap(true);
    SetRecordTitle->setFont(QFont("Segoe UI Black",16));

    SetRecordText = new QLabel(SetRecord);
    SetRecordText->setGeometry(QRect(20,115,240,100));
    SetRecordText->setAlignment(Qt::AlignJustify);
    SetRecordText->setText(QString("Input your name: "));
    SetRecordText->setWordWrap(true);
    SetRecordText->setFont(QFont("Segoe UI Black",12));

    SetRecordForm = new QLineEdit(SetRecord);
    SetRecordForm->setGeometry(QRect(240,100,540,60));
    SetRecordForm->setFont(QFont("Segoe UI Black",12));
    SetRecordForm->setStyleSheet(QString("background-color: #ffffff;"
                                         "border-radius: 10px;"
                                         "padding-left: 10px;"));

    SetRecordButton = new QPushButton(SetRecord);
    SetRecordButton->setObjectName("SetRecordButton");
    SetRecordButton->setGeometry(QRect(320,200,160,60));
    SetRecordButton->setFont(QFont("Segoe UI Black",12));
    SetRecordButton->setText("Continue");
    SetRecordButton->setStyleSheet(QString("#SetRecordButton {"
                                           "  background-color: #ffffff;"
                                           "  border-radius: 10px;"
                                           "}"
                                           "#SetRecordButton:hover {"
                                           "  background-color: #fcfcfc;"
                                           "  border: 0px;"
                                           "}"));*/
}

MainWindow::~MainWindow()
{
}

void MainWindow::MenuInfo_Slot()
{
    Info->setVisible(true);
    Options->setVisible(false);
    CurrentState->setText(QString("Exciting information, let's start"));
}

void MainWindow::MenuColor_Slot()
{
    CurrentState->setText(QString("Choose the color to continue"));
    QColor Color = QColorDialog::getColor();
    if (Color.isValid())
    {
        CurrentColor = Color;
        CurrentState->setText(QString("Color has been chosen"));
        qDebug() << Color;
    }
    else
    {
        CurrentState->setText(QString("Color hasn't been chosen"));
    }
}

void MainWindow::MenuOption_Slot()
{
    Info->setVisible(false);
    Options->setVisible(true);
    CurrentState->setText(QString("Choose the option to continue"));
}

void MainWindow::OptionsGenerate()
{
    qDebug() << OptionsCurrent << "   " << OptionsCurrent->size();
}

void MainWindow::OptionRGB_Slot()
{
    //QVector<QString>::iterator it = std::find_if(OptionsCurrent->begin(), OptionsCurrent->end(),
    //                                             [](const QString& Elem){return Elem.startsWith("RGB");});

    //if (it != OptionsCurrent->end())
    {
        OptionsCurrent->push_back(QString("RGB"));
    }
    //else
    {
        //OptionsCurrent->erase(it);
    }

    OptionsGenerate();
}

