class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int idxs=0,sum=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            if(idxs==sum){
                cnt++;
                idxs=0;
                sum=0;
            }
            idxs+=i;
            sum+=arr[i];
        }
        return cnt;
    }
};