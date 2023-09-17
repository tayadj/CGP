#include "modalwindow.h"
#include "mainwindow.h"

ModalWindow::ModalWindow(QWidget *parent, QString Type) : QGroupBox(parent)
{
    setFixedSize(280,480);
    setStyleSheet(QString("background-color: #f8f8f8;"
                          "border-radius: 10px;"));

    QLabel* ModalTitle = new QLabel(Type, this);
    ModalTitle->setGeometry(0,20,280,80);
    ModalTitle->setAlignment(Qt::AlignHCenter);
    ModalTitle->setWordWrap(true);
    ModalTitle->setFont(QFont("Segoe UI Black",12));

    ReceiveColor();

    if (Type == "RGB")
    {
        QString Red = QString("%1").arg(CurrentColor.red());
        QString Green = QString("%1").arg(CurrentColor.green());
        QString Blue = QString("%1").arg(CurrentColor.blue());

        QLabel* RedInfo = new QLabel("Red: ", this);
        RedInfo->setFont(QFont("Segoe UI Black",12));
        RedInfo->setGeometry(20,100,100,40);

        RedInput = new QLineEdit(Red, this);
        RedInput->setFont(QFont("Segoe UI Black",12));
        RedInput->setGeometry(140,100,120,40);
        RedInput->setStyleSheet("background-color: #f0f0f0");
        RedInput->setTextMargins(10,0,10,0);
        RedInput->setValidator(new QIntValidator(0,255,this));

        QLabel* GreenInfo = new QLabel("Green: ", this);
        GreenInfo->setFont(QFont("Segoe UI Black",12));
        GreenInfo->setGeometry(20,160,100,40);

        GreenInput = new QLineEdit(Green, this);
        GreenInput->setFont(QFont("Segoe UI Black",12));
        GreenInput->setGeometry(140,160,120,40);
        GreenInput->setStyleSheet("background-color: #f0f0f0");
        GreenInput->setTextMargins(10,0,10,0);
        GreenInput->setValidator(new QIntValidator(0,255,this));

        QLabel* BlueInfo = new QLabel("Blue: ", this);
        BlueInfo->setFont(QFont("Segoe UI Black",12));
        BlueInfo->setGeometry(20,220,100,40);

        BlueInput = new QLineEdit(Blue, this);
        BlueInput->setFont(QFont("Segoe UI Black",12));
        BlueInput->setGeometry(140,220,120,40);
        BlueInput->setStyleSheet("background-color: #f0f0f0");
        BlueInput->setTextMargins(10,0,10,0);
        BlueInput->setValidator(new QIntValidator(0,255,this));

        QPushButton* SendChanges = new QPushButton("Apply changes", this);
        SendChanges->setObjectName(QString("SendChangesRGB"));
        SendChanges->setFont(QFont("Segoe UI Black",12));
        SendChanges->setGeometry(40,400,200,40);
        SendChanges->setStyleSheet(QString("#SendChangesRGB {"
                                           "    background-color: #f0f0f0;"
                                           "    border-radius: 10px;"
                                           "}"
                                           "#SendChangesRGB:hover {"
                                           "    background-color: #f4f4f4;"
                                           "}"));
        connect(SendChanges,SIGNAL(clicked()),this,SLOT(RecalculateColor_Slot()));
    }

    if (Type == "CMYK")
    {
        RecalculateColor(CurrentColor);

        QLabel* CyanInfo = new QLabel("Cyan: ", this);
        CyanInfo->setFont(QFont("Segoe UI Black",12));
        CyanInfo->setGeometry(20,100,100,40);

        CyanInput = new QLineEdit(QString("%1").arg((int)(Cyan*255)), this);
        CyanInput->setFont(QFont("Segoe UI Black",12));
        CyanInput->setGeometry(140,100,120,40);
        CyanInput->setStyleSheet("background-color: #f0f0f0");
        CyanInput->setTextMargins(10,0,10,0);
        CyanInput->setValidator(new QDoubleValidator(0.0,1.0,4,this));

        QLabel* MagentaInfo = new QLabel("Magenta: ", this);
        MagentaInfo->setFont(QFont("Segoe UI Black",12));
        MagentaInfo->setGeometry(20,160,120,40);

        MagentaInput = new QLineEdit(QString("%1").arg((int)(Magenta*255)), this);
        MagentaInput->setFont(QFont("Segoe UI Black",12));
        MagentaInput->setGeometry(140,160,120,40);
        MagentaInput->setStyleSheet("background-color: #f0f0f0");
        MagentaInput->setTextMargins(10,0,10,0);
        MagentaInput->setValidator(new QDoubleValidator(0.0,1.0,4,this));

        QLabel* YellowInfo = new QLabel("Yellow: ", this);
        YellowInfo->setFont(QFont("Segoe UI Black",12));
        YellowInfo->setGeometry(20,220,100,40);

        YellowInput = new QLineEdit(QString("%1").arg((int)(Yellow*255)), this);
        YellowInput->setFont(QFont("Segoe UI Black",12));
        YellowInput->setGeometry(140,220,120,40);
        YellowInput->setStyleSheet("background-color: #f0f0f0");
        YellowInput->setTextMargins(10,0,10,0);
        YellowInput->setValidator(new QDoubleValidator(0.0,1.0,4,this));

        QLabel* KeyInfo = new QLabel("Key: ", this);
        KeyInfo->setFont(QFont("Segoe UI Black",12));
        KeyInfo->setGeometry(20,280,100,40);

        KeyInput = new QLineEdit(QString("%1").arg((int)(Key*255)), this);
        KeyInput->setFont(QFont("Segoe UI Black",12));
        KeyInput->setGeometry(140,280,120,40);
        KeyInput->setStyleSheet("background-color: #f0f0f0");
        KeyInput->setTextMargins(10,0,10,0);
        KeyInput->setValidator(new QDoubleValidator(0.0,1.0,4,this));

        QPushButton* SendChanges = new QPushButton("Apply changes", this);
        SendChanges->setObjectName(QString("SendChangesCMYK"));
        SendChanges->setFont(QFont("Segoe UI Black",12));
        SendChanges->setGeometry(40,400,200,40);
        SendChanges->setStyleSheet(QString("#SendChangesCMYK {"
                                           "    background-color: #f0f0f0;"
                                           "    border-radius: 10px;"
                                           "}"
                                           "#SendChangesCMYK:hover {"
                                           "    background-color: #f4f4f4;"
                                           "}"));
        connect(SendChanges,SIGNAL(clicked()),this,SLOT(RecalculateColor_Slot()));
    }

    if (Type == "HSV")
    {
        RecalculateColor(CurrentColor);

        QLabel* HueInfo = new QLabel("Hue: ", this);
        HueInfo->setFont(QFont("Segoe UI Black",12));
        HueInfo->setGeometry(20,100,100,40);

        HueInput_1 = new QLineEdit(QString("%1").arg(Hue_1), this);
        HueInput_1->setFont(QFont("Segoe UI Black",12));
        HueInput_1->setGeometry(140,100,120,40);
        HueInput_1->setStyleSheet("background-color: #f0f0f0");
        HueInput_1->setTextMargins(10,0,10,0);
        HueInput_1->setValidator(new QIntValidator(0,255,this));

        QLabel* SaturationInfo = new QLabel("Sat.: ", this);
        SaturationInfo->setFont(QFont("Segoe UI Black",12));
        SaturationInfo->setGeometry(20,160,100,40);

        SaturationInput_1 = new QLineEdit(QString("%1").arg(Saturation_1), this);
        SaturationInput_1->setFont(QFont("Segoe UI Black",12));
        SaturationInput_1->setGeometry(140,160,120,40);
        SaturationInput_1->setStyleSheet("background-color: #f0f0f0");
        SaturationInput_1->setTextMargins(10,0,10,0);
        SaturationInput_1->setValidator(new QIntValidator(0,255,this));

        QLabel* ValueInfo = new QLabel("Value: ", this);
        ValueInfo->setFont(QFont("Segoe UI Black",12));
        ValueInfo->setGeometry(20,220,100,40);

        ValueInput = new QLineEdit(QString("%1").arg(Value), this);
        ValueInput->setFont(QFont("Segoe UI Black",12));
        ValueInput->setGeometry(140,220,120,40);
        ValueInput->setStyleSheet("background-color: #f0f0f0");
        ValueInput->setTextMargins(10,0,10,0);
        ValueInput->setValidator(new QIntValidator(0,255,this));

        QPushButton* SendChanges = new QPushButton("Apply changes", this);
        SendChanges->setObjectName(QString("SendChangesHSV"));
        SendChanges->setFont(QFont("Segoe UI Black",12));
        SendChanges->setGeometry(40,400,200,40);
        SendChanges->setStyleSheet(QString("#SendChangesHSV {"
                                           "    background-color: #f0f0f0;"
                                           "    border-radius: 10px;"
                                           "}"
                                           "#SendChangesHSV:hover {"
                                           "    background-color: #f4f4f4;"
                                           "}"));
        connect(SendChanges,SIGNAL(clicked()),this,SLOT(RecalculateColor_Slot()));
    }

    if (Type == "HLS")
    {
        RecalculateColor(CurrentColor);

        QLabel* HueInfo = new QLabel("Hue: ", this);
        HueInfo->setFont(QFont("Segoe UI Black",12));
        HueInfo->setGeometry(20,100,100,40);

        HueInput_2 = new QLineEdit(QString("%1").arg(Hue_2), this);
        HueInput_2->setFont(QFont("Segoe UI Black",12));
        HueInput_2->setGeometry(140,100,120,40);
        HueInput_2->setStyleSheet("background-color: #f0f0f0");
        HueInput_2->setTextMargins(10,0,10,0);
        HueInput_2->setValidator(new QIntValidator(0,255,this));

        QLabel* SaturationInfo = new QLabel("Sat.: ", this);
        SaturationInfo->setFont(QFont("Segoe UI Black",12));
        SaturationInfo->setGeometry(20,160,100,40);

        SaturationInput_2 = new QLineEdit(QString("%1").arg(Saturation_2), this);
        SaturationInput_2->setFont(QFont("Segoe UI Black",12));
        SaturationInput_2->setGeometry(140,160,120,40);
        SaturationInput_2->setStyleSheet("background-color: #f0f0f0");
        SaturationInput_2->setTextMargins(10,0,10,0);
        SaturationInput_2->setValidator(new QIntValidator(0,255,this));

        QLabel* LightnessInfo = new QLabel("Light.: ", this);
        LightnessInfo->setFont(QFont("Segoe UI Black",12));
        LightnessInfo->setGeometry(20,220,100,40);

        LightnessInput = new QLineEdit(QString("%1").arg(Lightness), this);
        LightnessInput->setFont(QFont("Segoe UI Black",12));
        LightnessInput->setGeometry(140,220,120,40);
        LightnessInput->setStyleSheet("background-color: #f0f0f0");
        LightnessInput->setTextMargins(10,0,10,0);
        LightnessInput->setValidator(new QIntValidator(0,255,this));

        QPushButton* SendChanges = new QPushButton("Apply changes", this);
        SendChanges->setObjectName(QString("SendChangesHLS"));
        SendChanges->setFont(QFont("Segoe UI Black",12));
        SendChanges->setGeometry(40,400,200,40);
        SendChanges->setStyleSheet(QString("#SendChangesHLS {"
                                           "    background-color: #f0f0f0;"
                                           "    border-radius: 10px;"
                                           "}"
                                           "#SendChangesHLS:hover {"
                                           "    background-color: #f4f4f4;"
                                           "}"));
        connect(SendChanges,SIGNAL(clicked()),this,SLOT(RecalculateColor_Slot()));
    }

    if (Type == "XYZ")
    {
        RecalculateColor(CurrentColor);

        QLabel* XInfo = new QLabel("X: ", this);
        XInfo->setFont(QFont("Segoe UI Black",12));
        XInfo->setGeometry(20,100,100,40);

        XInput = new QLineEdit(QString("%1").arg(X), this);
        XInput->setFont(QFont("Segoe UI Black",12));
        XInput->setGeometry(140,100,120,40);
        XInput->setStyleSheet("background-color: #f0f0f0");
        XInput->setTextMargins(10,0,10,0);
        XInput->setValidator(new QDoubleValidator(0.0,100.0,4,this));

        QLabel* YInfo = new QLabel("Y: ", this);
        YInfo->setFont(QFont("Segoe UI Black",12));
        YInfo->setGeometry(20,160,100,40);

        YInput = new QLineEdit(QString("%1").arg(Y), this);
        YInput->setFont(QFont("Segoe UI Black",12));
        YInput->setGeometry(140,160,120,40);
        YInput->setStyleSheet("background-color: #f0f0f0");
        YInput->setTextMargins(10,0,10,0);
        YInput->setValidator(new QDoubleValidator(0.0,100.0,4,this));

        QLabel* ZInfo = new QLabel("Z: ", this);
        ZInfo->setFont(QFont("Segoe UI Black",12));
        ZInfo->setGeometry(20,220,100,40);

        ZInput = new QLineEdit(QString("%1").arg(Z), this);
        ZInput->setFont(QFont("Segoe UI Black",12));
        ZInput->setGeometry(140,220,120,40);
        ZInput->setStyleSheet("background-color: #f0f0f0");
        ZInput->setTextMargins(10,0,10,0);
        ZInput->setValidator(new QDoubleValidator(0.0,100.0,4,this));

        QPushButton* SendChanges = new QPushButton("Apply changes", this);
        SendChanges->setObjectName(QString("SendChangesXYZ"));
        SendChanges->setFont(QFont("Segoe UI Black",12));
        SendChanges->setGeometry(40,400,200,40);
        SendChanges->setStyleSheet(QString("#SendChangesXYZ {"
                                           "    background-color: #f0f0f0;"
                                           "    border-radius: 10px;"
                                           "}"
                                           "#SendChangesXYZ:hover {"
                                           "    background-color: #f4f4f4;"
                                           "}"));
        connect(SendChanges,SIGNAL(clicked()),this,SLOT(RecalculateColor_Slot()));
    }

    if (Type == "LAB")
    {
        RecalculateColor(CurrentColor);

        QLabel* LInfo = new QLabel("L: ", this);
        LInfo->setFont(QFont("Segoe UI Black",12));
        LInfo->setGeometry(20,100,100,40);

        LInput = new QLineEdit(QString("%1").arg(L), this);
        LInput->setFont(QFont("Segoe UI Black",12));
        LInput->setGeometry(140,100,120,40);
        LInput->setStyleSheet("background-color: #f0f0f0");
        LInput->setTextMargins(10,0,10,0);
        LInput->setValidator(new QDoubleValidator(0.0,100.0,4,this));

        QLabel* AInfo = new QLabel("A: ", this);
        AInfo->setFont(QFont("Segoe UI Black",12));
        AInfo->setGeometry(20,160,100,40);

        AInput = new QLineEdit(QString("%1").arg(A), this);
        AInput->setFont(QFont("Segoe UI Black",12));
        AInput->setGeometry(140,160,120,40);
        AInput->setStyleSheet("background-color: #f0f0f0");
        AInput->setTextMargins(10,0,10,0);
        AInput->setValidator(new QDoubleValidator(0.0,100.0,4,this));

        QLabel* BInfo = new QLabel("B: ", this);
        BInfo->setFont(QFont("Segoe UI Black",12));
        BInfo->setGeometry(20,220,100,40);

        BInput = new QLineEdit(QString("%1").arg(B), this);
        BInput->setFont(QFont("Segoe UI Black",12));
        BInput->setGeometry(140,220,120,40);
        BInput->setStyleSheet("background-color: #f0f0f0");
        BInput->setTextMargins(10,0,10,0);
        BInput->setValidator(new QDoubleValidator(0.0,100.0,4,this));

        QPushButton* SendChanges = new QPushButton("Apply changes", this);
        SendChanges->setObjectName(QString("SendChangesXYZ"));
        SendChanges->setFont(QFont("Segoe UI Black",12));
        SendChanges->setGeometry(40,400,200,40);
        SendChanges->setStyleSheet(QString("#SendChangesXYZ {"
                                           "    background-color: #f0f0f0;"
                                           "    border-radius: 10px;"
                                           "}"
                                           "#SendChangesXYZ:hover {"
                                           "    background-color: #f4f4f4;"
                                           "}"));
        connect(SendChanges,SIGNAL(clicked()),this,SLOT(RecalculateColor()));
    }
}

