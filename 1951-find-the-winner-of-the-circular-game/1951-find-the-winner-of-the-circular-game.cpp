class Solution {
public:
    // Simple Recursive Solution to the Josephus Problem
    int findTheWinner(int n, int k) {
        return n==1?1:(findTheWinner(n-1,k)+k-1)%n+1;
    }
};