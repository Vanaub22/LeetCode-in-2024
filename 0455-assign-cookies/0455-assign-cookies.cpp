class Solution {
public:
    // Greedy Approach using Two Pointers
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m=g.size(),n=s.size(),i=0,j=0,content=0;
        while(i<m && j<n) {
            if(g[i]<=s[j]) {
                content++;
                i++;
            }
            j++;
        }
        return content;
    }
};