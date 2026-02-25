class Solution {
public:
    int cnt(int n){
        int cnt=0;
        while(n){
            n=n&n-1;
            cnt++;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>res;
        for(int i=0;i<arr.size();i++){
            int j=cnt(arr[i]);
            res.push_back({j,arr[i]});
        }
        sort(res.begin(),res.end());
        vector<int>ans;
        for(auto it:res){
            ans.push_back(it.second);
        }
        return ans;
    }
};