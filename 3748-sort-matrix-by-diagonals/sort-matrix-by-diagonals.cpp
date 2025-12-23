class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &i:mp){
            if(i.first>=0) sort(i.second.begin(),i.second.end());
            else sort(i.second.rbegin(),i.second.rend());
        }

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mat[i][j]=(mp[i-j].back());
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};