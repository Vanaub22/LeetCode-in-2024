// Defining a class to create separate Replace objects
class Replace {
public:
    string src,target;
    int idx,n;
    Replace(string src, string target, int idx, int n) {
        this->n=n,this->idx=idx,this->src=src,this->target=target;
    }
};
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=indices.size();
        vector<Replace> ops;
        for(int i=0;i<n;i++) ops.emplace_back(sources[i],targets[i],indices[i],sources[i].size());
        sort(ops.begin(),ops.end(),[&](auto& a, auto& b) {
            return a.idx>b.idx;
        });
        string res=s;
        for(auto& op:ops){
            if(s.substr(op.idx,op.n)==op.src)
            res=res.substr(0,op.idx)+op.target+res.substr(op.idx+op.n);
        }
        return res;
    }
};