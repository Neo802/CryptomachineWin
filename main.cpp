#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("CryptomachineWin");
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}