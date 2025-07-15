#include "VatsayanaWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "cryptomachine/algorithms/Vatsayana.h"

VatsayanaWidget::VatsayanaWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    auto* label = new QLabel("Vatsayana Cipher Widget", this);
    layout->addWidget(label);

    auto* textEdit = new QLineEdit;
    auto* keyMapEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt");
    auto* decryptBtn = new QPushButton("Decrypt");

    keyMapEdit->setPlaceholderText("Key mapping (26 letters, e.g. QWERTY...)");
    resultLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Key Mapping:"));
    layout->addWidget(keyMapEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(decryptBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        Vatsayana vatsayana(keyMapEdit->text());
        resultLabel->setText(vatsayana.encrypt(textEdit->text(), ""));
    });
    connect(decryptBtn, &QPushButton::clicked, this, [=] {
        Vatsayana vatsayana(keyMapEdit->text());
        resultLabel->setText(vatsayana.decrypt(textEdit->text(), ""));
    });
}
