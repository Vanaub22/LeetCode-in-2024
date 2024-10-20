class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for(char c:expression) {
            if(c=='(' || c==',') continue;
            else if(c=='t' || c=='f' || c=='&' || c=='!' || c=='|') stk.push(c);
            else {
                bool has_true=false,has_false=false;
                while(stk.top()!='!' && stk.top()!='|' && stk.top()!='&') {
                    char v=stk.top();
                    stk.pop();
                    if(has_true && has_false) continue;
                    if(v=='t') has_true=v=='t';
                    if(v=='f') has_false=v=='f';
                }
                char sym=stk.top();
                stk.pop();
                if(sym=='!') stk.push(has_true?'f':'t');
                else if(sym=='|') stk.push(has_true?'t':'f');
                else stk.push(has_false?'f':'t');
            }
        }
        return stk.top()=='t';
    }
};