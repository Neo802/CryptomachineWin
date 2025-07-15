#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include "widgets/CaesarWidget.h"
#include "widgets/VigenereWidget.h"
#include "widgets/BeaufortWidget.h"
#include "widgets/AutokeyWidget.h"
#include "widgets/VatsayanaWidget.h"
#include "widgets/PlayfairWidget.h"
#include "widgets/TwoSquareWidget.h"
#include "widgets/FourSquareWidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QMenu* algoMenu = menuBar()->addMenu("Algorithms");
    algoMenu->addAction("Caesar", this, &MainWindow::showCaesar);
    algoMenu->addAction("Vigenere", this, &MainWindow::showVigenere);
    algoMenu->addAction("Beaufort", this, &MainWindow::showBeaufort);
    algoMenu->addAction("Autokey", this, &MainWindow::showAutokey);
    algoMenu->addAction("Vatsayana", this, &MainWindow::showVatsayana);
    algoMenu->addAction("Playfair", this, &MainWindow::showPlayfair);
    algoMenu->addAction("TwoSquare", this, &MainWindow::showTwoSquare);
    algoMenu->addAction("FourSquare", this, &MainWindow::showFourSquare);

    setCentralWidget(new QWidget); // Placeholder
}

void MainWindow::showCaesar() { setCentralWidget(new CaesarWidget(this)); }
void MainWindow::showVigenere() { setCentralWidget(new VigenereWidget(this)); }
void MainWindow::showBeaufort() { setCentralWidget(new BeaufortWidget(this)); }
void MainWindow::showAutokey() { setCentralWidget(new AutokeyWidget(this)); }
void MainWindow::showVatsayana() { setCentralWidget(new VatsayanaWidget(this)); }
void MainWindow::showPlayfair() { setCentralWidget(new PlayfairWidget(this)); }
void MainWindow::showTwoSquare() { setCentralWidget(new TwoSquareWidget(this)); }
void MainWindow::showFourSquare() { setCentralWidget(new FourSquareWidget(this)); }
