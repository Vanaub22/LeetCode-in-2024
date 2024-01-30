class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for(auto& token:tokens) {
            if(isOperator(token)) {
                int b=operands.top();
                operands.pop();
                int a=operands.top();
                operands.pop();
                operands.push(performOperation(a,b,token));
            }
            else operands.push(stoi(token));
        }
        return operands.top();
    }
    int performOperation(int x, int y, string sign) {
        if(sign=="+") return x+y;
        else if(sign=="-") return x-y;
        else if(sign=="*") return x*y;
        else return x/y;
    }
    bool isOperator(string s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
};