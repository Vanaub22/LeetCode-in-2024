class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size(),totalSkill=skill[0]+skill[n-1];
        long long chemistry=skill[0]*skill[n-1];
        for(int i=1;i<n/2;i++) {
            if(skill[i]+skill[n-i-1]==totalSkill) chemistry+=skill[i]*skill[n-i-1];
            else return -1;
        }
        return chemistry;
    }
};