class Solution {
public:
    bool feasible(int speed,vector<int> &piles,int Hours){
        int hours = 0;
        for(int pile:piles){
            hours += ceil((1.0*pile)/speed);
        }
        if(hours > Hours){
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        while(start <= end){
            int mid = start + (end-start)/2;
            if(feasible(mid,piles,h)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};