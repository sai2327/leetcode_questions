class Solution {
public:
    long long can(vector<int>&a,long long givenTime){
        long long cnt=0;
        for(auto i:a){
            cnt+=(givenTime/i);
        }
        return cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1,h=1e14;
        while(l<h){
            long long mid=(l+h)/2;
            if(can(time,mid)>=totalTrips){
                h=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};