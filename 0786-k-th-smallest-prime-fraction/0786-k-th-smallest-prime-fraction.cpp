class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,pair<int,int>>> f;
        int n=arr.size();
        for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) f.push_back(make_pair((float)arr[i]/arr[j],make_pair(arr[i],arr[j])));
        sort(f.begin(),f.end());
        return {f[k-1].second.first,f[k-1].second.second};
    }
};