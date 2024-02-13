class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(int asteroid:asteroids) if(asteroid<=mass) mass+=asteroid;
        else return false;
        return true;
    }
};