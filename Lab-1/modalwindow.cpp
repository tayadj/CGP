#include "modalwindow.h"
#include "mainwindow.h"

ModalWindow::ModalWindow(QWidget* parent, QString Type) : QGroupBox(parent)
{
    setFixedSize(280,480);
    setStyleSheet(QString("background-color: #f8f8f8;"
                          "border-radius: 10px;"));

    Title = new QLabel(Type, this);
    Title->setGeometry(0,20,280,80);
    Title->setAlignment(Qt::AlignHCenter);
    Title->setWordWrap(true);
    Title->setFont(QFont("Segoe UI Black",12));

    Label_1 = new QLabel(this);
    Label_1->setFont(QFont("Segoe UI Black",12));
    Label_1->setGeometry(20,100,100,40);
    Label_2 = new QLabel(this);
    Label_2->setFont(QFont("Segoe UI Black",12));
    Label_2->setGeometry(20,160,110,40);
    Label_3 = new QLabel(this);
    Label_3->setFont(QFont("Segoe UI Black",12));
    Label_3->setGeometry(20,220,100,40);
    Label_4 = new QLabel(this);
    Label_4->setFont(QFont("Segoe UI Black",12));
    Label_4->setGeometry(20,280,100,40);
    Label_4->setVisible(false);

    LineEdit_1 = new QLineEdit(this);
    LineEdit_1->setFont(QFont("Segoe UI Black",12));
    LineEdit_1->setGeometry(140,100,120,40);
    LineEdit_1->setStyleSheet("background-color: #f0f0f0");
    LineEdit_1->setTextMargins(10,0,10,0);
    LineEdit_1->setValidator(new QIntValidator(-999,999));
    connect(LineEdit_1, SIGNAL(textEdited(QString)), this, SLOT(LineEdit_1_Changed()));
    LineEdit_2 = new QLineEdit(this);
    LineEdit_2->setFont(QFont("Segoe UI Black",12));
    LineEdit_2->setGeometry(140,160,120,40);
    LineEdit_2->setStyleSheet("background-color: #f0f0f0");
    LineEdit_2->setTextMargins(10,0,10,0);
    LineEdit_2->setValidator(new QIntValidator(-999,999));
    connect(LineEdit_2, SIGNAL(textEdited(QString)), this, SLOT(LineEdit_2_Changed()));
    LineEdit_3 = new QLineEdit(this);
    LineEdit_3->setFont(QFont("Segoe UI Black",12));
    LineEdit_3->setGeometry(140,220,120,40);
    LineEdit_3->setStyleSheet("background-color: #f0f0f0");
    LineEdit_3->setTextMargins(10,0,10,0);
    LineEdit_3->setValidator(new QIntValidator(-999,999));
    connect(LineEdit_3, SIGNAL(textEdited(QString)), this, SLOT(LineEdit_3_Changed()));
    LineEdit_4 = new QLineEdit(this);
    LineEdit_4->setFont(QFont("Segoe UI Black",12));
    LineEdit_4->setGeometry(140,280,120,40);
    LineEdit_4->setStyleSheet("background-color: #f0f0f0");
    LineEdit_4->setTextMargins(10,0,10,0);
    LineEdit_4->setVisible(false);
    LineEdit_4->setValidator(new QIntValidator(-999,999));
    connect(LineEdit_4, SIGNAL(textEdited(QString)), this, SLOT(LineEdit_4_Changed()));

    ReceiveColor();

    if (Type == "RGB")
    {
        Label_1->setText("Red: ");
        Label_2->setText("Green: ");
        Label_3->setText("Blue: ");

        LineEdit_1->setText(QString("%1").arg(Red));
        LineEdit_2->setText(QString("%1").arg(Green));
        LineEdit_3->setText(QString("%1").arg(Blue));
    }

    if (Type == "CMYK")
    {
        Label_1->setText("Cyan: ");
        Label_2->setText("Magenta: ");
        Label_3->setText("Yellow: ");
        Label_4->setText("Key: ");
        Label_4->setVisible(true);

        LineEdit_1->setText(QString("%1").arg(Cyan));
        LineEdit_2->setText(QString("%1").arg(Magenta));
        LineEdit_3->setText(QString("%1").arg(Yellow));
        LineEdit_4->setText(QString("%1").arg(Key));
        LineEdit_4->setVisible(true);
    }

    if (Type == "HSV")
    {
        Label_1->setText("Hue: ");
        Label_2->setText("Sat.: ");
        Label_3->setText("Value: ");

        LineEdit_1->setText(QString("%1").arg(Hue_1));
        LineEdit_2->setText(QString("%1").arg(Saturation_1));
        LineEdit_3->setText(QString("%1").arg(Value));
    }

    if (Type == "HSL")
    {
        Label_1->setText("Hue: ");
        Label_2->setText("Sat.: ");
        Label_3->setText("Light.: ");

        LineEdit_1->setText(QString("%1").arg(Hue_2));
        LineEdit_2->setText(QString("%1").arg(Saturation_2));
        LineEdit_3->setText(QString("%1").arg(Lightness));
    }

    if (Type == "XYZ")
    {
        Label_1->setText("X: ");
        Label_2->setText("Y: ");
        Label_3->setText("Z: ");

        LineEdit_1->setText(QString::number(X, 'f', 3));
        LineEdit_2->setText(QString::number(Y, 'f', 3));
        LineEdit_3->setText(QString::number(Z, 'f', 3));
    }

    if (Type == "LAB")
    {
        Label_1->setText("L: ");
        Label_2->setText("A: ");
        Label_3->setText("B: ");

        LineEdit_1->setText(QString::number(L, 'f', 3));
        LineEdit_2->setText(QString::number(A, 'f', 3));
        LineEdit_3->setText(QString::number(B, 'f', 3));
    }
}

