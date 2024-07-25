// Solution without using in-built functions and in O(nlogn) T.C.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<vector<int>(int,int)> merge_sort=[&](int left, int right)->vector<int> {
            if(left==right) return {nums[left]};
            auto merging=[](vector<int>& a, vector<int>& b)->vector<int> {
                int i=0,j=0,m=a.size(),n=b.size();
                vector<int> res;
                while(i<m && j<n) {
                    if(a[i]<b[j]) res.push_back(a[i++]);
                    else res.push_back(b[j++]);
                }
                while(i<m) res.push_back(a[i++]);
                while(j<n) res.push_back(b[j++]);
                return res;
            };
            int mid=left+(right-left)/2;
            vector<int> leftArr=merge_sort(left,mid),rightArr=merge_sort(mid+1,right);
            return merging(leftArr,rightArr);
        };
        return merge_sort(0,nums.size()-1);
    }
};