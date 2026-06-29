class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0,l=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp.size()==3){
                cnt+=s.size()-i;
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
        }
        return cnt;
    }
};