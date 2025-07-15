#ifndef CAESAR_H
#define CAESAR_H

#include "Cipher.h"

class Caesar : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
};

#endif // CAESAR_H
