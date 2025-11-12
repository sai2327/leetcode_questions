class Solution {
public:
    bool sumGame(string num) {
       int n=num.size();
       int sum=0,cnt1=0,cnt2=0;
       for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?') cnt1++;
                else sum+=num[i]-'0';
            }
            else{
                if(num[i]=='?') cnt2++;
                else sum-=num[i]-'0';
            }
        }
        if((cnt1+cnt2)%2==1) return true;
        int ans=sum+(cnt1/2)*9-(cnt2/2)*9 ;
        if(ans==0) return false;
        return true;
    }
};