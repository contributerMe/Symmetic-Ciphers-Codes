#include <bits/stdc++.h>
#define noAlpha 26

using namespace std;
#define maxSize 5
int SIZE = 5;

string cleanKey(const string& key) {
    string cleanedKey = "";
    vector<bool> present(26, false);

    for (char c : key) {
        if (c != ' ' && !present[tolower(c) - 'a']) {
            cleanedKey += tolower(c); 
            present[tolower(c) - 'a'] = true;
        }
    }

    while (cleanedKey.size() < 25) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!present[c - 'a']) {
                cleanedKey += c;
                present[c - 'a'] = true;
                break;
            }
        }
    }

    for (char& c : cleanedKey) {
        if (c == 'j')
            c = 'i';
    }

    return cleanedKey;
}

void constructMatrix(const string& key, vector<vector<char>>& matrix) {
    string cleanedKey = cleanKey(key);

    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = cleanedKey[index++];
        }
    }
}

void findPositions(const vector<vector<char>>& matrix, char a, char b, int& rowA, int& colA, int& rowB, int& colB) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == a) {
                rowA = i;
                colA = j;
            }
            if (matrix[i][j] == b) {
                rowB = i;
                colB = j;
            }
        }
    }
}

string encryptPair(const vector<vector<char>>& matrix, char a, char b) {
    int rowA, colA, rowB, colB;
    findPositions(matrix, a, b, rowA, colA, rowB, colB);

    if (rowA == rowB) {
        return string(1, matrix[rowA][(colA + 1) % SIZE]) + string(1, matrix[rowB][(colB + 1) % SIZE]);
    }
    else if (colA == colB) {
        return string(1, matrix[(rowA + 1) % SIZE][colA]) + string(1, matrix[(rowB + 1) % SIZE][colB]);
    }
    else {
        return string(1, matrix[rowA][colB]) + string(1, matrix[rowB][colA]);
    }
}

string playfairEncrypt(const string& plaintext, const string& key) {
    vector<vector<char>> matrix(SIZE, vector<char>(SIZE));
    constructMatrix(key, matrix);

    string ciphertext = "";
    int len = plaintext.length();
    for (int i = 0; i < len; i += 2) {
        char a = plaintext[i];
        char b = (i + 1 < len) ? plaintext[i + 1] : 'x'; 
        if (a == b) b = 'x';
        ciphertext += encryptPair(matrix, a, b);
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
    string ciphertext = playfairEncrypt(plaintext, key);
    for (char& ch : ciphertext) {
        if (islower(ch)) {
            ch = toupper(ch);
        }
    }
    cout << ciphertext ;

    return 0;
}
