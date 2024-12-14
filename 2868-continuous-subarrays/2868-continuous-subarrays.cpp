#define ll long long
class Solution {
public:
    ll continuousSubarrays(vector<int>& nums) {
        ll cnt=0;
        map<int,int> f;
        int left=0,right=0,n=nums.size();
        while(right<n) {
            f[nums[right]]++;
            int max_entry=f.rbegin()->first,min_entry=f.begin()->first;
            while(max_entry-min_entry>2) {
                f[nums[left]]--;
                if(!f[nums[left]]) f.erase(nums[left]);
                left++;
                max_entry=f.rbegin()->first,min_entry=f.begin()->first;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
};