#include "Vatsayana.h"

Vatsayana::Vatsayana(const QString& keyMapping)
    : keyMapping(keyMapping) {}

QString Vatsayana::encrypt(const QString& text, const QString& /*key*/) {
    QString encryptedText;
    for (QChar character : text) {
        if (character.isLetter()) {
            QChar base = character.isUpper() ? 'A' : 'a';
            int index = character.unicode() - base.unicode();
            if (index >= 0 && index < keyMapping.length())
                encryptedText.append(keyMapping[index]);
            else
                encryptedText.append(character);
        } else {
            encryptedText.append(character);
        }
    }
    return encryptedText;
}

QString Vatsayana::decrypt(const QString& text, const QString& /*key*/) {
    QString decryptedText;
    for (QChar character : text) {
        int index = keyMapping.indexOf(character);
        if (index != -1) {
            QChar base = character.isUpper() ? 'A' : 'a';
            decryptedText.append(QChar(index + base.unicode()));
        } else {
            decryptedText.append(character);
        }
    }
    return decryptedText;
}
