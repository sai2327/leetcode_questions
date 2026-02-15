class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i:arr) mp[i]++;
        vector<int>freq;
        for(auto i:mp){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        int res=0,removed=0,half=arr.size()/2,i=freq.size()-1;
        while(removed<half){
            res+=1;
            removed+=freq[i--];
        }
        return res;
    }
};