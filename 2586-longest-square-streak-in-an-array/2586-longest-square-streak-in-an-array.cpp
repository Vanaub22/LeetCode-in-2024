#define lli long long int
class Solution {
public:
    int longestSquareStreak(vector<int> nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        unordered_set<lli> s(nums.begin(),nums.end());
        for(lli i:nums) {
            int streak=0;
            while(s.find(i)!=s.end()) {
                s.erase(i);
                i*=i,streak++;
            }
            ans=max(ans,streak);
        }
        return ans>=2?ans:-1;
    }
};