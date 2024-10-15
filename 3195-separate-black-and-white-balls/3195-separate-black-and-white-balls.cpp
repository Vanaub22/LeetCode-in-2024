class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0,black_cnt=0;
        for(char c:s) {
            if(c=='0') swaps+=black_cnt;
            else black_cnt++;
        }
        return swaps;
    }
};