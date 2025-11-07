class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s=to_string(n);
        unordered_map<char,int>mp;
        for(char i:s){
            mp[i]++;
            cout<<i<<" ";
        }
        int ans=INT_MAX;
        char res;
        for(auto i:mp){
            if(ans>i.second){
                ans=i.second;
                res=i.first;
            }
            else if(ans==i.second){
                if(i.first<res) res=i.first;
            }
        }
        return res-'0';
    }
};