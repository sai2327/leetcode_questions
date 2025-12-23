class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n=arr.length;
        int [] pre=new int[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^arr[i];
        }
        int[] res=new int[queries.length];
        for(int i=0;i<queries.length;i++){
            int x=queries[i][0];
            int y=queries[i][1];
            if(x==0) res[i]=pre[y];
            else res[i]=pre[y]^pre[x-1];
        }
        return res;
    }
}