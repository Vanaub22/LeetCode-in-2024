class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size(),boats=0,left=0,right=n-1;
        sort(people.begin(),people.end());
        while(left<=right && left<n && right>=0) {
            if(people[left]+people[right]<=limit) {
                left++;
                right--;
            }
            else {
                if(people[left]>=people[right]) left++;
                else right--;
            }
            boats++;
        }
        return boats;
    }
};