#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(1440,900);
    setWindowTitle(QString("CGP-1"));



    Tab = new QGroupBox(this);
    Tab->setGeometry(QRect(0,0,1440,80));
    Tab->setStyleSheet(QString("background-color: #ffffff;"
                               "border-radius: 0px;"));

    Title = new QLabel(Tab);
    Title->setText(QString("Lab #1"));
    Title->setFont(QFont("Segoe UI Black",32));
    Title->setGeometry(QRect(80,6,400,68));



    Menu = new QGroupBox(this);
    Menu->setGeometry(QRect(80,160,320,220));
    Menu->setStyleSheet(QString("border-radius: 10px;"));

    MenuModals = new QPushButton(Menu);
    MenuModals->setObjectName(QString("MenuModals"));
    MenuModals->setText(QString("Edit models"));
    MenuModals->setFont(QFont("Segoe UI Black",16));
    MenuModals->setGeometry(QRect(0,0,196,60));
    MenuModals->setStyleSheet(QString("#MenuModals:hover {"
                                      "    background-color: #f8f8f8;"
                                      "}"));
    connect(MenuModals,SIGNAL(clicked()),this,SLOT(MenuModals_Slot()));

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
    Info->setGeometry(QRect(440,160,920,260));
    Info->setStyleSheet(QString("background-color: #f8f8f8;"
                                "border-radius: 10px;"));

    InfoTitle = new QLabel(Info);
    InfoTitle->setGeometry(QRect(20,20,880,80));
    InfoTitle->setText(QString("Guide on this project"));
    InfoTitle->setAlignment(Qt::AlignHCenter);
    InfoTitle->setWordWrap(true);
    InfoTitle->setFont(QFont("Segoe UI Black",16));

    InfoText = new QLabel(Info);
    InfoText->setGeometry(QRect(20,100,880,200));
    InfoText->setText(QString("This program is used to work with various representations of color in the computer. In it, you can choose a color by directly clicking on the \"Choose color\" button, change the current color representation models by directly clicking on the \"Edit models\" button."));
    InfoText->setAlignment(Qt::AlignJustify);
    InfoText->setWordWrap(true);
    InfoText->setFont(QFont("Segoe UI Black",12));



    MenuModalsOptions = new QGroupBox(this);
    MenuModalsOptions->setVisible(false);
    MenuModalsOptions->setGeometry(480,160,820,320);
    MenuModalsOptions->setStyleSheet(QString("border-radius: 10px;"
                                             "background-color: #f8f8f8;"));

    MenuModalsOptionsRGB = new QPushButton("RGB", MenuModalsOptions);
    MenuModalsOptionsRGB->setObjectName(QString("MenuModalsOptionsRGB"));
    MenuModalsOptionsRGB->setFont(QFont("Segoe UI Black",12));
    MenuModalsOptionsRGB->setGeometry(40,40,220,100);
    MenuModalsOptionsRGB->setStyleSheet(QString("#MenuModalsOptionsRGB {"
                                                "    background-color: #f0f0f0;"
                                                "    border-radius: 10px;"
                                                "}"
                                                "#MenuModalsOptionsRGB:hover {"
                                                "    background-color: #f4f4f4;"
                                                "}"));
    connect(MenuModalsOptionsRGB,SIGNAL(clicked()),this,SLOT(MenuModalsOptions_Slot()));

    MenuModalsOptionsCMYK = new QPushButton("CMYK", MenuModalsOptions);
    MenuModalsOptionsCMYK->setObjectName(QString("MenuModalsOptionsCMYK"));
    MenuModalsOptionsCMYK->setFont(QFont("Segoe UI Black",12));
    MenuModalsOptionsCMYK->setGeometry(300,40,220,100);
    MenuModalsOptionsCMYK->setStyleSheet(QString("#MenuModalsOptionsCMYK {"
                                                 "    background-color: #f0f0f0;"
                                                 "    border-radius: 10px;"
                                                 "}"
                                                 "#MenuModalsOptionsCMYK:hover {"
                                                 "    background-color: #f4f4f4;"
                                                 "}"));
    connect(MenuModalsOptionsCMYK,SIGNAL(clicked()),this,SLOT(MenuModalsOptions_Slot()));

    MenuModalsOptionsHSV = new QPushButton("HSV", MenuModalsOptions);
    MenuModalsOptionsHSV->setObjectName(QString("MenuModalsOptionsHSV"));
    MenuModalsOptionsHSV->setFont(QFont("Segoe UI Black",12));
    MenuModalsOptionsHSV->setGeometry(560,40,220,100);
    MenuModalsOptionsHSV->setStyleSheet(QString("#MenuModalsOptionsHSV {"
                                                "    background-color: #f0f0f0;"
                                                "    border-radius: 10px;"
                                                "}"
                                                "#MenuModalsOptionsHSV:hover {"
                                                "    background-color: #f4f4f4;"
                                                "}"));
    connect(MenuModalsOptionsHSV,SIGNAL(clicked()),this,SLOT(MenuModalsOptions_Slot()));

    MenuModalsOptionsHLS = new QPushButton("HLS", MenuModalsOptions);
    MenuModalsOptionsHLS->setObjectName(QString("MenuModalsOptionsHLS"));
    MenuModalsOptionsHLS->setFont(QFont("Segoe UI Black",12));
    MenuModalsOptionsHLS->setGeometry(40,180,220,100);
    MenuModalsOptionsHLS->setStyleSheet(QString("#MenuModalsOptionsHLS {"
                                                "    background-color: #f0f0f0;"
                                                "    border-radius: 10px;"
                                                "}"
                                                "#MenuModalsOptionsHLS:hover {"
                                                "    background-color: #f4f4f4;"
                                                "}"));
    connect(MenuModalsOptionsHLS,SIGNAL(clicked()),this,SLOT(MenuModalsOptions_Slot()));

    MenuModalsOptionsXYZ = new QPushButton("XYZ", MenuModalsOptions);
    MenuModalsOptionsXYZ->setObjectName(QString("MenuModalsOptionsXYZ"));
    MenuModalsOptionsXYZ->setFont(QFont("Segoe UI Black",12));
    MenuModalsOptionsXYZ->setGeometry(300,180,220,100);
    MenuModalsOptionsXYZ->setStyleSheet(QString("#MenuModalsOptionsXYZ {"
                                                "    background-color: #f0f0f0;"
                                                "    border-radius: 10px;"
                                                "}"
                                                "#MenuModalsOptionsXYZ:hover {"
                                                "    background-color: #f4f4f4;"
                                                "}"));
    connect(MenuModalsOptionsXYZ,SIGNAL(clicked()),this,SLOT(MenuModalsOptions_Slot()));

    MenuModalsOptionsLAB = new QPushButton("LAB", MenuModalsOptions);
    MenuModalsOptionsLAB->setObjectName(QString("MenuModalsOptionsLAB"));
    MenuModalsOptionsLAB->setFont(QFont("Segoe UI Black",12));
    MenuModalsOptionsLAB->setGeometry(560,180,220,100);
    MenuModalsOptionsLAB->setStyleSheet(QString("#MenuModalsOptionsLAB {"
                                                "    background-color: #f0f0f0;"
                                                "    border-radius: 10px;"
                                                "}"
                                                "#MenuModalsOptionsLAB:hover {"
                                                "    background-color: #f4f4f4;"
                                                "}"));
    connect(MenuModalsOptionsLAB,SIGNAL(clicked()),this,SLOT(MenuModalsOptions_Slot()));



    Modals = new QGroupBox(this);
    Modals->setGeometry(440,160,920,500);
    Modals->setStyleSheet(QString("border-radius: 0px;"));

    ModalLayout = new QHBoxLayout(Modals);
}

