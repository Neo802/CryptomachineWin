#ifndef BEAUFORT_H
#define BEAUFORT_H

#include "Cipher.h"

class Beaufort : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
};

#endif // BEAUFORT_H
