class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n){
        vector<int>res(n,0);
        for(auto i:bookings){
            res[i[0]-1]+=i[2];
            if(i[1]<n)res[i[1]]-=i[2];
            if(i[1]<n)cout<<res[i[0]-1
            ]<<" "<<res[i[1]]<<" ";
        }
        cout<<endl;
        for(int i:res) cout<<i<<" ";
        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }
        return res;
    }
};