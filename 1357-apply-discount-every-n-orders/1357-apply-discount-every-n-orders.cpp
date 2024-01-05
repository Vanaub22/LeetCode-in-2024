class Cashier {
public:
    int n,discount,i;
    unordered_map<int,int> priceMap; // Using map for quicker access time
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->i=0;
        this->n=n;
        this->discount=discount;
        int L=products.size();
        for(int i=0;i<L;i++) this->priceMap[products[i]]=prices[i];
    }
    double getBill(vector<int> product, vector<int> amount) {
        this->i++;
        int n=product.size(),bill=0;
        for(int i=0;i<n;i++) bill+=amount[i]*priceMap[product[i]];
        if(this->i%this->n==0) return bill*(double)(100-this->discount)/100;
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */