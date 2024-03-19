#include <bits/stdc++.h>
#include<iostream>
using namespace std;
// Caesar
const string plaintextValues = "0123456789 abcdefghijklmnopqrstuvwxyz";
const int plaintextSize = plaintextValues.size();
const string ciphertextValues = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int customMod(int value, int mod) {
    return (value % mod + mod) % mod;
}
string CaesarEncrypt(const string plain_txt){
    int k_roll1= 4;
    
    string cipher_txt="";
    for (char c : plain_txt) {
        int position = plaintextValues.find(c);
        if (position != std::string::npos) {
            position = customMod(position + k_roll1, plaintextSize);
            cipher_txt += ciphertextValues[position];
        } 
        else {
            cipher_txt += c;
        }
    }

    return cipher_txt;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1; 
    }
    string plain_txt;
    for (int i = 1; i < argc; i++) {
        plain_txt += argv[i];
        if (i < argc - 1) {
            plain_txt += " "; 
        }
    }
    // cout<<plain_txt;
    string cipher_txt= CaesarEncrypt(plain_txt);
    cout<<cipher_txt;
    return 0;
}