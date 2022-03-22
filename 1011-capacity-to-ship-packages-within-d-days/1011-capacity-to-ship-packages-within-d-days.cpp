class Solution {
public:
    bool feasible(int capacity,vector<int> &weights,int Days){
        int total = 0;
        int days = 1;
        for(auto weight: weights){
            total += weight;
            if(total > capacity){
                total = weight;
                days += 1;
                if(days > Days){
                    return false;
                }
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        while(start <= end){
            int mid = start + (end-start)/2;
            if(feasible(mid,weights,days)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
    
};