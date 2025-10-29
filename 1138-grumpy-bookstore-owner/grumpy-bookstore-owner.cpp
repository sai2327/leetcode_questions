class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& gr, int min) {
        long long res=0,curr=0;
        for(int i=0;i<cus.size();i++) if(gr[i]==0) res+=cus[i];
        for(int i=0;i<min;i++){
            if(gr[i]==1) curr+=cus[i];
        }
        long long ans=curr;
        for(int i=min;i<cus.size();i++){
            if(gr[i-min]==1) curr-=cus[i-min];
            if(gr[i]==1) curr+=cus[i];
            ans=max(ans,curr);
        }
        return res+ans;
    }
};