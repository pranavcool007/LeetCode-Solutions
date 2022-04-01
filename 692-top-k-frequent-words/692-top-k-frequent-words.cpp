class compare{
    public:
        bool operator() (const pair<int,string> a,const pair<int,string> b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        typedef pair<int,string> pr;
        priority_queue<pr,vector<pr>,compare> minh;
        unordered_map<string,int> mpp;
        vector<string> ans;
        for(auto word : words){
            ++mpp[word];
        }
        for(auto i : mpp){
            minh.push({i.second,i.first});
            
            if(minh.size() > k){
                minh.pop();
            }
        }
        while(minh.size() > 0){
            string word = minh.top().second;
            ans.push_back(word);
            minh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};