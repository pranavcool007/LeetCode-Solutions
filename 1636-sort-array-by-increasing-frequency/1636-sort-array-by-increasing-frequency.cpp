class Solution {
public:
    static bool compare(vector<int>a,vector<int>b){
        if(a[0]<b[0]) return true;
        if(a[0] == b[0]) return a[1]>b[1];
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<vector<int>> temp;
        unordered_map<int,int> mpp;
        vector<int>ans;
        for(auto num: nums){
            mpp[num]++;
        }
        
        for(auto i:mpp){
            temp.push_back({i.second,i.first});
        }
        sort(temp.begin(),temp.end(),compare);
        for(auto i : temp){
            int num = i[1];
            int freq = i[0];
            while(freq){
                ans.push_back(num);
                --freq;
            }
        }
        return ans;
    }
};