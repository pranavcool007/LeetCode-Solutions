class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // range of eating speed(banana per hr)
        int left = 1;
        int right = *max_element(piles.begin(),piles.end()); 
        
        // min_eating_speed
        int ans = right;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int time = 0;
            
            for(int i: piles){
                time += ceil(1.0*i/mid);
            }
            if(time <= h){
                ans = min(ans,mid);
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};