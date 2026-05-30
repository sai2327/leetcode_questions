class Solution {
public:
    bool can(vector<int>&ranks,int cars,long long mid){
        long long cnt=0;
        for(int i:ranks){
            long long temp=mid/i;
            cnt+=floor(sqrt(temp));
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=0,high=1e15;
        while(low<high){
            long long mid=(low+high)/2;
            if(can(ranks,cars,mid))high=mid;
            else low=mid+1;
        }
        return low;
    }
};