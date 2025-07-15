#ifndef FOURSQUARE_H
#define FOURSQUARE_H

#include "Cipher.h"

class FourSquare : public Cipher {
public:
    QString encrypt(const QString& text, const QString& key) override;
    QString decrypt(const QString& text, const QString& key) override;
private:
    void prepareMatrices(const QString& key1, const QString& key2);
    void createStandardMatrix(QChar matrix[5][5]);
    void createKeyMatrix(const QString& key, QChar matrix[5][5]);
    int* findPosition(QChar c, QChar matrix[5][5]);
    QString processText(const QString& text, bool encrypt);
    QChar plainMatrix1[5][5], plainMatrix2[5][5], keyMatrix1[5][5], keyMatrix2[5][5];
};

#endif // FOURSQUARE_H
