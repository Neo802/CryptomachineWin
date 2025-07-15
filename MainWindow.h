#pragma once
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
private slots:
    void showCaesar();
    void showVigenere();
    void showBeaufort();
    void showAutokey();
    void showVatsayana();
    void showPlayfair();
    void showTwoSquare();
    void showFourSquare();
};
