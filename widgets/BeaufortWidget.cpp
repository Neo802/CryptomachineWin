#include "BeaufortWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "cryptomachine/algorithms/Beaufort.h"

BeaufortWidget::BeaufortWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);

    auto* label = new QLabel("<h2>Beaufort Cipher Widget</h2>", this);
    layout->addWidget(label);

    auto* textEdit = new QLineEdit;
    auto* keyEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt/Decrypt");

    resultLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Key:"));
    layout->addWidget(keyEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);

    Beaufort* beaufort = new Beaufort;

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(beaufort->encrypt(textEdit->text(), keyEdit->text()));
    });
}
