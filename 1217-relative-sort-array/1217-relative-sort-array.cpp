class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> ump;
        for(int i=0;i<arr2.size();i++) ump[arr2[i]]=i;
        sort(arr1.begin(),arr1.end(),[&](int& a, int& b) {
            bool fa=ump.find(a)==ump.end(),fb=ump.find(b)==ump.end();
            if(fa && fb) return a<b;
            else if(fa || fb) return fb;
            else return ump[a]<ump[b];
        });
        return arr1;
    }
};