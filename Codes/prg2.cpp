#include <bits/stdc++.h>

// Affine 
    #define K_ROLL1 4 // roll_no = 004
    #define K_ROLL2 0 
    using namespace std;
const string plaintextValues = "0123456789 abcdefghijklmnopqrstuvwxyz";
const int plaintextSize = plaintextValues.size();
const string ciphertextValues = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int customMod(int value, int mod) {
    return (value % mod + mod) % mod;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

string affineEncrypt(const std::string& plaintext, int k1, int k2) {
    string ciphertext = "";
    int inverseK1 = modInverse(k1, plaintextSize);

    for (char c : plaintext) {
        int position = plaintextValues.find(c);
        if (position != std::string::npos) {
            position = customMod((k1 * position + k2), plaintextSize);
            ciphertext += ciphertextValues[position];
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <plaintext>" << std::endl;
        return 1;
    }

    std::string plaintext = ""; 
    for (int i = 1; i < argc; ++i) {
        plaintext += argv[i]; 
        if (i < argc - 1) {
            plaintext += " "; 
        }
    }


    int k1 = K_ROLL1;
    int k2 = K_ROLL2;

    string ciphertext = affineEncrypt(plaintext, k1, k2);
    for (char& ch : ciphertext) {
        if (islower(ch)) {
            ch = toupper(ch);
        }
    }

    cout << ciphertext;

    return 0;
}
