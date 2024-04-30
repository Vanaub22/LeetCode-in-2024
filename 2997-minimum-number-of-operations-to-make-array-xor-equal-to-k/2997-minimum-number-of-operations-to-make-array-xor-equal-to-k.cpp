class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int arr_xor=0;
        for(int i:nums) arr_xor=arr_xor^i;
        arr_xor=arr_xor^k;
        int cnt=0;
        // Counting set bits in array xor result
        while(arr_xor) {
            cnt+=arr_xor&1;
            arr_xor>>=1;
        }
        return cnt;
    }
};