class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res=0;
        stack<int> stk;
        for(string& operation:operations) {
            if(operation=="+") {
                int a=stk.top(),b;
                stk.pop();
                b=stk.top();
                stk.pop();
                stk.push(b);
                stk.push(a);
                stk.push(a+b);
            }
            else if(operation=="D") {
                int x=stk.top();
                stk.push(2*x);
            }
            else if(operation=="C") stk.pop();
            else stk.push(stoi(operation));
        }
        while(!stk.empty()) {
            res+=stk.top();
            stk.pop();
        }
        return res;
    }
};