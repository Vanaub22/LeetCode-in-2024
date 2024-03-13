class Solution {
public:
    int pivotInteger(int n) {
        int psum=0,ssum=n*(n+1)/2;
        for(int i=1;i<=n;i++) {
            psum+=i;
            ssum-=(i-1);
            if(psum==ssum) return i;
        }
        return -1;
    }
};