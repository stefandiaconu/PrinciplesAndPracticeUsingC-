//
//  main.cpp
//  Ch11-06
//
//  Created by Stefan Diaconu on 28/09/2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Ch11-06
string replace_punctuation(string&& sentence)
{
    string new_sentence = "";
    int count_quotes = 0;
    
    for (char ch : sentence)
    {
        if (ch == '"')
            count_quotes += 1;
        
        if ((ch == '.' || ch == ';' || ch == ',' || ch == '?' || ch == '-' || ch == '\'') && count_quotes % 2 == 0)
            new_sentence += ' ';
        else
            new_sentence += ch;
    }
    return new_sentence;
}

// Ch11-07
string replace_quote(string&& sentence)
{
    string new_sentence = "";
    vector<string> words;
    string words_elem = "";
    
    for (char& ch : sentence) {
        if (ch != ' ' && ch != sentence.back()) {
            words_elem += ch;
        }
        else {
            words.push_back(words_elem);
            words_elem = "";
        }
    }
    
    for (string& s : words){
        if (s == "don't") {
            s = "do not";
        }
        else if (s == "can't") {
            s = "cannot";
        }
        new_sentence += s + " ";
    }
    
    return new_sentence;
}

string to_lower(string&& sentence)
{
    string new_sentence = "";
    
    for (char& ch : sentence) {
        if (isupper(ch)) {
            ch = tolower(ch);
            new_sentence += ch;
        }
        else {
            new_sentence += ch;
        }
    }
    
    return new_sentence;
}


int main(int argc, const char * argv[]) {
    
    // Ch11-06
    string s1 = replace_punctuation(" - don't use the as-if rule.");
    cout << s1 << endl;
    string s2 = replace_punctuation(" - don't use the as-if rule. Try to change \"can't and d-a;s-h?\" ");
    cout << s2 << endl;
    string s3 = replace_punctuation(" - don't use the as-if rule. Try to change \"can't and d-a;s-h?\". Now let's try again \"can't and d-a;s-h?\"");
    cout << s3 << endl;
    
    // Ch11-07
    string s4 = replace_quote(" - don't use the as-if rule.");
    cout << s4 << endl;
    
    string s5 = replace_quote(" - can't use the as-if rule.");
    cout << s5 << endl;
    
    string s6 = to_lower("Can'T uSe thE as-If rUle.");
    cout << s6 << endl;
    
    return 0;
}
