class Solution {
public:
    // Uses the concept of sinking, like Bubble Sort, i.e. placing 1 item in one round
    // 2 pancake flips are enough to bring any element to its desired index position
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> kValues;
        for(int toPlace=arr.size();toPlace>0;toPlace--) {
            int idx=find(arr.begin(),arr.end(),toPlace)-arr.begin();
            if(idx==toPlace-1) continue; // It is at its correct index
            // Flip such that toPlace reaches the head
            if(idx!=0) {
                reverse(arr.begin(),arr.begin()+idx+1);
                kValues.push_back(idx+1);
            }
            // Flipping the entire sublist to bring toPlace to the end of sublist
            kValues.push_back(toPlace);
            reverse(arr.begin(),arr.begin()+toPlace);
        }
        return kValues;
    }
};