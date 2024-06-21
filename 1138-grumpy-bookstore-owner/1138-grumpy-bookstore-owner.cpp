class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(),prev=0,maxSatisfaction,satisfaction=0;
        // Finding out the no. of customers who will be satisfied without using the power
        for(int i=0;i<n;i++) if(!grumpy[i]) satisfaction+=customers[i];
        maxSatisfaction=satisfaction;
        // Contribution to satisfaction if we use the power at t=0
        for(int i=0;i<minutes;i++) satisfaction+=customers[i]*grumpy[i];
        maxSatisfaction=max(maxSatisfaction,satisfaction);
        for(int i=minutes;i<n;i++) {
            satisfaction+=customers[i]*grumpy[i]-customers[prev]*grumpy[prev];
            prev++;
            maxSatisfaction=max(maxSatisfaction,satisfaction);
        }
        return maxSatisfaction;
    }
};