class Solution {
public:
    int maxScore(vector<string>& words, unordered_map<char,int>& freq, vector<int>& score,int index){
        
        if(index == words.size()) return 0;
        // word is not included
        int score_not_inc = 0 + maxScore(words,freq,score,index+1);
        
        // word is included
        int score_word = 0;
        bool flag = true;
        for(auto ch : words[index]){
            if(freq[ch] == 0){
                flag = false;
            }
            freq[ch]--;
            score_word += score[ch-'a'];
            
        }
        int score_inc = 0;
        if(flag){
            score_inc = score_word + maxScore(words,freq,score,index+1);
        }
        for(auto ch : words[index]){
            freq[ch]++;
        }
        return max(score_inc,score_not_inc);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int index = 0;
        unordered_map<char,int> mpp;
        for(auto i : letters){
            mpp[i]++;
        }
        int ans = maxScore(words,mpp,score,index);
        return ans;
    }
};