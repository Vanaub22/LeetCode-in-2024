class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        function<int(int,int)> solve=[&n,&solve,&memo](int value, int copied)->int {
            if(value==n) return 0;
            else if(value>n) return 1e5;
            else if(memo[value][copied]!=-1) return memo[value][copied];
            else return memo[value][copied]=min(1+solve(value+copied,copied),2+solve(value+value,value));
        };
        return 1+solve(1,1); // Copying the first 'A' is compulsory
    }
};