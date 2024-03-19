#include<bits/stdc++.h>
using namespace std;
// Rotar cipher
string rotarEncrypt(const string& plaintext, const string& keyMapping) {

    map<char, char> mpp;
    string s = "0123456789 abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 36; ++i) {
        mpp[s[i]] = keyMapping[i];
    }

    // Encrypt the plaintext using the mpp
    string ciphertext = "";
    for (auto c : plaintext) {
        ciphertext += mpp[c];
    }

    return ciphertext;
}

void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }
     string plain_txt="";
    for (int i = 1; i < argc; i++) {
        plain_txt += argv[i];
        if (i < argc - 1) {
            plain_txt += " "; 
        }
    }

    string keyMapping = "nimeshalkrbcdefgjopqtuvwxy 0123456789"; 
    leftrotate(keyMapping,4);

    // cout<<keyMapping.size();
    string ciphertext = rotarEncrypt(plain_txt, keyMapping);
    transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::toupper); 
    cout << ciphertext;

    return 0;
}
