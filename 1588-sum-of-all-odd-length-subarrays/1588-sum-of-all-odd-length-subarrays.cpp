class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),res=accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<n-1;i++) {
            int ss=arr[i];
            for(int j=i+1;j<n;j++) {
                int d=j-i+1;
                ss+=arr[j];
                if(d%2) res+=ss;
            }
        }
        return res;
    }
};