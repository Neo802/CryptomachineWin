#include "Autokey.h"

QString Autokey::encrypt(const QString& text, const QString& key) {
    QString upText = text.toUpper();
    QString upKey = key.toUpper();
    QString result;
    QString extendedKey = upKey + upText;
    extendedKey = extendedKey.left(upText.length());
    for (int i = 0; i < upText.length(); ++i) {
        QChar plaintextChar = upText[i];
        if (plaintextChar.isLetter()) {
            QChar keyChar = extendedKey[i];
            QChar encryptedChar = QChar(((plaintextChar.unicode() - 'A' + (keyChar.unicode() - 'A')) % 26) + 'A');
            result.append(encryptedChar);
        } else {
            result.append(plaintextChar);
        }
    }
    return result;
}

QString Autokey::decrypt(const QString& text, const QString& key) {
    QString upText = text.toUpper();
    QString upKey = key.toUpper();
    QString result;
    for (int i = 0; i < upText.length(); ++i) {
        QChar ciphertextChar = upText[i];
        if (ciphertextChar.isLetter()) {
            QChar keyChar = (i < upKey.length()) ? upKey[i] : result[i - upKey.length()];
            QChar decryptedChar = QChar(((ciphertextChar.unicode() - keyChar.unicode() + 26) % 26) + 'A');
            result.append(decryptedChar);
        } else {
            result.append(ciphertextChar);
        }
    }
    return result;
}