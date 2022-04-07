class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());
            int n = stones.size();
            int x = stones[n-2];
            int y = stones[n-1];
            stones.pop_back();
            stones.pop_back();
            
            if(x == y){
                continue;
            }
            else{
                int z = abs(y-x);
                stones.push_back(z);
                
            }
        }
        if(stones.size() == 0){
            return 0;
        }
        else{
            return stones.back();
        }
    }
};