ModalWindow::~ModalWindow()
{
}

void ModalWindow::ReceiveColor()
{
    CurrentColor = ((MainWindow*)this->parent())->getColor();
    RecalculateColor(CurrentColor);
}

void ModalWindow::SendColor(QColor* Color)
{
    ((MainWindow*)this->parent())->setColor(*Color);
}

void ModalWindow::RecalculateColor(QColor Color)
{
    Red = Color.red();
    Green = Color.green();
    Blue = Color.blue();

    // RGB - CMYK

    Key = 1.0 - std::max({Red, Green, Blue})/255.0;
    Cyan = (1.0 - Red/255.0 - Key)/(1.0 - Key);
    Magenta = (1.0 - Green/255.0 - Key)/(1.0 - Key);
    Yellow = (1.0 - Blue/255.0 - Key)/(1.0 - Key);
    if (Key == 1.0) { Cyan = Magenta = Yellow = 0.0; }

    // RGB - HSV

    Hue_1 = Color.hsvHue();
    Saturation_1 = Color.hsvSaturation();
    Value = Color.value();

    // RGB - HLS

    Hue_2 = Color.hslHue();
    Saturation_2 = Color.hslSaturation();
    Lightness = Color.lightness();

    // RGB - XYZ

    double RedN = 100.0, GreenN = 100.0, BlueN = 100.0;

    if (Red/255 > 0.04045) { RedN *= std::pow((Red/255 + 0.055)/1.055,2.4); } else { RedN *= Red/255/12.92; }
    if (Green/255 > 0.04045) { GreenN *= std::pow((Green/255 + 0.055)/1.055,2.4); } else { GreenN *= Green/255/12.92; }
    if (Blue/255 > 0.04045) { BlueN *= std::pow((Blue/255 + 0.055)/1.055,2.4); } else { BlueN *= Blue/255/12.92; }

    X = 0.412453*RedN + 0.357580*GreenN + 0.180423*BlueN;
    Y = 0.212671*RedN + 0.715160*GreenN + 0.072169*BlueN;
    Z = 0.019334*RedN + 0.119193*GreenN + 0.950227*BlueN;

    // XYZ - LAB

    double Xw = X/95.047, Yw = Y/100.0, Zw = Z/108.883;

    L = 116 * ((Yw>0.008856)?(std::pow(Yw,1.0/3)):(7.787*Yw+16.0/116)) - 16;
    A = 500 * (((Xw>0.008856)?(std::pow(Xw,1.0/3)):(7.787*Xw+16.0/116)) - ((Yw>0.008856)?(std::pow(Yw,1.0/3)):(7.787*Yw+16.0/116)));
    B = 200 * (((Yw>0.008856)?(std::pow(Yw,1.0/3)):(7.787*Yw+16.0/116)) - ((Zw>0.008856)?(std::pow(Zw,1.0/3)):(7.787*Zw+16.0/116)));
}

void ModalWindow::RecalculateColor_Slot()
{

    // Нужно определить цвет и поменять его везде
    // Для этого определяем от кого был отослан и получаем Color, потом отсылаем его остальным модулям
}
