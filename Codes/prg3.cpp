#include <iostream>
#include <string>
#include <cstdlib>
// Autokey cipher similar to vegenere 
// autokey = 4 here 
// hello
// 4hell
// 
using namespace std;
  #define K_ROLL1 4 
const string plaintextValues = "0123456789 abcdefghijklmnopqrstuvwxyz";
const int plaintextSize = plaintextValues.size();
const string ciphertextValues = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int customMod(int value, int mod) {
    return (value % mod + mod) % mod;
}

string autokeyEncrypt(const std::string& plaintext) {
    string ciphertext = "";
    int key = K_ROLL1;
    for (char c : plaintext) {
        int position = plaintextValues.find(c);
        if (position != std::string::npos) {
            int encryptedChar = customMod((position + key), plaintextSize);
            ciphertext += ciphertextValues[encryptedChar];
            key = encryptedChar;
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

    std::string plaintext = "";
    for (int i = 1; i < argc; ++i) {
        plaintext += argv[i];
        if (i < argc - 1) {
            plaintext += " ";
        }
    }

    string ciphertext = autokeyEncrypt(plaintext);
    for (char& ch : ciphertext) {
        if (islower(ch)) {
            ch = toupper(ch);
        }
    }

    cout << ciphertext ;

    return 0;
}
