class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        vector<int> ans;
        
        for(int i=0; i<arr.size(); ++i){
            int diff = abs(arr[i] - x);
            maxh.push({diff,arr[i]});
            
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        while(maxh.size() > 0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};