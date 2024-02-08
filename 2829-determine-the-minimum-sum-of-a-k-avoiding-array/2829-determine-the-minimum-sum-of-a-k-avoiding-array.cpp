class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> added;
        int sum=0,i=1;
        do {
            if(added.find(i)==added.end() && added.find(k-i)==added.end()) {
                added.insert(i);
                sum+=i;
            }
            i++;
        } while(added.size()<n);
        return sum;
    }
};