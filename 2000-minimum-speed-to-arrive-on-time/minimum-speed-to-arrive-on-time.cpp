class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e9,n=dist.size();
        while(low<high){
            int mid=(low+high)>>1;
            double time=0;
            for(int i=0;i<n-1;i++) time+=(dist[i]+mid-1)/mid;
            time+=(double)dist[n-1]/mid;
            if(time>hour){
                low=mid+1;
            }
            else high=mid;
        }
        if(high==1e9) return -1;
        return high;
    }
};