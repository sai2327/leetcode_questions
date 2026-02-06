class Solution {
public:
    int lastRemaining(int n) {
        long long first=1,gap=1,cnt=n;
        bool removefromleft=true;
        while(cnt>1){
            if(removefromleft or cnt%2==1) first+=gap;
            if(cnt%2==0)cnt/=2;
            else cnt=(cnt-1)/2;
            gap*=2;
            removefromleft=!removefromleft;
        }
        return first;
    }
};