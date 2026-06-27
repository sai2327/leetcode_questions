class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums)mp[i]++;
        int res=1;
        if(mp.count(1)){
            int cnt=mp[1];
            if(cnt%2){
                res=max(res,cnt);
            }
            else res=max(res,cnt-1);
            // cout<<cnt<<" ";
        }
        // for(auto i:mp) cout<<i.first<<" "<<i.second;
        for(auto &i:mp){
            if(i.first==1)continue;
            long long x=i.first;
            int len=0;
            while(mp.count(x) && mp[x]>=2){
                len+=2;
                x=x*x;
                if(x>=1e5) break;
                
            }
            if(mp.count(x))
                len++;
            else
                len--;
            res=max(res, len);
        }
        return res;
    }
};
