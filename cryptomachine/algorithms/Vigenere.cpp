#include "Vigenere.h"

QString Vigenere::encrypt(const QString& text, const QString& key) {
    QString result;
    QString upKey = key.toUpper();
    int keyIndex = 0;
    for (QChar character : text) {
        if (character.isUpper()) {
            QChar encryptedChar = QChar(((character.unicode() - 'A' + (upKey[keyIndex].unicode() - 'A')) % 26) + 'A');
            result.append(encryptedChar);
            keyIndex = (keyIndex + 1) % upKey.length();
        } else if (character.isLower()) {
            QChar encryptedChar = QChar(((character.unicode() - 'a' + (upKey[keyIndex].unicode() - 'A')) % 26) + 'a');
            result.append(encryptedChar);
            keyIndex = (keyIndex + 1) % upKey.length();
        } else {
            result.append(character);
        }
    }
    return result;
}

QString Vigenere::decrypt(const QString& text, const QString& key) {
    QString result;
    QString upKey = key.toUpper();
    int keyIndex = 0;
    for (QChar character : text) {
        if (character.isUpper()) {
            QChar decryptedChar = QChar(((character.unicode() - 'A' - (upKey[keyIndex].unicode() - 'A') + 26) % 26) + 'A');
            result.append(decryptedChar);
            keyIndex = (keyIndex + 1) % upKey.length();
        } else if (character.isLower()) {
            QChar decryptedChar = QChar(((character.unicode() - 'a' - (upKey[keyIndex].unicode() - 'A') + 26) % 26) + 'a');
            result.append(decryptedChar);
            keyIndex = (keyIndex + 1) % upKey.length();
        } else {
            result.append(character);
        }
    }
    return result;
}