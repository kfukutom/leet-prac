#include<iostream>
#include<string>
#include<vector>
using namespace std;

string getSmallestString(string word, string substr) {
    if (word.length() < 1) {
        return word;
    }
    
    string smallest = "";
    const int subLen = substr.length();
    const int wordLen = word.length();
    
    for (int i = 0; i <= word.length() - subLen; ++i) {
        string temp = word;
        bool valid = true;
        
        for (int j = 0; j < subLen; ++j) {
            if (temp[i+j] != '?' && temp[i+j] != substr[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (int j = 0; j < subLen; ++j) {
                temp[i+j] = substr[j];
            }
            
            for (char& c : temp) {
                if (c == '?') {
                    c = 'a';
                }
            }
            
            if (temp.find(substr) != string::npos) {
                if (smallest.empty() || temp < smallest) {
                    smallest = temp;
                }
            }
        }
    }
    return smallest.empty() ? "-1" : smallest;
}

int main()
{
    string word;
    getline(cin, word);

    string substr;
    getline(cin, substr);

    string result = getSmallestString(word, substr);

    std::cout << result << "\n";
    return 0;
}
