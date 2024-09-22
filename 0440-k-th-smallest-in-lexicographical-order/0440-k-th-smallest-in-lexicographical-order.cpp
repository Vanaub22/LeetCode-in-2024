// Very typical approach for optimization
// T.C. O(logn) S.C. O(1)
class Solution {
public:
    int findKthNumber(int n, int k) {
        // To find the count of numbers starting with the currently passed prefix
        function<int(int)> countPref=[&n](int x)->int {
            long curr=x,succ=x+1;
            int cnt=0;
            while(curr<=n) {
                cnt+=min((long)n+1,succ)-curr;
                curr*=10,succ*=10;
            }
            return cnt;
        };
        int x=1;
        k--;
        while(k) {
            int cnt=countPref(x);
            if(cnt<=k) x++,k-=cnt; // Moving to the next prefix
            else x*=10,k--; // Moving deeper
        }
        return x;
    }

};