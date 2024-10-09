class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char> stk;
       for(char c:s) if(stk.empty() || !(stk.top()=='(' && c==')')) stk.push(c);
       else if(stk.top()=='(' && c==')') stk.pop();
       return stk.size();
    }
};