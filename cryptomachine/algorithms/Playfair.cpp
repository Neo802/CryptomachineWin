#include "Playfair.h"
#include <QSet>
#include <QVector>
#include <QRegularExpression>

void Playfair::prepareKeyMatrix(const QString& key) {
    QString upKey = key.toUpper().replace("J", "I");
    QSet<QChar> usedChars;
    int row = 0, col = 0;
    // Fill key chars
    for (QChar c : upKey) {
        if (c.isLetter() && !usedChars.contains(c)) {
            keyMatrixChar[row][col++] = c;
            usedChars.insert(c);
            if (col == 5) { row++; col = 0; }
        }
    }
    // Fill rest of alphabet
    for (int i = 'A'; i <= 'Z'; ++i) {
        QChar c = QChar(i);
        if (c == 'J') continue;
        if (!usedChars.contains(c)) {
            keyMatrixChar[row][col++] = c;
            usedChars.insert(c);
            if (col == 5) { row++; col = 0; }
        }
    }
}

int* Playfair::findPosition(QChar c) {
    static int pos[2];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (keyMatrixChar[i][j] == c) {
                pos[0] = i; pos[1] = j; return pos;
            }
    return nullptr;
}

QString Playfair::processText(const QString& text, bool encrypt) {
    QString upText = text.toUpper().replace("J", "I").remove(QRegularExpression("[^A-Z]"));
    QVector<QString> digraphs;
    for (int i = 0; i < upText.length(); i += 2) {
        QChar first = upText[i];
        QChar second = (i + 1 < upText.length() && upText[i + 1] != first) ? upText[i + 1] : 'X';
        if (i + 1 < upText.length() && upText[i + 1] == first) {
            digraphs.append(QString() + first + 'X');
        } else {
            digraphs.append(QString() + first + second);
            if (second == 'X') i -= 1;
        }
    }
    QString processedText;
    for (const QString& pair : digraphs) {
        QChar first = pair[0], second = pair[1];
        int* pos1 = findPosition(first);
        int* pos2 = findPosition(second);
        if (pos1[0] == pos2[0]) {
            processedText.append(keyMatrixChar[pos1[0]][(pos1[1] + (encrypt ? 1 : 4)) % 5]);
            processedText.append(keyMatrixChar[pos2[0]][(pos2[1] + (encrypt ? 1 : 4)) % 5]);
        } else if (pos1[1] == pos2[1]) {
            processedText.append(keyMatrixChar[(pos1[0] + (encrypt ? 1 : 4)) % 5][pos1[1]]);
            processedText.append(keyMatrixChar[(pos2[0] + (encrypt ? 1 : 4)) % 5][pos2[1]]);
        } else {
            processedText.append(keyMatrixChar[pos1[0]][pos2[1]]);
            processedText.append(keyMatrixChar[pos2[0]][pos1[1]]);
        }
    }
    return processedText;
}

QString Playfair::encrypt(const QString& text, const QString& key) {
    prepareKeyMatrix(key);
    return processText(text, true);
}

QString Playfair::decrypt(const QString& text, const QString& key) {
    prepareKeyMatrix(key);
    return processText(text, false);
}