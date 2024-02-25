class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int s=0;
        vector<bool> answer;
        for(int i:nums) {
            s=(s*2+i)%5;
            answer.push_back(!s);
        }
        return answer;
    }
};