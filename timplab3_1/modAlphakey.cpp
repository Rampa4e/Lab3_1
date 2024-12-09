#include "modAlphakey.h"
#include <stdexcept>
#include <string>

using namespace std;

std::string modAlphakey::encrypt(const std::string& open_text) {
    if (open_text.empty()) {
        throw invalid_argument("Input text cannot be empty.");
    }
    if (static_cast<size_t>(key1) > open_text.length()) {
        throw invalid_argument("Key cannot be greater than text length.");
    }

    string encrypted_text(open_text.length(), ' ');
    size_t num_rows = (open_text.length() - 1) / key1 + 1;

    size_t pos = 0;
    for (size_t col = 0; col < static_cast<size_t>(key1); col++) {
        for (size_t row = 0; row < num_rows; row++) {
            size_t index = col + row * key1;
            if (index < open_text.length()) {
                encrypted_text[pos++] = open_text[index];
            }
        }
    }
    return encrypted_text;
}

std::string modAlphakey::decrypt(const std::string& cipher_text) {
    if (cipher_text.empty()) {
        throw invalid_argument("Cipher text cannot be empty.");
    }
    if (static_cast<size_t>(key1) > cipher_text.length()) {
        throw invalid_argument("Key cannot be greater than text length.");
    }

    string decrypted_text(cipher_text.length(), ' ');
    size_t num_rows = (cipher_text.length() - 1) / key1 + 1;

    size_t pos = 0;
    for (size_t col = 0; col < static_cast<size_t>(key1); col++) {
        for (size_t row = 0; row < num_rows; row++) {
            size_t index = col + row * key1;
            if (index < cipher_text.length()) {
                decrypted_text[index] = cipher_text[pos++];
            }
        }
    }
    return decrypted_text;
}










