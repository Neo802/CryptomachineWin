#include "CaesarWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "cryptomachine/algorithms/Caesar.h"

CaesarWidget::CaesarWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    auto* textEdit = new QLineEdit;
    auto* keyEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt");
    auto* decryptBtn = new QPushButton("Decrypt");
    auto* label = new QLabel("Caesar Cipher Widget", this);

    resultLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Key:"));
    layout->addWidget(keyEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(decryptBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);
    layout->addWidget(label);

    Caesar* caesar = new Caesar;

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(caesar->encrypt(textEdit->text(), keyEdit->text()));
    });
    connect(decryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(caesar->decrypt(textEdit->text(), keyEdit->text()));
    });
}
