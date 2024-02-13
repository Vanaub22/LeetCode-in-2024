class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long planet_mass=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int asteroid:asteroids) if(asteroid<=planet_mass) planet_mass+=asteroid;
        else return false;
        return true;
    }
};