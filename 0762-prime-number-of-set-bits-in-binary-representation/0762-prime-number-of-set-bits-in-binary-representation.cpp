class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++) if(isPrime(countSetBits(i))) cnt++;
        return cnt;
    }
    int countSetBits(int x) {
        int cnt=0;
        while(x>0) {
            cnt+=x&1;
            x>>=1;
        }
        return cnt;
    }
    bool isPrime(int x) {
        if(x<=1) return false;
        int f=0;
        for(int i=2;i<=x/2;i++) if(x%i==0) f++;
        return !f;
    }
};