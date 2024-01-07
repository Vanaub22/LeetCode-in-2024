class Solution {
public:
    vector<long long> sumOfThree(long long x) {
        return x%3?vector<long long>{}:vector<long long>{x/3-1,x/3,x/3+1};
    }
};