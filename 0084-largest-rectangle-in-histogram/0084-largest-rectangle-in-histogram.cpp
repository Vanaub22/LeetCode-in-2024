// Monotonic Stack Solution (Next Greater Element Logic) in O(N) T.C.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),maxArea=-1;
        vector<int> leftWall(n),rightWall(n);
        stack<int> stk;
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
};