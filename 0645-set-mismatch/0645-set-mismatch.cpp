class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        int missing,repeated,n=nums.size();
        for(int i:nums) if(s.find(i)!=s.end()) repeated=i;
        else s.insert(i);
        for(int i=1;i<=n;i++) if(s.find(i)==s.end()) {
            missing=i;
            break;
        }
        return {repeated,missing};
    }
};