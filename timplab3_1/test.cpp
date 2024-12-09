#include <UnitTest++/UnitTest++.h>
#include "modAlphakey.h"

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText) {
    modAlphakey cipher(123); 
    CHECK_THROW(cipher.encrypt(""), std::invalid_argument);
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    modAlphakey cipher(123); 
    CHECK_THROW(cipher.decrypt(""), std::invalid_argument); 
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText) {
    modAlphakey cipher(123); // Пример ключа
    CHECK_THROW(cipher.encrypt("Hello"), std::invalid_argument); 
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness) {
    modAlphakey cipher(3); 
    std::string encrypted = cipher.encrypt("HELLO"); 
    CHECK(encrypted == "HLEOL"); 
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness) {
    modAlphakey cipher(3); 
    std::string decrypted = cipher.decrypt("HLEOL"); 
    CHECK(decrypted == "HELLO"); 
}

// Тест на шифрование текста с невалидным ключом
TEST(TestInvalidKey) {
    CHECK_THROW(modAlphakey cipher(-1), std::invalid_argument); 
}

// Тест на шифрование текста с ключом, превышающим длину текста
TEST(TestKeyGreaterThanTextLength) {
    modAlphakey cipher(10); 
    CHECK_THROW(cipher.encrypt("HELLO"), std::invalid_argument); 
}


int main() {
    return UnitTest::RunAllTests();
}













