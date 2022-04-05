class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int index = 0;
        int count = 0;
        priority_queue<int> maxh;
        int max_reach = startFuel;
    
        while(max_reach < target)
        {
            
            while(index < stations.size() and stations[index][0] <= max_reach)
            {
                maxh.push(stations[index][1]);
                ++index;
            }
            if(maxh.empty()) return -1;
            
            int max_fuel = maxh.top();
            maxh.pop();
            ++count;
            max_reach += max_fuel;
        }
        return count;
    }
};