ModalWindow::~ModalWindow()
{
}

void ModalWindow::RecalculateColor(QColor Color)
{
    CurrentColor = Color;

    // RGB

    Red = CurrentColor.red();
    Green = CurrentColor.green();
    Blue = CurrentColor.blue();

    // RGB - CMYK

    Key = 255.0 - std::max({Red, Green, Blue});
    Cyan = (int) (255 * (std::max({Red, Green, Blue}) - Red) / (std::max({Red, Green, Blue})));
    Magenta = (int) (255 * (std::max({Red, Green, Blue}) - Green) / (std::max({Red, Green, Blue})));
    Yellow = (int) (255 * (std::max({Red, Green, Blue}) - Blue) / (std::max({Red, Green, Blue})));
    if (Key == 255.0) { Cyan = Magenta = Yellow = 0.0; }
    Key = CurrentColor.black();
    Cyan = CurrentColor.cyan();
    Magenta = CurrentColor.magenta();
    Yellow = CurrentColor.yellow();

    // RGB - HSV

    Hue_1 = CurrentColor.hsvHue();
    Saturation_1 = CurrentColor.hsvSaturation();
    Value = CurrentColor.value();

    // RGB - HSL

    Hue_2 = CurrentColor.hslHue();
    Saturation_2 = CurrentColor.hslSaturation();
    Lightness = CurrentColor.lightness();

    // RGB - XYZ

    double RedN = 100.0, GreenN = 100.0, BlueN = 100.0;

    if (Red/255 > 0.04045) { RedN *= std::pow((Red/255 + 0.055)/1.055,2.4); } else { RedN *= Red/255/12.92; }
    if (Green/255 > 0.04045) { GreenN *= std::pow((Green/255 + 0.055)/1.055,2.4); } else { GreenN *= Green/255/12.92; }
    if (Blue/255 > 0.04045) { BlueN *= std::pow((Blue/255 + 0.055)/1.055,2.4); } else { BlueN *= Blue/255/12.92; }

    X = (0.412453*RedN + 0.357580*GreenN + 0.180423*BlueN);
    Y = (0.212671*RedN + 0.715160*GreenN + 0.072169*BlueN);
    Z = (0.019334*RedN + 0.119193*GreenN + 0.950227*BlueN);

    // XYZ - LAB

    double Xw = X/95.0456, Yw = Y/100.0, Zw = Z/108.875;

    L = (116 * ((Yw>0.008856)?(std::pow(Yw,1.0/3)):(7.787*Yw+16.0/116)) - 16);
    A = (500 * (((Xw>0.008856)?(std::pow(Xw,1.0/3)):(7.787*Xw+16.0/116)) - ((Yw>0.008856)?(std::pow(Yw,1.0/3)):(7.787*Yw+16.0/116))));
    B = (200 * (((Yw>0.008856)?(std::pow(Yw,1.0/3)):(7.787*Yw+16.0/116)) - ((Zw>0.008856)?(std::pow(Zw,1.0/3)):(7.787*Zw+16.0/116))));

    if (Title->text() == "RGB")
    {
        LineEdit_1->setText(QString("%1").arg(Red));
        LineEdit_2->setText(QString("%1").arg(Green));
        LineEdit_3->setText(QString("%1").arg(Blue));
    }

    if (Title->text() == "CMYK")
    {
        LineEdit_1->setText(QString("%1").arg(Cyan));
        LineEdit_2->setText(QString("%1").arg(Magenta));
        LineEdit_3->setText(QString("%1").arg(Yellow));
        LineEdit_4->setText(QString("%1").arg(Key));
    }

    if (Title->text() == "HSV")
    {
        LineEdit_1->setText(QString("%1").arg(Hue_1));
        LineEdit_2->setText(QString("%1").arg(Saturation_1));
        LineEdit_3->setText(QString("%1").arg(Value));
    }

    if (Title->text() == "HSL")
    {
        LineEdit_1->setText(QString("%1").arg(Hue_2));
        LineEdit_2->setText(QString("%1").arg(Saturation_2));
        LineEdit_3->setText(QString("%1").arg(Lightness));
    }

    if (Title->text() == "XYZ")
    {
        LineEdit_1->setText(QString::number(X, 'f', 3));
        LineEdit_2->setText(QString::number(Y, 'f', 3));
        LineEdit_3->setText(QString::number(Z, 'f', 3));
    }

    if (Title->text() == "LAB")
    {
        LineEdit_1->setText(QString::number(L, 'f', 3));
        LineEdit_2->setText(QString::number(A, 'f', 3));
        LineEdit_3->setText(QString::number(B, 'f', 3));
    }
}

