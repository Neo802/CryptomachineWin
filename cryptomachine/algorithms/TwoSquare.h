#ifndef TWOSQUARE_H
#define TWOSQUARE_H

#include "Cipher.h"

class TwoSquare : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
private:
    void prepareMatrices(const QString& key1, const QString& key2);
    void createMatrix(const QString& key, QChar matrix[5][5]);
    QString processText(const QString& text, bool encrypt);
    int* findPosition(QChar c, QChar matrix[5][5]);
    QChar matrix1[5][5];
    QChar matrix2[5][5];
};

#endif // TWOSQUARE_H
