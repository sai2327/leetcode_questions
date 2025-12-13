class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>res;
        vector<string>a={"electronics", "grocery", "pharmacy", "restaurant"};
        vector<pair<string,string>>isValid;
        for(int i=0;i<code.size();i++){
            if(isActive[i] and find(a.begin(),a.end(),businessLine[i])!=a.end()){
                string s=code[i];
                bool flag=true;
                for(char j:s){
                    if(!isalnum(j) and j!='_') flag=false;
                }
                if(flag) isValid.push_back({businessLine[i],code[i]});
            }
        }
        sort(isValid.begin(),isValid.end());
        for(auto i:isValid){

            if(i.second!="")res.push_back(i.second);
        }
        return res;
    }
};