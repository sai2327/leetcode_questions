class Solution {
public:
    bool isPrime(int n){
        if(n%2 == 0) return false;
        for(int i = 3; i * i<=n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    bool isPalindrome(int n){
        int num = n,rev = 0;
        while(num > 0){
            rev  = rev*10 + num % 10;
            num /= 10;
        };
        return n==rev;
    }
    
    int primePalindrome(int n) {
        if(n==1 || n==2) return 2;
        int i;
        if(n%2 == 0) i = n+1;
        else i=n;
        while(true){
            if(isPalindrome(i) && isPrime(i)) return i;
            i += 2;
            if(i > 1e7 && i < 1e8) i = 1e8 + 1;
            if(i > 1e5 && i < 1e6) i = 1e6 + 1;
            if(i > 1e3 && i < 1e4) i = 1e4 + 1;
            if(i > 11 && i < 100) i = 101;
        }
        return -1;
    }
};