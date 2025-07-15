#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void showWelcome();
    void showAlgorithmMenu();
    void showCaesar();
    void showVigenere();
    void showBeaufort();
    void showAutokey();
    void showVatsayana();
    void showPlayfair();
    void showTwoSquare();
    void showFourSquare();

private:
    QStackedWidget* stackedWidget;
    QWidget* welcomePage;
    QWidget* algorithmMenuPage;
    void setupWelcomePage();
    void setupAlgorithmMenuPage();
};
