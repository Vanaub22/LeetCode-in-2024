/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

#define umap unordered_map
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Will be using some new data structures for O(1) fetching
        umap<int,int> imp;
        umap<int,vector<int>> sub;
        for(auto& employee:employees) {
            imp[employee->id]=employee->importance;
            sub[employee->id]=employee->subordinates;
        }
        int res=0;
        dfs(id,imp,sub,res);
        return res;
    }
    void dfs(int id, umap<int,int>& imp, umap<int,vector<int>>& sub, int& res) {
        res+=imp[id]; // Adding the importance value of the current employee
        for(int subordinate:sub[id]) dfs(subordinate,imp,sub,res);
    }
};