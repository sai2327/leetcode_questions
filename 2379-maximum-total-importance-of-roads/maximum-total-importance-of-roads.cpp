class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>deg(n,0);
        for(auto e:roads){
            deg[e[0]]++;
            deg[e[1]]++;
        }
        sort(deg.begin(),deg.end());
        long long res=0;
        for(int i=0;i<n;i++){
            res+=deg[i]*(i+1);
        }
        return res;
    }
};