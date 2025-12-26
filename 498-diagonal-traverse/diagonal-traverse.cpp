class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flag= true;
        vector<int> res;
        for(auto &i:mp){
            if(!flag){
                reverse(i.second.begin(),i.second.end());
            }
            while(i.second.size()>=1){
                res.push_back(i.second.back());
                i.second.pop_back();
            }
            if(flag) flag=false;
            else flag=true;
        }
        // for(int i=0;i<mat.size();i++){
        //     for(int j=0;j<mat[i].size() and mat.size();j++){
        //         int a=mp[i].back();
        //         res.push_back(a);
        //         mp[i].pop_back();
        //     }
        // }
        return res;
    }
};