#define ll long long
class Bank {
public:
    vector<ll> balance;
    Bank(vector<ll>& balance) {
        this->balance=balance;
    }
    
    bool transfer(int acc1, int acc2, ll money) {
        if(balance.size()<acc1 || balance.size()<acc2 || balance[acc1-1]<money) return false;
        balance[acc1-1]-=money;
        balance[acc2-1]+=money;
        return true;
    }
    
    bool deposit(int acc, ll money) {
        if(balance.size()<acc) return false;
        balance[acc-1]+=money;
        return true;
    }
    
    bool withdraw(int acc, ll money) {
        if(balance.size()<acc || balance[acc-1]<money) return false;
        balance[acc-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */