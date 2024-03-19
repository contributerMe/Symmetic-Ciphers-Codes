#include <iostream>
#include <string>
using namespace std;
// Vigenere Cipher
const string plaintextValues = "0123456789 abcdefghijklmnopqrstuvwxyz";
const int plaintextSize = plaintextValues.size();
const string ciphertextValues = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char vigenereEncryptChar(char plaintextChar, char key) {
    int plaintextIndex = plaintextValues.find(tolower(plaintextChar));
    int keyIndex = plaintextValues.find(tolower(key));
    if (plaintextIndex != std::string::npos) {
        return ciphertextValues[(plaintextIndex + keyIndex) % plaintextSize];
    } else {
        return plaintextChar;
    }
}

string vigenereEncrypt(string& plaintext, string& key) {
    string ciphertext = "";
    int keyLength = key.length();
    int keyIndex = 0;

    for (char c : plaintext) {
        if (isalnum(c) || c == ' ') { 
            ciphertext += vigenereEncryptChar(c, key[keyIndex]);
            keyIndex = (keyIndex + 1) % keyLength; 
        } else {
            ciphertext += c; 
        }
    }

    return ciphertext;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

  string plaintext = ""; 
    for (int i = 1; i < argc; ++i) {
        plaintext += argv[i]; 
        if (i < argc - 1) {
            plaintext += " "; 
        }
    }

    string key = "nimeshmaslekar"; 

    string ciphertext = vigenereEncrypt(plaintext, key);
    cout <<ciphertext;

    return 0;
}
