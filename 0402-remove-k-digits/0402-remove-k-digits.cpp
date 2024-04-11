class Solution {
public:
    string removeKdigits(string num, int k) {
        string smallest="";
        stack<char> stk;
        for(char dig:num){
            while(!stk.empty() && stk.top()>dig && k>0){
                stk.pop();
                k--;
            }
            stk.push(dig);
        }
        for(int i=0;i<k;i++) stk.pop();
        while(!stk.empty()){
            smallest+=stk.top();
            stk.pop();
        }
        while(smallest!="" && smallest.back()=='0') smallest.pop_back();
        reverse(smallest.begin(),smallest.end());
        return smallest==""?"0":smallest;
    }
};