void ModalWindow::ReceiveColor()
{
    CurrentColor = ((MainWindow*)this->parent())->SendColor();
    RecalculateColor(CurrentColor);
}
void ModalWindow::ReceiveColor(QColor Color)
{
    CurrentColor = Color;
    RecalculateColor(CurrentColor);
}

void ModalWindow::LineEdit_Changed(QLineEdit* LineEdit, qint16 Min, qint16 Max, bool Statement) {
    if (LineEdit->text().toDouble() > Max){
        QMessageBox::critical(this, "Out of range","Your value is more than max-value, it's been seamlessed");
        LineEdit->setText(QString::number(Max));
    }
    if (LineEdit->text().toDouble() < Min){
        QMessageBox::critical(this, "Out of range","Your value is less than min-value, it's been seamlessed");
        LineEdit->setText(QString::number(Min));
    }

    if (Title->text() == "RGB") {
        QColor Color;
        Color.setRgb(LineEdit_1->text().toInt(),LineEdit_2->text().toInt(),LineEdit_3->text().toInt());
        RecalculateColor(Color);
    }
    if (Title->text() == "CMYK") {
        QColor Color;
        Color.setCmyk(LineEdit_1->text().toInt(),LineEdit_2->text().toInt(),LineEdit_3->text().toInt(),LineEdit_4->text().toInt());
        RecalculateColor(Color);
    }
    if (Title->text() == "LAB") {
        QColor Color;

        RecalculateColor(Color);
    }
    if (Title->text() == "HSV") {
        QColor Color;
        Color.setHsv(LineEdit_1->text().toInt(),LineEdit_2->text().toInt(),LineEdit_3->text().toInt());
        RecalculateColor(Color);
    }
    if (Title->text() == "HSL") {
        QColor Color;
        Color.setHsl(LineEdit_1->text().toInt(),LineEdit_2->text().toInt(),LineEdit_3->text().toInt());
        RecalculateColor(Color);
    }
    if (Title->text() == "XYZ") {
        QColor Color;
        double Rn = (3.2406 * LineEdit_1->text().toInt() - 1.5372 * LineEdit_2->text().toInt() - 0.4986 * LineEdit_3->text().toInt())/100;
        double Gn = (-0.9689 * LineEdit_1->text().toInt() + 1.8758 * LineEdit_2->text().toInt() + 0.0415 * LineEdit_3->text().toInt())/100;
        double Bn = (0.0557 * LineEdit_1->text().toInt() - 0.2040 * LineEdit_2->text().toInt() + 1.0570 * LineEdit_3->text().toInt())/100;
        int Red = ((Rn >= 0.0031308)?(1.055 * std::pow(Rn, 1/2.4)-0.055):(12.92*Rn))*255;
        int Green = ((Gn >= 0.0031308)?(1.055 * std::pow(Gn, 1/2.4)-0.055):(12.92*Gn))*255;
        int Blue = ((Bn >= 0.0031308)?(1.055 * std::pow(Bn, 1/2.4)-0.055):(12.92*Bn))*255;
        qDebug() << Red << ' ' << Green << ' ' << Blue;
        Color.setRgb(Red,Green,Blue);
        RecalculateColor(Color);
    }

    if (!Statement) {
        emit SendColor(CurrentColor);
    }
}

