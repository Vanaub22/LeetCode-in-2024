class Solution {
private:
    bool isSubfolder(string& f1, string& f2) {
        return f1.size()<=f2.size() && f2.substr(0,f1.size())==f1 && f2[f1.size()]=='/';
    }
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        vector<string> ans;
        sort(folders.begin(),folders.end());
        string last_added="";
        for(auto& folder:folders) {
            if(last_added.empty() || !isSubfolder(last_added,folder)) {
                last_added=folder;
                ans.emplace_back(folder);
            }
        }
        return ans;
    }
};