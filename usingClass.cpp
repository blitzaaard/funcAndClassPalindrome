#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class palindrome_checker {
private:
    string input;
    
    string clean_string(string& input){
        string new_string;
        for(char c : input){
            if(isalnum(c)){
                new_string += c;
            }
        }
        return new_string;
    }

public:
    palindrome_checker(string input) : input(input) {
        this->input = clean_string(this->input);
    }

    bool palindrome() { 
        cout<< "Input : " << input <<endl;
        int palindrome_len = input.length();
        for (int i = 0; i < palindrome_len/2; i++){
            if(input[i] != input[palindrome_len - 1 - i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string allTexts;
    cout << "Input the texts (separated by '|' symbol): ";
    getline(cin, allTexts);

    vector<string> textList;
    string currentText;
    for (char c : allTexts) {
        if (c == '|') {
            if (!currentText.empty()) {
                textList.push_back(currentText);
                currentText = "";
            }
        } else {
            currentText += c;
        }
    }
    if (!currentText.empty()) {
        textList.push_back(currentText);
    }

    for (int i = 0; i < textList.size(); i++) {
        palindrome_checker checker(textList[i]);
        if (checker.palindrome()){
            cout << "Text number " << i + 1 << " is a palindrome" << endl;
        } else {
            cout << "Text number " << i + 1 << " is not a palindrome" << endl;
        }
    }

    return 0;
}
