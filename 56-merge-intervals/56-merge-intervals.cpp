class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),comp);
        
        ans.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); ++i){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start <= ans.back()[1]){
                ans.back()[1] = max(end,ans.back()[1]);
            }
            else{
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};