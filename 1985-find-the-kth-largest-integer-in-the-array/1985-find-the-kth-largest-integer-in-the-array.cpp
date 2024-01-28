class Solution {
public:
    static bool comp(string& a, string& b) {
        return a.length()!=b.length()?a.length()>b.length():a>b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[k-1];
    }
};