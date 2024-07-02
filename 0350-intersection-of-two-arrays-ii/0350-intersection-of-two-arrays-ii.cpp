class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> f1,f2;
        for(int i:nums1) f1[i]++;
        for(int i:nums2) f2[i]++;
        for(auto& [x,f]:f1) for(int i=0;i<min(f,f2[x]);i++) ans.push_back(x);
        return ans;
    }
};