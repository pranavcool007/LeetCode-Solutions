class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> map2;
        for(char i: t){
            ++map2[i];
        }
        
        int i= -1;
        int j= -1;
        int mct= t.length();       // match count of string t
        int cmct= 0;               // current match count of string s
        string ans = "";
        unordered_map<char,int> map1;
        
        
        
        while(true) {  
        bool flag1 = false;         //variables to terminate loop
        bool flag2 = false;
            
        //acquire
        while(i < (int)s.length()-1 and cmct < mct){
            i++;
            ++map1[s[i]];
            
            if(map1[s[i]] <= map2[s[i]]){
                ++cmct;
            }
            flag1 = true;                 // loop entered
        }
        //collect ans and release 
        while(j < i and cmct == mct){
            string pans = s.substr(j+1,i-j);
            if(ans.length() == 0 or pans.length()<ans.length()){
                ans=pans;
            }
            
            j++;
            if(map1[s[j]] == 1){
                map1.erase(s[j]);
            }
            else{
              --map1[s[j]];  
            }
            
            if(map1[s[j]] < map2[s[j]]){
                --cmct;
            }
            
            flag2 = true;          // loop entered
        }
        if(flag1 == false and flag2 == false) break;
            
        }
        
        
        return ans;
        
    }
};