class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> mapped_value;
        auto generate_value=[&mapping](int x) {
            if(x<10) return mapping[x];
            int value=0,i=0;
            while(x>0) {
                value=mapping[x%10]*pow(10,i)+value;
                x/=10;
                i++;
            }
            return value;
        };
        for(int i:nums) mapped_value[i]=generate_value(i);
        sort(nums.begin(),nums.end(),[&](int& a, int& b) {
            return mapped_value[a]<mapped_value[b];
        });
        return nums;
    }
};