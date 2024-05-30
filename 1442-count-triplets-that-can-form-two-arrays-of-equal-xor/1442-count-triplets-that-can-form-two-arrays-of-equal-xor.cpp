class Solution {
public:
    // Subarray of length >= 2 such that xor of 1st half equals xor of 2nd half
    // Therefore, we are basically looking for subarray with cumulative xor = 0
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++) {
            int tmp=0;
            for(int j=i;j<n;j++) {
                tmp^=arr[j];
                if(tmp==0) ans+=j-i;
            }
        }
        return ans;
    }
};