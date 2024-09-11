class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal,flips=0;
        while(x) {
            flips+=x&1;
            x>>=1;
        }
        return flips;
    }
};