class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>tr(n);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) cnt++;
                else break;
            }
            tr[i]=cnt;
        }
        int res=0;
        for(int i=0;i<n;i++){
            int req=n-i-1,j=i;
            while(j<n and tr[j]<req) j++;
            if(j==n) return -1;
            while(j>i){
                swap(tr[j],tr[j-1]);
                res++;
                j--;
            }
        }
        return res;
    }
};