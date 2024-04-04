class Solution {
public:
    int maxDepth(string s) {
        int depth=-1;
        stack<int> st;
        for(char c:s) {
            if(c=='(') st.push(c);
            else if(c==')') st.pop();
            depth=max(depth,(int)st.size());
        }
        return depth;
    }
};