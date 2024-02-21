class Solution {
public:
    int twoCitySchedCost(auto& costs) {
        int minCost=0;
        // Calculating refunds assuming we send all 2n people to city B instead of A
        vector<int> refunds;
        for(auto& cost:costs) {
            refunds.emplace_back(cost[0]-cost[1]);
            minCost+=cost[0]; // Initial cost of sending all 2n people to A
        }
        // To minimize costs we have to ensure maximum refunds
        sort(refunds.rbegin(),refunds.rend());
        // Updating the final cost by deducting refunds of sending n people to B from the initial cost
        for(int i=0;i<costs.size()/2;i++) minCost-=refunds[i];
        return minCost;
    }
};