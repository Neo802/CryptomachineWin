#ifndef CIPHER_H
#define CIPHER_H

#include <QString>

class Cipher {
public:
    virtual ~Cipher() {}
    virtual QString encrypt(const QString& text, const QString& key) = 0;
    virtual QString decrypt(const QString& text, const QString& key) = 0;
};

#endif // CIPHER_H