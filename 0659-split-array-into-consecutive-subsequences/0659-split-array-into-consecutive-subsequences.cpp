class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq,reqd;
        for(int i:nums) freq[i]++;
        for(int i:nums) {
            if(reqd[i] && freq[i]) {
                reqd[i]--;
                freq[i]--;
                reqd[i+1]++;
            }
            else {
                if(!freq[i]) continue;
                if(freq[i] && freq[i+1] && freq[i+2]) {
                    freq[i]--;
                    freq[i+1]--;
                    freq[i+2]--;
                    reqd[i+3]++;
                }
                else return false;
            }
        }
        return true;
    }
};