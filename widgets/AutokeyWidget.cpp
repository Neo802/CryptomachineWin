#include "AutokeyWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "cryptomachine/algorithms/Autokey.h"

AutokeyWidget::AutokeyWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Autokey Cipher Widget", this));

    auto* textEdit = new QLineEdit;
    auto* keyEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt");
    auto* decryptBtn = new QPushButton("Decrypt");

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Key:"));
    layout->addWidget(keyEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(decryptBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);

    Autokey* autokey = new Autokey;

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(autokey->encrypt(textEdit->text(), keyEdit->text()));
    });
    connect(decryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(autokey->decrypt(textEdit->text(), keyEdit->text()));
    });
}
