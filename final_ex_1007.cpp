#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> dict;
int main() {
    string words, foreign_word, english_word;
    do {
        getline(cin, words);
        if (words[0] != '\0') {
            std::size_t pos = words.find(" ");
            english_word = words.substr(0, pos);
            foreign_word = words.substr(pos + 1);
            dict[foreign_word] = english_word;
        }
    } while (words[0] != '\0');
    while (cin >> words) {
        if (dict.find(words) != dict.end()) {
            cout << dict[words] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}
