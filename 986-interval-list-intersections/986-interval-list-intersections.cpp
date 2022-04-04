class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        int i = 0;
        int j = 0;
        int size1 = firstList.size();
        int size2 = secondList.size();
        int start = 0;
        int end = 1;
        
        while(i < size1 and j < size2)
        {
            if(firstList[i][start] <= secondList[j][end] and firstList[i][end] >= secondList[j][start])
            {
                int new_start = max(firstList[i][start],secondList[j][start]);
                int new_end = min(firstList[i][end],secondList[j][end]);
                ans.push_back({new_start,new_end});
            }
            if(firstList[i][end] < secondList[j][end]){
                    ++i;
                }
                else
                    ++j;
                
        }
        return ans;
        
    }
};