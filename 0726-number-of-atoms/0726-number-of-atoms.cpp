class Solution {
public:
    string countOfAtoms(string formula) {
        int i=0;
        function<map<string,int>()> solve=[&formula,&solve,&i]()->map<string,int>{
            int n=formula.size(),start,val;
            map<string,int> f;
            while(i<n) {
                if(formula[i]=='(') {
                    i++;
                    map<string,int> nf=solve();
                    start=i,val=1;
                    while(i<n && isdigit(formula[i])) i++;
                    if(i>start) val=stoi(formula.substr(start,i-start));
                    for(auto& [ele,cnt]:nf) f[ele]+=(cnt*val);
                }
                else if(formula[i]==')') {
                    i++;
                    break;
                }
                else {
                    start=i,val=1;
                    i++;
                    while(i<n && islower(formula[i])) i++;
                    string ele=formula.substr(start,i-start);
                    start=i;
                    while(i<n && isdigit(formula[i])) i++;
                    if(i>start) val=stoi(formula.substr(start,i-start));
                    f[ele]+=val;
                }
            }
            return f;
        };
        string ans="";
        for(auto& [ele,cnt]:solve()) ans+=ele+(cnt==1?"":to_string(cnt));
        return ans;
    }
};