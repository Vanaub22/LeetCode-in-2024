class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long cnt[1024]={0},res=0;
        cnt[0]=1;
        int curr=0;
        for(char c:word) {
            curr^=1<<(c-'a');
            res+=cnt[curr];
            for(int i=0;i<10;i++) res+=cnt[curr^(1<<i)];
            cnt[curr]++;
        }
        return res;
    }
};