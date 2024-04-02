class Solution {
public:
    bool present(auto& umap,int value){
        for(auto it:umap) if(it.second==value) return true;
        return false;
    }
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> umap;
        for(int i=0;i<s.length();i++) {
            if(umap[s[i]]==0){
                if(!present(umap,t[i])) umap[s[i]]=t[i];
                else return false;
            }
            if(umap[s[i]]!=0 && umap[s[i]]!=t[i])
            return false;
        }
        return true;
    }
};