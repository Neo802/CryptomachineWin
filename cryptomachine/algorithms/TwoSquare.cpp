#include "TwoSquare.h"
#include <QSet>
#include <QStringList>
#include <QRegularExpression>

void TwoSquare::prepareMatrices(const QString& key1, const QString& key2) {
    createMatrix(key1, matrix1);
    createMatrix(key2, matrix2);
}

void TwoSquare::createMatrix(const QString& key, QChar matrix[5][5]) {
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
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        QChar c = QChar(ch);
        if (c == 'J') continue;
        if (!usedChars.contains(c)) {
            matrix[row][col++] = c;
            usedChars.insert(c);
            if (col == 5) { row++; col = 0; }
        }
    }
}

int* TwoSquare::findPosition(QChar c, QChar matrix[5][5]) {
    static int pos[2];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (matrix[i][j] == c) {
                pos[0] = i; pos[1] = j; return pos;
            }
    return nullptr;
}

QString TwoSquare::processText(const QString& text, bool encrypt) {
    QString upText = text.toUpper().replace("J", "I").remove(QRegularExpression("[^A-Z]"));
    QString processedText;
    for (int i = 0; i < upText.length(); i += 2) {
        QChar first = upText[i];
        QChar second = (i + 1 < upText.length()) ? upText[i + 1] : 'X';
        int* pos1 = findPosition(first, matrix1);
        int* pos2 = findPosition(second, matrix2);
        if (pos1 && pos2) {
            if (pos1[0] == pos2[0]) {
                processedText.append(matrix1[pos1[0]][(pos1[1] + (encrypt ? 1 : 4)) % 5]);
                processedText.append(matrix2[pos2[0]][(pos2[1] + (encrypt ? 1 : 4)) % 5]);
            } else {
                processedText.append(matrix1[pos1[0]][pos2[1]]);
                processedText.append(matrix2[pos2[0]][pos1[1]]);
            }
        }
    }
    return processedText;
}

QString TwoSquare::encrypt(const QString& text, const QString& key) {
    QStringList keys = key.split(';');
    if (keys.size() != 2) return text;
    prepareMatrices(keys[0], keys[1]);
    return processText(text, true);
}

QString TwoSquare::decrypt(const QString& text, const QString& key) {
    QStringList keys = key.split(';');
    if (keys.size() != 2) return text;
    prepareMatrices(keys[0], keys[1]);
    return processText(text, false);
}