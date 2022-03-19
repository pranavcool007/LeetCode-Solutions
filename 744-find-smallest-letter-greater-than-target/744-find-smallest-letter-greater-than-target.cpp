class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size()-1;
        int ans_idx = 0;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(letters[mid] == target){
                start = mid+1;
            }
            else if(letters[mid] < target){
                start = mid+1;
            }
            else{
                ans_idx = mid;
                end = mid-1;
            }
        }
        return letters[ans_idx];
    }
};