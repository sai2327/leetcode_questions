class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt=0,j=0;
        vector<string>res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
            else cnt--;
            if(cnt==0){
                res.push_back("1"+makeLargestSpecial(s.substr(j+1,i-j-1))+"0");
                j=i+1;
            }
        }
        sort(res.rbegin(),res.rend());
        string ans="";
        for(string s:res) ans+=s;
        return ans;
    }
};