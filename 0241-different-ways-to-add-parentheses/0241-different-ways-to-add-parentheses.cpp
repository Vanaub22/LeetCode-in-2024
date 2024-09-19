class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n=expression.length();
        for(int i=0;i<n;i++) {
            char c=expression[i];
            if(c=='+' || c=='-' || c=='*') {
                vector<int> lhs=diffWaysToCompute(expression.substr(0,i)),rhs=diffWaysToCompute(expression.substr(i+1));
                for(int i:lhs) {
                    for(int j:rhs) {
                        if(c=='+') ans.emplace_back(i+j);
                        if(c=='-') ans.emplace_back(i-j);
                        if(c=='*') ans.emplace_back(i*j);
                    }
                }
            }
        }
        if(!ans.size()) ans.emplace_back(stoi(expression));
        return ans;
    }
};