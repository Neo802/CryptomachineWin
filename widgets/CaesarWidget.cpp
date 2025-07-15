#include "CaesarWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QGroupBox>
#include "cryptomachine/algorithms/Caesar.h"

CaesarWidget::CaesarWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);

    auto* label = new QLabel("<h2>Caesar Cipher Widget</h2>", this);
    layout->addWidget(label);

    // --- Standard Caesar Cipher UI ---
    auto* textEdit = new QLineEdit;
    auto* keyEdit = new QLineEdit;
    auto* resultLabel = new QLabel;
    auto* encryptBtn = new QPushButton("Encrypt");
    auto* decryptBtn = new QPushButton("Decrypt");
    auto* analyzeBtn = new QPushButton("Analyze");

    resultLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    layout->addWidget(new QLabel("Text:"));
    layout->addWidget(textEdit);
    layout->addWidget(new QLabel("Key:"));
    layout->addWidget(keyEdit);
    layout->addWidget(encryptBtn);
    layout->addWidget(decryptBtn);
    layout->addWidget(analyzeBtn);
    layout->addWidget(new QLabel("Result:"));
    layout->addWidget(resultLabel);

    Caesar* caesar = new Caesar;

    connect(encryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(caesar->encrypt(textEdit->text(), keyEdit->text()));
    });
    connect(decryptBtn, &QPushButton::clicked, this, [=] {
        resultLabel->setText(caesar->decrypt(textEdit->text(), keyEdit->text()));
    });

    // --- Cryptoanalysis Section ---
    auto* cryptoGroup = new QGroupBox("Caesar Cryptoanalysis (Brute-force all shifts)", this);
    auto* cryptoLayout = new QVBoxLayout(cryptoGroup);

    auto* cryptoInput = new QTextEdit;
    cryptoInput->setPlaceholderText("Paste ciphertext here...");
    auto* cryptoResult = new QLabel("Results will appear here.");
    cryptoResult->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    cryptoResult->setWordWrap(true);
    
    cryptoLayout->addWidget(new QLabel("All possible shifts:"));
    cryptoLayout->addWidget(cryptoResult);

    layout->addWidget(cryptoGroup);

    connect(analyzeBtn, &QPushButton::clicked, this, [textEdit, cryptoResult]() {
        QString text = textEdit->text();
        QString results;
        for (int shift = 1; shift < 26; ++shift) {
            QString decrypted;
            for (QChar c : text) {
                if (c.isUpper()) {
                    decrypted += QChar('A' + (c.unicode() - 'A' + 26 - shift) % 26);
                } else if (c.isLower()) {
                    decrypted += QChar('a' + (c.unicode() - 'a' + 26 - shift) % 26);
                } else {
                    decrypted += c;
                }
            }
            results += QString("Shift %1: %2\n").arg(shift).arg(decrypted);
        }
        cryptoResult->setText(results);
    });
}
