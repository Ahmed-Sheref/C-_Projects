// File: A2_S5,6_20231142_Sheet_problem(3)
// Author: Mohamed Sheref Abdelazeem Rady
// ID: 20231142
// TA: Bassant
// Date: 15 NOV
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
bool is_num(string w) {
    for (int i = 0; i < w.size(); ++i) {
        if (!isdigit(w[i])) {
            return false;
        }
    }
    return true;
}
int main() {
    string filename;
    cout << "Enter the name of file you want to count the frequency of its words: ";
    cin >> filename;
    map<string, int> frequency;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open the file " << filename << endl;
        return 1;
    }
    string word;
    size_t max_word_length = 4;
    while (file >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return ispunct(c);
        }), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (!is_num(word)) {
            frequency[word]++;
            max_word_length = max(max_word_length, word.size());
        }
    }
    file.close();
    size_t freq_col_width = 9;
    size_t table_width = max_word_length + freq_col_width + 5;
    cout << "+" << string(max_word_length + 2, '-') << "+" << string(freq_col_width + 2, '-') << "+" << endl;
    cout << "| " << left << setw(max_word_length) << "Word" << " | " << setw(freq_col_width) << "Frequency" << " |" << endl;
    cout << "+" << string(max_word_length + 2, '-') << "+" << string(freq_col_width + 2, '-') << "+" << endl;
    for (const auto& pair : frequency) {
        cout << "| " << left << setw(max_word_length) << pair.first
            << " | " << right << setw(freq_col_width) << pair.second << " |" << endl;
    }
    cout << "+" << string(max_word_length + 2, '-') << "+" << string(freq_col_width + 2, '-') << "+" << endl;
    return 0;
}