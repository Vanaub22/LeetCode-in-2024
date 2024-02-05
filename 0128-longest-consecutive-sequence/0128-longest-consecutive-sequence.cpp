class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return false;
        int ans=1;
        unordered_set<int> s;
        for(int i:nums) s.insert(i);
        for(int i:nums) {
            if(s.find(i-1)==s.end()) {
                int x=i,cnt=0;
                while(s.find(x)!=s.end()) {
                    x++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};