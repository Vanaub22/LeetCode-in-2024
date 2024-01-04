class Solution {
public:
    // Greedy Approach
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        int step=0;
        for(auto it:freq) {
            // Try to reduce by 3 as far as possible
            if(it.second%3==0) step+=it.second/3;
            else {
                int cnt=it.second;
                while(cnt>0) {
                    if(cnt>=3 && ((cnt-3)%3==0 || (cnt-3)%2==0)) cnt-=3;
                    else if(cnt>=2 && ((cnt-2)%3==0 || (cnt-2)%2==0)) cnt-=2;
                    else return -1; // Lesser than 2 remaining => cannot be reduced further
                    step++;
                }
            }
        }
        return step;
    }
};