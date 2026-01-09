class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>smp(10,0),gmp(10,0);
        int bulls=0,cows=0;
        for(int i=0;i<secret.size();i++){
            int a=secret[i]-'0',b=guess[i]-'0';
            if(a==b) bulls++;
            else{
                smp[a]++;
                gmp[b]++;
            }
        }
        for(int i=0;i<10;i++) cows+=min(smp[i],gmp[i]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};