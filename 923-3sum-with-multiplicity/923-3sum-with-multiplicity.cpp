class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long ans = 0;
        unordered_map<int,long> mpp;
        for(auto i : arr){
            mpp[i]++;
        }
        
        for(auto i1 : mpp)
        {
            for(auto i2 : mpp)
            {
                int i = i1.first;
                int j = i2.first;
                int k = target -i-j;
                if(mpp.find(k) != mpp.end())
                {
                    if(i==j and j==k){
                        long n = mpp[i];
                        ans += (n*(n-1)*(n-2))/6;
                    }
                    else if(i==j and j!=k){
                        int n1 = mpp[i];
                        int n2 = mpp[k];
                        ans += n2*(n1)*(n1-1)/2;
                    }
                    else if(i<j and j<k){
                        int n1 = mpp[i];
                        int n2 = mpp[j];
                        int n3 = mpp[k];
                        ans += n1*n2*n3;
                    }
                }
            }
        }
        return ans % 1000000007;
    }
};