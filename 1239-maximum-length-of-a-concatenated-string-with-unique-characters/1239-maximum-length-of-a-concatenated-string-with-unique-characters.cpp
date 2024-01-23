class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res=0;
        dfs(0,"",arr,arr.size(),res);
        return res;
    }
    // Helper fn. to perform DFS and explore all possible subsequences
    void dfs(int idx, string curr, vector<string>& arr, int n, int& res) {
        if(!hasUniqueChars(curr)) return;
        res=max(res,(int)curr.size());
        for(int i=idx;i<n;i++) dfs(i+1,curr+arr[i],arr,n,res);
    }
    // To check if the characters in the current string are unique or not
    bool hasUniqueChars(string& s) {
        set<char> st;
        for(char c:s) if(st.find(c)!=st.end()) return false;
        else st.insert(c);
        return true;
    }
};