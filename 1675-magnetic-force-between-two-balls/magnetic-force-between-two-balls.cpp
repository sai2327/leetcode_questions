class Solution {
public:
    int spirit(vector<int>&arr,int mid){
        int ans=1;
        int last=arr[0],n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]-last>=mid){
                ans++;
                last=arr[i];
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int ans=1,low=1,right=position[n-1]-position[0],mid;
        while(low<=right){
            mid=(right+low)/2;
            int magnets=spirit(position,mid);
            if(magnets>=m){
                ans=mid;
                low=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};