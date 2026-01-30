class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>pref(n,0),suff(n,0);
        for(int i=1;i<n;i++){
             if(ratings[i]>ratings[i-1]) pref[i]=pref[i-1]+1;
        }
        if(n>1 and ratings[0]>ratings[1]) pref[0]=pref[1]+1;
        for(int i=n-2;i>=0;i--){
             if(ratings[i]>ratings[i+1]) suff[i]=suff[i+1]+1;
        }
        if(n>=2 and ratings[n-1]>ratings[n-2]) suff[n-1]=suff[n-2]+1;
        int res=0;
        for(int i=0;i<n;i++){
            res+=max(pref[i],suff[i]);
            res++;
        }
        return res;
    }
};