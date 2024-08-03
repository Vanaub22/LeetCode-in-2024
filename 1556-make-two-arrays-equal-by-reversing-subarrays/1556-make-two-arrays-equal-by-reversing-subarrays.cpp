class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int f[1001]={0};
        for(int i:target) f[i]++;
        for(int i:arr) f[i]--;
        for(int i:f) if(i) return false;
        return true;
    }
};