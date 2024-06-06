class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k) return false;
        map<int,int> mp;
        for(int i:nums) mp[i]++;
        // for(auto it:mp) cout<<it.first<<"->"<<it.second<<" | ";
        // cout<<endl;
        while(!mp.empty()) {
            int start=(*mp.begin()).first;
            // cout<<"start: "<<start<<endl;
            for(int i=start;i<start+k;i++) {
                if(mp.find(i)==mp.end()) return false;
                mp[i]--;
                if(mp[i]==0) {
                    if(i!=(*mp.begin()).first) return false;
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};