class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> f,af;
        for(int i:nums1) f[i]++;
        for(int i:nums2) if(f[i] && !af[i]) {
            ans.push_back(i);
            af[i]++;
        }
        return ans;
    }
};