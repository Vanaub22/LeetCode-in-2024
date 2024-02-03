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
                reqd[i+1]++; // Creating a need for the next element of subsequence
            }
            else {
                if(!freq[i]) continue; // All occurrences have been chosen for some subsequence
                if(freq[i] && freq[i+1] && freq[i+2]) {
                    // Creating a new subsequence having a minimum of 3 elements
                    freq[i]--;
                    freq[i+1]--;
                    freq[i+2]--;
                    reqd[i+3]++; // Creating a need for the next element for this subsequence
                }
                else return false;
            }
        }
        return true;
    }
};