void ModalWindow::LineEdit_1_Changed(bool Statement) {
    if (Title->text() == "RGB") {
        LineEdit_Changed(LineEdit_1, 0, 255, Statement);
    }
    if (Title->text() == "CMYK") {
        LineEdit_Changed(LineEdit_1, 0, 255, Statement);
    }
    if (Title->text() == "LAB") {
        LineEdit_Changed(LineEdit_1, 0, 100, Statement);
    }
    if (Title->text() == "HSV") {
        LineEdit_Changed(LineEdit_1, 0, 360, Statement);
    }
    if (Title->text() == "HSL") {
        LineEdit_Changed(LineEdit_1, 0, 255, Statement);
    }
    if (Title->text() == "XYZ") {
        LineEdit_Changed(LineEdit_1, 0, 100, Statement);
    }
}

void ModalWindow::LineEdit_2_Changed(bool Statement) {
    if (Title->text() == "RGB") {
        LineEdit_Changed(LineEdit_2, 0, 255, Statement);
    }
    if (Title->text() == "CMYK") {
        LineEdit_Changed(LineEdit_2, 0, 255, Statement);
    }
    if (Title->text() == "LAB") {
        LineEdit_Changed(LineEdit_2, -128, 127, Statement);
    }
    if (Title->text() == "HSV") {
        LineEdit_Changed(LineEdit_2, 0, 255, Statement);
    }
    if (Title->text() == "HSL") {
        LineEdit_Changed(LineEdit_2, 0, 255, Statement);
    }
    if (Title->text() == "XYZ") {
        LineEdit_Changed(LineEdit_2, 0, 100, Statement);
    }
}

void ModalWindow::LineEdit_3_Changed(bool Statement) {
    if (Title->text() == "RGB") {
        LineEdit_Changed(LineEdit_3, 0, 255, Statement);
    }
    if (Title->text() == "CMYK") {
        LineEdit_Changed(LineEdit_3, 0, 255, Statement);
    }
    if (Title->text() == "LAB") {
        LineEdit_Changed(LineEdit_3, -128, 127, Statement);
    }
    if (Title->text() == "HSV") {
        LineEdit_Changed(LineEdit_3, 0, 255, Statement);
    }
    if (Title->text() == "HSL") {
        LineEdit_Changed(LineEdit_3, 0, 255, Statement);
    }
    if (Title->text() == "XYZ") {
        LineEdit_Changed(LineEdit_3, 0, 100, Statement);
    }
}

void ModalWindow::LineEdit_4_Changed(bool Statement) {
    if (Title->text() == "CMYK") {
        LineEdit_Changed(LineEdit_4, 0, 255, Statement);
    }
}
