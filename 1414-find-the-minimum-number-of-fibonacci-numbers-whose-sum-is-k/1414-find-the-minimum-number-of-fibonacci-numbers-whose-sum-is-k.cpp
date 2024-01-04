class Solution {
public:
    // Greedy Approach
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo={0,1};
        genFibo(fibo,k);
        int n=fibo.size(),sum=0,cnt=0;
        // Logic to find minimum number of Fibonacci numbers needed to generate the sum
        for(int i=n-1;i>=0;i--) {
            // Greedily choosing larger Fibonacci numbers first
            if(sum+fibo[i]<=k) {
                sum+=fibo[i];
                cnt++;
                if(sum==k) break;
            }
        }
        return cnt;
    }
    // Helper function to generate all Fibonacci numbers to k
    void genFibo(vector<int>& fibo, int k) {
        int x=0;
        while(true) {
            int n=fibo.size();
            x=fibo[n-1]+fibo[n-2];
            if(x>k) break;
            fibo.emplace_back(x);
        }
    }
};