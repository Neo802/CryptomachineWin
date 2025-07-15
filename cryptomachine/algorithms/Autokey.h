#ifndef AUTOKEY_H
#define AUTOKEY_H

#include "Cipher.h"

class Autokey : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
};

#endif // AUTOKEY_H
