class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(),s.rend());
        string res;
        int freq=1,idx=0;
        for(int i=0;i<s.size();i++){
            if(!res.empty() and res.back()==s[i]){
                if(freq<repeatLimit){
                    res+=s[i];
                    freq++;
                }
                else{
                    idx=max(idx,i+1);
                    while(idx<s.size() && s[idx]==s[i]){
                        idx++;
                    }
                    if (idx<s.size()){
                        res+=s[idx];
                        swap(s[i],s[idx]);
                        freq=1;
                    } 
                    else break;
                }
            }
            else{
                res+=s[i];
                freq=1;
            }
        }
        return res;
    }
};