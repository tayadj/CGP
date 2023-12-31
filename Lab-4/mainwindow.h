#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <naivealgorithm.h>
#include <brforsegment.h>
#include <brforcircle.h>
#include <dialog.h>
#include <dda.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void showBrCircle();
        void showBrSegment();
        void showNaive();
        void showDDA();
        void outOfRangeError();

    private:
        Ui::MainWindow              *ui;
        QGridLayout                 *l = new QGridLayout;
        BrForCircle                 *brfc = new BrForCircle(0,0,5);
        BrForSegment                *brfs = new BrForSegment(0,0,5,5);
        NaiveAlgorithm              *naive = new NaiveAlgorithm(0,0,5,5);
        DDA                         *dda = new DDA(0,0,5,5);
        QPushButton                 *pbBrCircle = new QPushButton;
        QPushButton                 *pbBrSegment= new QPushButton;
        QPushButton                 *pbNaiveAlgorithm = new QPushButton;
        QLabel                      *lText = new QLabel;
        QPushButton                 *pbDDA = new QPushButton;
        Dialog                      *d;
};

#endif
