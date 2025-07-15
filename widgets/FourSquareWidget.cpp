#include "FourSquareWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "cryptomachine/algorithms/FourSquare.h"

FourSquareWidget::FourSquareWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);

    auto* label = new QLabel("<h2>Four Square Cipher Widget</h2>", this);
    layout->addWidget(label);

    auto* textEdit = new QLineEdit;
    auto* keyEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt");
    auto* decryptBtn = new QPushButton("Decrypt");

    resultLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    keyEdit->setPlaceholderText("KEY1;KEY2");

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Keys (KEY1;KEY2):"));
    layout->addWidget(keyEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(decryptBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);

    FourSquare* foursquare = new FourSquare;

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(foursquare->encrypt(textEdit->text(), keyEdit->text()));
    });
    connect(decryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(foursquare->decrypt(textEdit->text(), keyEdit->text()));
    });
}
