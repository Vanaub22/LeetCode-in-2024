class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> ump;
        for(int i=0;i<arr2.size();i++) ump[arr2[i]]=i;
        sort(arr1.begin(),arr1.end(),[&](int& a, int& b) {
            unordered_map<int,int>::iterator itra=ump.find(a),itrb=ump.find(b);
            if(itra==ump.end() && itrb==ump.end()) return a<b;
            else if(itra==ump.end()) return false;
            else if(itrb==ump.end()) return true;
            else return ump[a]<ump[b];
        });
        return arr1;
    }
};