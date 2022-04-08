#include <cstring>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> char_to_word;
        unordered_map<string,char> word_to_char;
        vector<string> words;
        
        string word = "";
        for(char i: s){
            if(i == ' '){
                words.push_back(word);
                word = "";
            }
            else{
                word += i;
            }
        }
        words.push_back(word);
        
        // for(auto i : words){
        //     cout<<i<<" ";
        // }
        
        // edge case when length of either of word or pattern is not same
        
        int n = pattern.length();
        int m = words.size();
        if(n != m) return false;
        
        for(int i = 0; i<pattern.length(); ++i){
            string word = words[i];
            char pat = pattern[i];
            if(char_to_word.find(pat) != char_to_word.end() and char_to_word[pat] != word){
                return false;
            }
            if(word_to_char.find(word) != word_to_char.end() and word_to_char[word] != pat){
                return false;
            }
            char_to_word[pat] = word;
            word_to_char[word] = pat;
        }
        return true;
    }
};