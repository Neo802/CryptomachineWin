#ifndef VATSAYANA_H
#define VATSAYANA_H

#include "Cipher.h"

class Vatsayana : public Cipher {
public:
    Vatsayana(const QString& keyMapping);
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
private:
    QString keyMapping;
};

#endif // VATSAYANA_H
