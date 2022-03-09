class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {  // pat = p, s = txt
        unordered_map<char,int> mp;
	    for(char ch : pat){
	        ++mp[ch];
	    }
        
	    int K = pat.length();
	    int count = mp.size();
	    vector<int> ans;            // use vector instead of a int
	    int i=0,j=0;
	    while(j<txt.length()){
	        if(mp.find(txt[j]) != mp.end()){
	            --mp[txt[j]];
	            if(mp[txt[j]] == 0){
	                --count;
	            }
	        }
	        if(j-i+1 < K){
	            ++j;
	        }
	        else if (j-i+1 == K){
	            if(count == 0){
	                ans.push_back(i);    // use i instead of ++ans in count occurences
	            }
	            if(mp.find(txt[i]) != mp.end()){
	                ++mp[txt[i]];
	                if(mp[txt[i]] == 1){
	                    ++count;
	                }
	            }
	            ++i;
	            ++j;
	        }
	    }
	    return ans;
	}
};