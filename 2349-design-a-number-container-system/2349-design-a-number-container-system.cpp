class NumberContainers {
public:
    unordered_map<int,int> indexNum; // Index to number
    unordered_map<int,set<int>> cont; // Number to indices
    void change(int index, int number) {
        int x=indexNum[index];
        if(x==number) return; // Invalid Change (Same entry)
        indexNum[index]=number;
        cont[number].insert(index);
        cont[x].erase(index);
    }
    int find(int number) {
        return cont[number].empty()?-1:*cont[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */