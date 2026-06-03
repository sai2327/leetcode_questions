class Solution {
public:
    int reinitializePermutation(int n) {
        int cnt=0;
        vector<int>perm(n,0),arr(n);
        for(int i=0;i<n;i++)perm[i]=i;
        int total=n;
        while(1){
            cnt++;
            for(int i=0;i<n;i++){
                if(i%2==0) arr[i]=perm[i/2];
                else arr[i]=perm[n/2+(i-1)/2];
            }
            int m=0;
            for(int i=0;i<n;i++) if(arr[i]==i) m++;
            if(m==n)return cnt; 
            perm=arr;
        }
        return 1;
    }
};