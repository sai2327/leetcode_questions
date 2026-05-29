class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=1e9;
        while(low<high){
            int mid=(low+high)/2,need=1,curr=0;
            for(int i=0; i<weights.size() and need<=days;i++){
                if(curr+weights[i]>mid){
                    curr=0;
                    need++;
                }
                curr+=weights[i];
            }
            if(need>days) low=mid+1;
            else high=mid;
        }
        return low;
    }
};