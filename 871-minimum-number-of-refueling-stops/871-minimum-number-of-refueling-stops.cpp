class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int index = 0;
        int count = 0;
        priority_queue<int> maxh;
        int max_reach = startFuel;
        
/* if target is reached then no need to take one more station to fuel the car, tar = 1
   max_reach = 1 and stations (any) then why to refuel. */
        while(max_reach < target)   
        {
         
/* this saves all the fuel stations till the max_reach point and to calculate the least 
   no of fuel stations we need max fuel from a station(greedy), so max heap is used to 
   find which station till the point gives max fuel */
            
            while(index < stations.size() and stations[index][0] <= max_reach)
            {
                maxh.push(stations[index][1]);
                ++index;
            }
            
/* if no fuel stations till the max_reach point it means we cannot reach the target so
   return -1  */
            
            if(maxh.empty()) return -1;
            
            int max_fuel = maxh.top();
            maxh.pop();
            ++count;
            max_reach += max_fuel;
        }
        return count;
    }
};