#define pii pair<int,int>
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.second<b.second;
    } 
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        int n=arr.size();
        for(int i:arr) freq[i]++;
        priority_queue<pii,vector<pii>,function<bool(pii,pii)>> pq(comp);
        for(auto it:freq) pq.push(it);
        int minSize=0,arrSize=n;
        while(!pq.empty() && arrSize>n/2) {
            arrSize-=pq.top().second;
            minSize++;
            pq.pop();
        }
        return minSize;
    }
};