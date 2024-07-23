class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int i:nums) f[i]++;
        sort(nums.begin(),nums.end(),[&](int& a, int& b) {
            return f[a]==f[b]?a>b:f[a]<f[b];
        });
        return nums;
    }
};