MainWindow::~MainWindow()
{
}

QColor MainWindow::getColor()
{
    return this->CurrentColor;
}

void MainWindow::setColor(QColor Color)
{
}

void MainWindow::MenuModals_Slot()
{
    Info->setVisible(false);
    Modals->setVisible(false);
    MenuModalsOptions->setVisible(true);
}

void MainWindow::MenuModalsOptions_Slot()
{
    Info->setVisible(false);
    Modals->setVisible(true);
    MenuModalsOptions->setVisible(false);

    if (QObject::sender()->objectName() == "MenuModalsOptionsRGB")
    {
        int Index = (*ModalList).indexOf(QString("RGB"));

        if (Index == -1)
        {
            if (ModalList->size() == 3)
            {
                QMessageBox::information(this,"Error","You can't have more than 3 models simultaneously.");
            }
            else
            {
                ModalList->push_back("RGB");
            }
        }
        if (Index != -1)
        {
            ModalList->erase(ModalList->begin() + Index);
        }
    }
    if (QObject::sender()->objectName() == "MenuModalsOptionsCMYK")
    {
        int Index = (*ModalList).indexOf(QString("CMYK"));

        if (Index == -1)
        {
            if (ModalList->size() == 3)
            {
                QMessageBox::information(this,"Error","You can't have more than 3 models simultaneously.");
            }
            else
            {
                ModalList->push_back("CMYK");
            }
        }
        if (Index != -1)
        {
            ModalList->erase(ModalList->begin() + Index);
        }
    }
    if (QObject::sender()->objectName() == "MenuModalsOptionsHSV")
    {
        int Index = (*ModalList).indexOf(QString("HSV"));

        if (Index == -1)
        {
            if (ModalList->size() == 3)
            {
                QMessageBox::information(this,"Error","You can't have more than 3 models simultaneously.");
            }
            else
            {
                ModalList->push_back("HSV");
            }
        }
        if (Index != -1)
        {
            ModalList->erase(ModalList->begin() + Index);
        }
    }
    if (QObject::sender()->objectName() == "MenuModalsOptionsHLS")
    {
        int Index = (*ModalList).indexOf(QString("HLS"));

        if (Index == -1)
        {
            if (ModalList->size() == 3)
            {
                QMessageBox::information(this,"Error","You can't have more than 3 models simultaneously.");
            }
            else
            {
                ModalList->push_back("HLS");
            }
        }
        if (Index != -1)
        {
            ModalList->erase(ModalList->begin() + Index);
        }
    }
    if (QObject::sender()->objectName() == "MenuModalsOptionsXYZ")
    {
        int Index = (*ModalList).indexOf(QString("XYZ"));

        if (Index == -1)
        {
            if (ModalList->size() == 3)
            {
                QMessageBox::information(this,"Error","You can't have more than 3 models simultaneously.");
            }
            else
            {
                ModalList->push_back("XYZ");
            }
        }
        if (Index != -1)
        {
            ModalList->erase(ModalList->begin() + Index);
        }
    }
    if (QObject::sender()->objectName() == "MenuModalsOptionsLAB")
    {
        int Index = (*ModalList).indexOf(QString("LAB"));

        if (Index == -1)
        {
            if (ModalList->size() == 3)
            {
                QMessageBox::information(this,"Error","You can't have more than 3 models simultaneously.");
            }
            else
            {
                ModalList->push_back("LAB");
            }
        }
        if (Index != -1)
        {
            ModalList->erase(ModalList->begin() + Index);
        }
    }

    GenerateModals();
}

