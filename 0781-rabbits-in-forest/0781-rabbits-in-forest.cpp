class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int rabbits=0;
        unordered_map<int,int> response;
        for(int answer:answers) response[answer]++;
        for(auto& r:response) {
            int x=r.first,f=r.second;
            if(x==0 || x+1==f) rabbits+=f;
            else if(x>=f) rabbits+=x+1;
            // If there are rabbits left after grouping into groups of x+1 => Add remaining
            else if(x<f) rabbits=f%(x+1)?rabbits+(x+1)*(f/(x+1))+x+1:rabbits+f;
        }
        return rabbits;
    }
};