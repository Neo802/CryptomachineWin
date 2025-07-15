#include "FourSquare.h"
#include <QSet>
#include <QStringList>
#include <QRegularExpression>

// Fills the matrix with the standard alphabet (A-Z, skipping J)
void FourSquare::createStandardMatrix(QChar matrix[5][5]) {
    int row = 0, col = 0;
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (i == 'J') continue;
        matrix[row][col++] = QChar(i);
        if (col == 5) { row++; col = 0; }
    }
}

void FourSquare::createKeyMatrix(const QString& key, QChar matrix[5][5]) {
    QString upKey = key.toUpper().replace("J", "I");
    QSet<QChar> usedChars;
    int row = 0, col = 0;
    for (QChar c : upKey) {
        if (c.isLetter() && !usedChars.contains(c)) {
            matrix[row][col++] = c;
            usedChars.insert(c);
            if (col == 5) { row++; col = 0; }
        }
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        QChar c(i);
        if (c == 'J') continue;
        if (!usedChars.contains(c)) {
            matrix[row][col++] = c;
            usedChars.insert(c);
            if (col == 5) { row++; col = 0; }
        }
    }
}

void FourSquare::prepareMatrices(const QString& key1, const QString& key2) {
    createStandardMatrix(plainMatrix1);
    createStandardMatrix(plainMatrix2);
    createKeyMatrix(key1, keyMatrix1);
    createKeyMatrix(key2, keyMatrix2);
}

int* FourSquare::findPosition(QChar c, QChar matrix[5][5]) {
    static int pos[2];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (matrix[i][j] == c) {
                pos[0] = i; pos[1] = j; return pos;
            }
    return nullptr;
}

QString FourSquare::processText(const QString& text, bool encrypt) {
    QString upText = text.toUpper().replace("J", "I").remove(QRegularExpression("[^A-Z]"));
    QString processedText;
    for (int i = 0; i < upText.length(); i += 2) {
        QChar first = upText[i];
        QChar second = (i + 1 < upText.length()) ? upText[i + 1] : 'X';
        if (encrypt) {
            int* pos1 = findPosition(first, plainMatrix1);
            int* pos2 = findPosition(second, plainMatrix2);
            processedText.append(keyMatrix1[pos1[0]][pos2[1]]);
            processedText.append(keyMatrix2[pos2[0]][pos1[1]]);
        } else {
            int* pos1 = findPosition(first, keyMatrix1);
            int* pos2 = findPosition(second, keyMatrix2);
            processedText.append(plainMatrix1[pos1[0]][pos2[1]]);
            processedText.append(plainMatrix2[pos2[0]][pos1[1]]);
        }
    }
    return processedText;
}

QString FourSquare::encrypt(const QString& text, const QString& key) {
    QStringList keys = key.split(';');
    if (keys.size() != 2) return text;
    prepareMatrices(keys[0], keys[1]);
    return processText(text, true);
}

QString FourSquare::decrypt(const QString& text, const QString& key) {
    QStringList keys = key.split(';');
    if (keys.size() != 2) return text;
    prepareMatrices(keys[0], keys[1]);
    return processText(text, false);
}