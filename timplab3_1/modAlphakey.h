#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class modAlphakey {
private:
    int key1; 
public:
    modAlphakey() = delete;
    modAlphakey(const int& key) {
        if (key <= 0) {
            throw std::invalid_argument("Key must be greater than 0.");
        }
        key1 = key;
    }

    std::string encrypt(const std::string& open_text);
    std::string decrypt(const std::string& cipher_text);
};


