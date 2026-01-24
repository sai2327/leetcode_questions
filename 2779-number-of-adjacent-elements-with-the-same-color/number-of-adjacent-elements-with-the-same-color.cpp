class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>A(n,0);
        vector<int>B(queries.size(),0);
        int cnt=0;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int op=A[x]; 
            if(op==y){
                B[i]=cnt;
                continue;
            }
            if(x==0){
                if((x+1)<n && A[x]!=0 && op==A[x+1] && y!=A[x+1]){
                    cnt--;
                }
            }
            if(x==(n-1)){
                if((x-1)>=0 && A[x]!=0 && op==A[x-1] && y!=A[x-1]){
                    cnt--;
                }
            }
            if(x!=0&&x!=(n-1)){
                if(op!=0 && op==A[x+1] && y!=A[x+1]){
                    cnt--;
                }
                if(op!=0 && op==A[x-1] && y!=A[x-1]){
                    cnt--;
                }
            }
            A[x]=y;
            if(x==0){
                if((x+1)<n &&  A[x]!=0 && A[x]==A[x+1]){
                   cnt++;
                }
            }
            if(x==(n-1)){
                if((x-1)>=0 && A[x]!=0 && A[x]==A[x-1] ){
                    cnt++;
                }
            }
             if(x!=0&&x!=(n-1)){
                if(A[x]!=0 && A[x]==A[x+1]){
                    cnt++;
                }
                if(A[x]!= 0 && A[x]==A[x-1]){
                    cnt++;
                }
           }
            B[i]=cnt;
        }
        return B;
    }
};