class Solution {
public:
    char findKthBit(int n, int k) {
        return findSn("0",n)[k-1];
    }
    string findSn(string sprev, int n) {
        if(n==0) return sprev;
        string i=sprev;
        for(char& c:i) c+=c-'0'?-1:1;
        reverse(i.begin(),i.end());
        return findSn(sprev+"1"+i,n-1);
    }
};