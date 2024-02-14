class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg,res;
        for(int i:nums) if(i>0) pos.push_back(i);
        else neg.push_back(i);
        int i=0;
        while(res.size()!=nums.size()){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
            i++;
        }
        return res;
    }
};