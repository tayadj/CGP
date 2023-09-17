#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication Application(argc, argv);
    MainWindow Window;
    Window.show();
    return Application.exec();
}
