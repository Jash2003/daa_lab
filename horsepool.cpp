13-05-23 03:04
#include <iostream>
#include <string>
using namespace std;

const int MAXCHAR = 256;

void computeShiftTable(int shiftTable[], const string& pattern) {
    int m = pattern.length();
    for (int i = 0; i < MAXCHAR; i++) {
        shiftTable[i] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        shiftTable[pattern[j]] = m - 1 - j;
    }
}

int horspoolSearch(const string& text, const string& pattern, int& compSuccess, int& compFailure) {
    int n = text.length();
    int m = pattern.length();
    int shiftTable[MAXCHAR];
    computeShiftTable(shiftTable, pattern);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        compSuccess++;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
            compSuccess++;
        }
        if (k == m) {
            return i - m + 1; // successful match
        } else {
            compFailure++;
            i += shiftTable[text[i]];
        }
    }
    return -1; // unsuccessful match
}

int main() {
	char text[100], pattern[100];
    cout<<"Enter a text:";
    cin.getline(text,100);
    cout<<"Enter a pattern:";
    cin.getline(pattern,100);
    int compSuccess = 0, compFailure = 0;
    int index = horspoolSearch(text, pattern, compSuccess, compFailure);
    if (index == -1)
        cout << "Pattern not found!" << endl;
    else
        cout << "Pattern found at index " << index << " in the text" << endl;
    cout << "Number of key comparisons in successful search: " << compSuccess << endl;
    cout << "Number of key comparisons in unsuccessful search: " << compFailure << endl;
    return 0;
}
