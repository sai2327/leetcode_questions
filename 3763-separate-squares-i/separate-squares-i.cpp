class Solution {
public:
    double total;
    double areabelow(double y,vector<vector<int>>& squares){
        double area=0;
        for(auto &s:squares){
            if(y<=s[1]) continue;
            if(y>=s[2]+s[1]) area+=1.0*s[2]*s[2];
            else area+=s[2]*(y-s[1]);
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low=1e18,high=-1e18;
        total=0;
        for(auto &s:squares){
            low=min(low,(double)s[1]);
            high=max(high,(double)(s[1]+s[2]));
            total+=1.0*s[2]*s[2];
        }
        for(int i=0;i<100;i++){
            double mid=(low+high)/2;
            if(areabelow(mid,squares)*2<total) low=mid;
            else high=mid;
        }
        return low;
    }
};