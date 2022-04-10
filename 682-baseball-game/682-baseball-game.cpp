class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> records;
        int ans = 0;
        
        for(string i : ops){
            if(i == "C"){
                records.pop_back();
            }
            else if(i == "D"){
                int temp = records.back() * 2;
                records.push_back(temp);
            }
            else if(i == "+"){
                int n = records.size();
                int r1 = records[n-1];
                int r2 = records[n-2];
                records.push_back(r1 + r2);
            }
            else{
                records.push_back(stoi(i));
            }
        }
        for(auto record : records){
            ans += record;
        }
        return ans;
    }
};