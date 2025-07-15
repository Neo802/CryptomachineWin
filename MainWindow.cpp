#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
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
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    setupWelcomePage();
    setupAlgorithmMenuPage();

    stackedWidget->addWidget(welcomePage);         // index 0
    stackedWidget->addWidget(algorithmMenuPage);   // index 1

    // Show welcome page at startup
    stackedWidget->setCurrentWidget(welcomePage);
}

void MainWindow::setupWelcomePage() {
    welcomePage = new QWidget(this);
    auto* layout = new QVBoxLayout(welcomePage);

    auto* welcomeLabel = new QLabel("<h1>Welcome to CryptomachineWin!</h1>", welcomePage);
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    auto* guideLabel = new QLabel("To get started, click the button below to select a cryptographic algorithm.", welcomePage);
    guideLabel->setAlignment(Qt::AlignCenter);
    guideLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    auto* selectAlgoBtn = new QPushButton("Select Algorithm", welcomePage);
    connect(selectAlgoBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);

    layout->addStretch();
    layout->addWidget(welcomeLabel);
    layout->addWidget(guideLabel);
    layout->addWidget(selectAlgoBtn, 0, Qt::AlignCenter);
    layout->addStretch();
}

void MainWindow::setupAlgorithmMenuPage() {
    algorithmMenuPage = new QWidget(this);
    auto* layout = new QVBoxLayout(algorithmMenuPage);

    auto* label = new QLabel("<b>Select an Algorithm:</b>", algorithmMenuPage);
    label->setAlignment(Qt::AlignCenter);
    label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    layout->addWidget(label);

    auto* caesarBtn = new QPushButton("Caesar", algorithmMenuPage);
    connect(caesarBtn, &QPushButton::clicked, this, &MainWindow::showCaesar);
    layout->addWidget(caesarBtn);

    auto* vigenereBtn = new QPushButton("Vigenere", algorithmMenuPage);
    connect(vigenereBtn, &QPushButton::clicked, this, &MainWindow::showVigenere);
    layout->addWidget(vigenereBtn);

    auto* beaufortBtn = new QPushButton("Beaufort", algorithmMenuPage);
    connect(beaufortBtn, &QPushButton::clicked, this, &MainWindow::showBeaufort);
    layout->addWidget(beaufortBtn);

    auto* autokeyBtn = new QPushButton("Autokey", algorithmMenuPage);
    connect(autokeyBtn, &QPushButton::clicked, this, &MainWindow::showAutokey);
    layout->addWidget(autokeyBtn);

    auto* vatsayanaBtn = new QPushButton("Vatsayana", algorithmMenuPage);
    connect(vatsayanaBtn, &QPushButton::clicked, this, &MainWindow::showVatsayana);
    layout->addWidget(vatsayanaBtn);

    auto* playfairBtn = new QPushButton("Playfair", algorithmMenuPage);
    connect(playfairBtn, &QPushButton::clicked, this, &MainWindow::showPlayfair);
    layout->addWidget(playfairBtn);

    auto* twoSquareBtn = new QPushButton("TwoSquare", algorithmMenuPage);
    connect(twoSquareBtn, &QPushButton::clicked, this, &MainWindow::showTwoSquare);
    layout->addWidget(twoSquareBtn);

    auto* fourSquareBtn = new QPushButton("FourSquare", algorithmMenuPage);
    connect(fourSquareBtn, &QPushButton::clicked, this, &MainWindow::showFourSquare);
    layout->addWidget(fourSquareBtn);

    auto* backBtn = new QPushButton("Back", algorithmMenuPage);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showWelcome);
    layout->addWidget(backBtn);
}

void MainWindow::showWelcome() {
    stackedWidget->setCurrentWidget(welcomePage);
}

void MainWindow::showAlgorithmMenu() {
    stackedWidget->setCurrentWidget(algorithmMenuPage);
}

void MainWindow::showCaesar() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new CaesarWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showVigenere() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new VigenereWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showBeaufort() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new BeaufortWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showAutokey() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new AutokeyWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showVatsayana() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new VatsayanaWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showPlayfair() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new PlayfairWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showTwoSquare() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new TwoSquareWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}

void MainWindow::showFourSquare() {
    auto* widget = new QWidget(this);
    auto* layout = new QVBoxLayout(widget);
    auto* algoWidget = new FourSquareWidget(widget);
    layout->addWidget(algoWidget);

    auto* backBtn = new QPushButton("Back", widget);
    connect(backBtn, &QPushButton::clicked, this, &MainWindow::showAlgorithmMenu);
    layout->addWidget(backBtn);

    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
}
