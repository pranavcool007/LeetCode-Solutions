class Solution {
public:
    bool feasible(int days,vector<int>& bloomDay,int m,int k){
        int n = bloomDay.size();
        int flowers = 0;
        int boq = 0;
        for(int i=0; i<n; ++i){
            if(days < bloomDay[i]){
                flowers = 0;
            }else{
                flowers +=1;
                if(flowers == k){
                    boq += 1;
                    flowers = 0;
                }
            }
        }
        return boq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < k*m) return -1;
        int start = 1;
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        while(start <= end){
            int mid = start + (end-start)/2;
            if(feasible(mid,bloomDay,m,k)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
    
};