#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Widget widget;
    widget.show();
    return application.exec();
}
