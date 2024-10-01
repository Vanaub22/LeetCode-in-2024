class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()%2) return false;
        unordered_map<int,int> remf;
        for(int i:arr) remf[((i%k)+k)%k]++;
        if(remf[0]%2) return false;
        for(int i=1;i<k;i++) if(remf[i]!=remf[k-i]) return false;
        return true;
    }
};