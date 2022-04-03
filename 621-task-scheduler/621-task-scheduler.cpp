class Solution {
public:
    // same approach for Rearrange string k distance apart
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(auto task : tasks){
            mpp[task]++;
        }
        
        priority_queue<int> maxh;
        for(auto i : mpp){
            maxh.push(i.second);
        }
        
        queue<pair<int,int>> q;
        int time = 0;
        while(maxh.size() > 0 or q.size() > 0){
            time += 1;
            if(maxh.size() > 0){
                int count = maxh.top();
                maxh.pop();
                --count;
                if(count != 0) {
                    q.push({count,time+n});   
                }
            }
          
            if(q.size() > 0 and q.front().second == time){
                    auto temp = q.front();
                    maxh.push(temp.first);
                    q.pop();
                }
            }
        return time;
        }
        
};