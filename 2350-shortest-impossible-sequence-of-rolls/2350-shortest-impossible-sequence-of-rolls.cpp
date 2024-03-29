class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int hmap[k+1],cnt=0,slen=1;
        bzero(hmap,sizeof(hmap));
        for(int roll:rolls) {
            hmap[roll]++;
            if(hmap[roll]==1) cnt++;
            if(cnt==k) {
                slen++;
                bzero(hmap,sizeof(hmap));
                cnt=0;
            }
        }
        return slen;
    }
};