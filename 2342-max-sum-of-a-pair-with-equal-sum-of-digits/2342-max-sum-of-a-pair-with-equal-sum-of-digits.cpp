class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res=-1;
        unordered_map<int,vector<int>> ump;
        for(int i:nums) ump[sumOfDigits(i)].emplace_back(i);
        for(auto& it:ump) {
            auto x=it.second;
            if(x.size()>=2) {
                sort(x.begin(),x.end(),greater<int>());
                res=max(res,x[0]+x[1]);
            }
        }
        return res;
    }
private:
    int sumOfDigits(int x) {
        if(!x) return 0;
        int sum=0;
        while(x>0) {
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
};