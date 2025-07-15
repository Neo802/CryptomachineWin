#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include "Cipher.h"

class Playfair : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
private:
    void prepareKeyMatrix(const QString& key);
    QString processText(const QString& text, bool encrypt);
    int keyMatrix[5][5];
    QChar keyMatrixChar[5][5];
    int* findPosition(QChar c);
};

#endif // PLAYFAIR_H
