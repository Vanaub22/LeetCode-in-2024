class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1]==b[1]?a[0]>b[0]:a[1]>b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;
        vector<int> ans;
        for(auto& r:restaurants) if(r[3]<=maxPrice && r[4]<=maxDistance) filtered.emplace_back(r);
        sort(filtered.begin(),filtered.end(),comp);
        for(auto& restaurant:filtered) {
            if(veganFriendly) {
                if(restaurant[2]==1) ans.emplace_back(restaurant[0]);
            }
            else ans.emplace_back(restaurant[0]);
        }
        return ans;
    }
};