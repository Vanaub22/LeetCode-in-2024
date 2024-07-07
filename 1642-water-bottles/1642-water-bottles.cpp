class Solution {
public:
    int numWaterBottles(int n, int e) {
        int drink=0,full=n,empty=0;
        while(full) {
            drink+=full;
            empty+=full;
            full=empty/e;
            empty%=e;
        }
        return drink;
    }
};