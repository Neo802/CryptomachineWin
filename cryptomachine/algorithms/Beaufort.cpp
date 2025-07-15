#include "Beaufort.h"

// ...existing code...
static QString performBeaufort(const QString& text, const QString& key) {
    QString result;
    QString upKey = key.toUpper();
    int keyIndex = 0;
    for (QChar character : text) {
        if (character.isUpper()) {
            QChar encryptedChar = QChar(((upKey[keyIndex].unicode() - character.unicode() + 26) % 26) + 'A');
            result.append(encryptedChar);
            keyIndex = (keyIndex + 1) % upKey.length();
        } else if (character.isLower()) {
            QChar encryptedChar = QChar(((upKey[keyIndex].unicode() - character.toUpper().unicode() + 26) % 26) + 'A');
            result.append(encryptedChar);
            keyIndex = (keyIndex + 1) % upKey.length();
        } else {
            result.append(character);
        }
    }
    return result;
}

QString Beaufort::encrypt(const QString& text, const QString& key) {
    return performBeaufort(text, key);
}

QString Beaufort::decrypt(const QString& text, const QString& key) {
    return performBeaufort(text, key);
}