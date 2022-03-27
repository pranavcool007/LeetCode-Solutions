class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int> pr;
        priority_queue<pr,vector<pr>,greater<pr>> minh;
        unordered_map<int,int> mpp;
        vector<int> ans;
        
        for(auto num: nums){
            ++mpp[num];
        }
        
        for(auto i: mpp){
            minh.push({i.second,i.first});
            
            if(minh.size() > k){
                minh.pop();
            }
        }
        
        while(minh.size() > 0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    } 
};