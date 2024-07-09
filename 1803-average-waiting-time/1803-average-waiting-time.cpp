class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& orders) {
        int startTime=orders[0][0];
        long long totalWaiting=0;
        for(auto& order:orders){
            int arrival=order[0],timeTaken=order[1];
            startTime=max(arrival,startTime);
            totalWaiting+=timeTaken+startTime-arrival;
            startTime+=timeTaken;
        }
        return totalWaiting/(double)orders.size();
    }
};