class Solution {
public:
    int numberOfWays(string corridor) {
        int mod=1e9+7;
        vector<int>pos;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S')pos.push_back(i);
        }
        if(pos.size()%2==1 or pos.size()==0) return 0;
        long long res=1;
        for(int i=2;i<pos.size();i+=2){
            int gap=pos[i]-pos[i-1];
            cout<<res<<" ";
            res=(res*gap)%mod;
        }
        return res;
    }
};