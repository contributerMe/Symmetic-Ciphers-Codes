#include <bits/stdc++.h>
// Hill cipher 
using namespace std;

const string plaintextValues = "0123456789 abcdefghijklmnopqrstuvwxyz";
const int plaintextSize = plaintextValues.size();
const string ciphertextValues = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to generate the key matrix from the key string
vector<vector<int>> generateKeyMatrix(const string& key) {
    vector<vector<int>> keyMatrix(5, vector<int>(5, 0));
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            keyMatrix[i][j] = (tolower(key[index]) - 'a') % plaintextSize;
            index = (index + 1) % key.size();
        }
    }
    return keyMatrix;
}

// Function to perform matrix multiplication
vector<int> matrixMultiply(const vector<vector<int>>& matrix, const vector<int>& vector1, int rows) {
    vector<int> result(rows, 0); // Initialize result vector with the number of rows passed
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < vector1.size(); ++j) {
            result[i] += matrix[i][j] * vector1[j];
        }
        result[i] %= plaintextSize;
    }
    return result;
}

// Function to encrypt plaintext using Hill Cipher
string hillEncrypt(const string& plaintext, const string& key) {
    vector<vector<int>> keyMatrix = generateKeyMatrix(key);
    string ciphertext = "";
    int blockSize = keyMatrix.size();

    for (int i = 0; i < plaintext.size(); i += blockSize) {
        vector<int> plaintextBlock(blockSize, 0);
        for (int j = 0; j < blockSize && i + j < plaintext.size(); ++j) {
            plaintextBlock[j] = plaintextValues.find(tolower(plaintext[i + j]));
        }

        // Multiply plaintext block with key matrix
        vector<int> ciphertextBlock = matrixMultiply(keyMatrix, plaintextBlock, blockSize);

        // Convert ciphertext block to string
        for (int j = 0; j < blockSize; ++j) {
            ciphertext += plaintextValues[ciphertextBlock[j]];

        }
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

    string key = "nimeshmaslekar"; 
    // vector<vector<int>> keyMatrix = generateKeyMatrix(key);
    // for(auto x : keyMatrix){
    //     for(auto y : x){
    //             cout<<y<<" ";
    //     }
    // }
    string ciphertext = hillEncrypt(plain_txt, key);
     transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), 
              ::toupper); 
    cout << ciphertext;

    return 0;
}
