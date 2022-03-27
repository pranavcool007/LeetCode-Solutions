class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        vector<vector<int>> ans;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            maxh.push({dist,{x,y}});
            
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        while(maxh.size() >0){
            auto temp = maxh.top().second;
            ans.push_back({temp.first,temp.second});
            maxh.pop();
        }
        return ans;
    }
};