class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        vector<int> leftProd(n),rightProd(n);
        leftProd[0]=rightProd[n-1]=1;
        for(int i=1;i<n;i++) leftProd[i]=leftProd[i-1]*arr[i-1];
        for(int i=n-2;i>-1;i--) rightProd[i]=rightProd[i+1]*arr[i+1];
        for(int i=0;i<n;i++) arr[i]=leftProd[i]*rightProd[i];
        return arr;
    }
};