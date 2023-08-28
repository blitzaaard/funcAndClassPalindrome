#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string clean_string(string& input){
    string new_string;
    for(char c : input){
        if(isalnum(c)){
            new_string += c;
        }
    }
    return new_string;
}

bool palindrome(string input){ 
    input = clean_string(input);
    cout<< "Input : " << input <<endl;
    int palindrome_len;
    palindrome_len = input.length();
    for (int i = 0; i < palindrome_len/2; i++){
        if(input[i] != input[palindrome_len - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    string allTexts;
    cout << "Input the texts (separated by '|' symbol): ";
    getline(cin, allTexts);

    vector<string> texts;
    string currentText;
    for (char c : allTexts) {
        if (c == '|') {
            if (!currentText.empty()) {
                texts.push_back(currentText);
                currentText = "";
            }
        } else {
            currentText += c;
        }
    }
    if (!currentText.empty()) {
        texts.push_back(currentText);
    }

    for (int i = 0; i < texts.size(); i++) {
        bool output = palindrome(texts[i]);
        if (output){
            cout << "Text number " << i + 1 << " is a palindrome" << endl;
        } else {
            cout << "Text number " << i + 1 << " is not a palindrome" << endl;
        }
    }

    return 0;
}