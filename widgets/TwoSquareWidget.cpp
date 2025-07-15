#include "TwoSquareWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "cryptomachine/algorithms/TwoSquare.h"

TwoSquareWidget::TwoSquareWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    auto* label = new QLabel("Two Square Cipher Widget", this);
    layout->addWidget(label);

    auto* textEdit = new QLineEdit;
    auto* keyEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt");
    auto* decryptBtn = new QPushButton("Decrypt");

    keyEdit->setPlaceholderText("KEY1;KEY2");
    resultLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Keys (KEY1;KEY2):"));
    layout->addWidget(keyEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(decryptBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);

    TwoSquare* twosquare = new TwoSquare;

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(twosquare->encrypt(textEdit->text(), keyEdit->text()));
    });
    connect(decryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(twosquare->decrypt(textEdit->text(), keyEdit->text()));
    });
}
