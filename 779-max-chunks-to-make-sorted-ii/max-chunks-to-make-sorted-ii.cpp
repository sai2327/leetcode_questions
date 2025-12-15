class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>sorted(arr.begin(),arr.end());
        sort(sorted.begin(),sorted.end());
        long long  s=0,ss=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            ss+=sorted[i];
            if(s==ss)
                cnt++;
        }
        return cnt;
    }
};