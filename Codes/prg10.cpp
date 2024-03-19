#include <bits/stdc++.h>
using namespace std;
void keyedTrasCiph(const string &plain_txt, string &keyMapping){
    int sizeOfKey = keyMapping.size();
    int cols = sizeOfKey ;
    int rows =  (plain_txt.size() + cols - 1) / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols,'$'));
    int index = 0 ; 
    for(int i = 0 ; i < rows; i++){
        for(int j = 0 ; j < cols && index < plain_txt.size(); j++){
            matrix[i][j] = plain_txt[index];
            index++;
        }
    }

    map<char, int> charIndexMap;
    for (int i = 0; i < sizeOfKey; ++i) {
        charIndexMap[keyMapping[i]] = i;
    }

    string sortedKeyMapping = keyMapping;
    sort(sortedKeyMapping.begin(), sortedKeyMapping.end());

    // Rearrange the columns of the matrix 
    vector<vector<char>> rearrangedMatrix(rows, vector<char>(cols));
    for (int i = 0; i < cols; ++i) {
        int newIndex = charIndexMap[sortedKeyMapping[i]];
        for (int j = 0; j < rows; ++j) {
            rearrangedMatrix[j][i] = matrix[j][newIndex];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if( rearrangedMatrix[i][j]!='$'){
                char c = rearrangedMatrix[i][j];
                c = toupper(c);
            cout << c;
            }
        }
    }
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
 
keyedTrasCiph(plain_txt,keyMapping);
    return 0;
}
