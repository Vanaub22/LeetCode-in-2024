// Solving using Largest Histogram Area logic
class Solution {
private:
    int findLargestHistogramArea(auto& heights) {
        int n=heights.size(),maxArea=0;
        stack<int> stk;
        vector<int> leftWall(n),rightWall(n);
        for(int i=0;i<n;i++) {
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            if(stk.empty()) leftWall[i]=0;
            else leftWall[i]=stk.top()+1;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=n-1;i>=0;i--) {
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            if(stk.empty()) rightWall[i]=n-1;
            else rightWall[i]=stk.top()-1;
            stk.push(i);
            maxArea=max(maxArea,(rightWall[i]-leftWall[i]+1)*heights[i]);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<int> r(n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]-'0') r[j]++;
                else r[j]=0;
            }
            ans=max(ans,findLargestHistogramArea(r));
        }
        return ans;
    }
};