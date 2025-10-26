class Bank {
public:
    vector<long long>b;
    int n;
    Bank(vector<long long>& balance) {
        b=balance;
        n=balance.size();
    }
    
    bool transfer(int acc1, int acc2, long long money) {
        if((acc1>=1 and acc1<=n) and (acc2>=1 and acc2<=n)){
            if(b[acc1-1]>=money){
                b[acc1-1]-=money;
                b[acc2-1]+=money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account >= 1 && account <= n){
            b[account-1] += money;
            return true;
         }
         return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account >= 1 && account <= n){
            if(b[account -1] >= money){
                b[account-1] -= money;
                return true;
            }
            return false;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */