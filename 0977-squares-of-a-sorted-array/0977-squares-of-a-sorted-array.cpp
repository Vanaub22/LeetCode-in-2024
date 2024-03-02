class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int& a, int& b) {
            return abs(a)<abs(b);
        });
        for(int& i:nums) i*=i;
        return nums;
    }
};