#include "Caesar.h"

QString Caesar::encrypt(const QString& text, const QString& key) {
    bool ok;
    int intKey = key.toInt(&ok);
    if (!ok) return text;
    QString result;
    for (QChar character : text) {
        if (character.isUpper()) {
            QChar encryptedChar = QChar(((character.unicode() - 'A' + intKey) % 26) + 'A');
            result.append(encryptedChar);
        } else if (character.isLower()) {
            QChar encryptedChar = QChar(((character.unicode() - 'a' + intKey) % 26) + 'a');
            result.append(encryptedChar);
        } else {
            result.append(character);
        }
    }
    return result;
}

QString Caesar::decrypt(const QString& text, const QString& key) {
    bool ok;
    int intKey = key.toInt(&ok);
    if (!ok) return text;
    intKey = 26 - (intKey % 26);
    return encrypt(text, QString::number(intKey));
}