void MainWindow::MenuInfo_Slot()
{
    Info->setVisible(true);
    Modals->setVisible(false);
    MenuModalsOptions->setVisible(false);
}

void MainWindow::MenuColor_Slot()
{
    QColor Color = QColorDialog::getColor();
    if (Color.isValid())
    {
        this->CurrentColor = Color;
        GenerateModals();
    }
}

void MainWindow::GenerateModals()
{
    QLayoutItem* Item;
    while((Item = ModalLayout->takeAt(0))) {
        delete Item->widget();
        delete Item;
    }

    for (int i = 0; i < ModalList->size(); ++i)
    {
        if ((*ModalList)[i] == "RGB")
        {
            ModalWindow* Modal = new ModalWindow(this, "RGB");
            ModalLayout->addWidget(Modal);
        }
        if ((*ModalList)[i] == "CMYK")
        {
            ModalWindow* Modal = new ModalWindow(this, "CMYK");
            ModalLayout->addWidget(Modal);
        }
        if ((*ModalList)[i] == "HSV")
        {
            ModalWindow* Modal = new ModalWindow(this, "HSV");
            ModalLayout->addWidget(Modal);
        }
        if ((*ModalList)[i] == "HLS")
        {
            ModalWindow* Modal = new ModalWindow(this, "HLS");
            ModalLayout->addWidget(Modal);
        }
        if ((*ModalList)[i] == "XYZ")
        {
            ModalWindow* Modal = new ModalWindow(this, "XYZ");
            ModalLayout->addWidget(Modal);
        }
        if ((*ModalList)[i] == "LAB")
        {
            ModalWindow* Modal = new ModalWindow(this, "LAB");
            ModalLayout->addWidget(Modal);
        }
    }
}
