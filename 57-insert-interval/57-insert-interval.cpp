class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int interval = 0;
        int start = 0;
        int end = 1;
        while(interval < intervals.size() and intervals[interval][end] < newInterval[start]){
            ans.push_back(intervals[interval]);
            ++interval;
        }
        
        while(interval < intervals.size() and intervals[interval][start] <= newInterval[end]){
            newInterval[start] = min(newInterval[start],intervals[interval][start]);
            newInterval[end] = max(newInterval[end],intervals[interval][end]);
            ++interval;
        }
        ans.push_back(newInterval);
        
        while(interval < intervals.size() and intervals[interval][start] > newInterval[end]){
            ans.push_back(intervals[interval]);
            ++interval;
        }
        return ans;
    }
};