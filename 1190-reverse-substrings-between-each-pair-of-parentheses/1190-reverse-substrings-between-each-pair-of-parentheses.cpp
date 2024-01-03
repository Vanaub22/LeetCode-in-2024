class Solution {
public:
    string reverseParentheses(string s) {
        string res="";
        stack<string> stk;
        for(char c:s) {
            stk.push(string(1,c));
            if(stk.top()==")") {
                stk.pop(); // Popping out the closing brace
                string toPush="";
                while(stk.top()!="(") {
                    toPush+=stk.top();
                    stk.pop();
                }
                reverse(toPush.begin(),toPush.end());
                stk.pop(); // Popping out the opening brace
                stk.push(toPush); // Pushing in the enclosed string
            }
        }
        while(!stk.empty()) {
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};