#ifndef VIGENERE_H
#define VIGENERE_H

#include "Cipher.h"

class Vigenere : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
};

#endif // VIGENERE_H
