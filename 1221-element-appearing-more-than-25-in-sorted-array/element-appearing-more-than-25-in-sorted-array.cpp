class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int cnt=0,res=0;
        for(auto i:mp){
            if(i.second>cnt){
                cnt=i.second;
                res=i.first;
            }
        }
        return res;
    }
};