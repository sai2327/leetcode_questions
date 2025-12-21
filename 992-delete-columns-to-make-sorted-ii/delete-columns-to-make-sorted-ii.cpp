class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        unordered_set<int>st;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(st.count(j)>0) continue;
                if(strs[i-1][j]==strs[i][j]) continue;
                if(strs[i-1][j]>strs[i][j]){
                    st.insert(j);
                    i=0;
                }
                break;
            }
        }
        return st.size();
    }
};