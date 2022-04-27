class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int val;
        while(true){
            val = 0;
            while(n){
                int i = n % 10;
                val += i*i;
                n /= 10;
            }
            if(val == 1) return true;
            if(s.find(val) != s.end()){
                return false;
            }
            s.insert(val);
            n = val;
        }
        
    }
};