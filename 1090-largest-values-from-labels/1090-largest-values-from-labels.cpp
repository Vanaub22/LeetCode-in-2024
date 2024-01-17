class Solution {
private:
    // Using a custom datatype for the Items
    struct Item {
        int val,lab;
    };
public:
    static bool comp(Item& a, Item& b) {
        return a.val>b.val;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int sub_len, int lim) {
        int max_score=0,n=values.size();
        unordered_map<int,int> label_cnt; // To keep a count of values chosen under a label
        vector<Item> items(n);
        for(int i=0;i<n;i++) items[i].val=values[i],items[i].lab=labels[i];
        sort(items.begin(),items.end(),comp); // Sorting in decreasing order of values
        for(Item item:items) {
            if(!sub_len) break; // The subset is full
            if(label_cnt[item.lab]<lim) {
                label_cnt[item.lab]++;
                sub_len--;
                max_score+=item.val;
            }
        }
        return max_score;
    }
};