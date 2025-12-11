class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>>minmaxx(n+1,{n+1,0});
        vector<pair<int,int>>minmaxy(n+1,{n+1,0});
        for(auto b:buildings){
            minmaxx[b[1]].first=min(b[0],minmaxx[b[1]].first);
            minmaxx[b[1]].second=max(b[0],minmaxx[b[1]].second);
            minmaxy[b[0]].first=min(b[1],minmaxy[b[0]].first);
            minmaxy[b[0]].second=max(b[1],minmaxy[b[0]].second);
        }
        int res=0;
        for(auto i:buildings){
            int x=i[0],y=i[1];
            if(minmaxx[y].first<x and minmaxx[y].second>x and minmaxy[x].first< y and minmaxy[x].second>y){
                res+=1;
            }
        }
        return res;
    }
};