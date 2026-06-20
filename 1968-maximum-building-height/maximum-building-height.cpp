class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1,0});
        sort(rest.begin(),rest.end());
        vector<int>a =rest.back();
        if(a[0]!=n)rest.push_back({n,n-1});
        for(int i=1;i<rest.size();i++){
            int hb=rest[i][0],ha=rest[i-1][0];
            int d=hb-ha;
            rest[i][1]=min(rest[i-1][1]+d,rest[i][1]);
        }
        for(int i=rest.size()-2;i>=0;i--){
            int hb=rest[i+1][0],ha=rest[i][0];
            int d=hb-ha;
            rest[i][1]=min(rest[i+1][1]+d,rest[i][1]);
        }
        int res=0;
        for(int i=0;i<rest.size()-1;i++){
            int hx=rest[i][1],hy=rest[i+1][1],d=rest[i+1][0]-rest[i][0];
            res=max(res,(hx+hy+d)/2);
        }
        return res;
    }
};