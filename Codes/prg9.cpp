#include <bits/stdc++.h>
using namespace std;

string KeylessTransCiph(const string& plaintext, int rows) {
    // no of columns needed
    int cols = (plaintext.size() + rows - 1) / rows;
    // int cols = int(ceil(float(plaintext.size())/rows*1.0));
    vector<vector<char>> table(rows, vector<char>(cols, '0'));
// writing row by row
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols && index < plaintext.size(); j++) {
            table[i][j] = plaintext[index];
            index++;
        }
    }
// reading col by col
    string ciphertext = "";
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; ++i) 
        {if (table[i][j] != '0') {
                ciphertext += table[i][j];
            }
        }
    }

    return ciphertext;
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

    int rows = 4; 

    string ciphertext = KeylessTransCiph(plain_txt, rows);
    transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), 
              ::toupper); 
    cout <<ciphertext;

    return 0;
}
