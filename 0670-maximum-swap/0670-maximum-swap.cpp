class Solution {
public:
    int maximumSwap(int num) {
        string best=to_string(num),curr=best;
        sort(best.rbegin(),best.rend());
        int n=curr.size();
        for(int i=0;i<n;i++) {
            if(best[i]!=curr[i]) {
                int j=n-1;
                for(;j>=0;j--) if(curr[j]==best[i]) break;
                swap(curr[j],curr[i]);
                break;
            }
        }
        return stoi(curr);
    }
};