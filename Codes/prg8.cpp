#include <bits/stdc++.h>
using namespace std;

string railFenceEncrypt(const string& plaintext, int rails) {
    vector<string> fence(rails, "");
    int row = 0;
    bool down = false;

    for (char c : plaintext) {
        fence[row] += c;
        if (row == 0 || row == rails - 1) {
            down = !down; }
        row += down ? 1 : -1; 
    }

    string ciphertext = "";
    for (const string& rail : fence) {
        ciphertext += rail;
    }
    return ciphertext;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }
    string plain_txt = "";
    for (int i = 1; i < argc; i++) {
        plain_txt += argv[i];
        if (i < argc - 1) {
            plain_txt += " "; 
        }
    }

    int rails = 4; 
    string ciphertext = railFenceEncrypt(plain_txt, rails);transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), 
              ::toupper); 

    cout << ciphertext;

    return 0;
}
