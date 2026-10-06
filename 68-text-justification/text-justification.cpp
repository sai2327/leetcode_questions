class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int sum=0,cnt=0;
        for(int i=0;i<words.size();i++){
            string s="";
            sum=0,cnt=0;
            sum+=words[i].size();
            // s+=words[i];
            // if(s.size()!=maxWidth)s+=" ";
            cnt++;
            int j=i+1;
            while(j<words.size() and sum+cnt+words[j].size()<=maxWidth){
                sum+=words[j].size();
                cnt++;
                j++;
            }
            if(j==words.size()){
                for(int k=i;k<j;k++){
                    s+=words[k];
                    if(k!=j-1)s+=" ";
                }
                while(s.size()<maxWidth)
                    s+=" ";
                res.push_back(s);
                break;
            }
            if(cnt==1){
                s=words[i];
                while(s.size()<maxWidth)s+=" ";
                res.push_back(s);
                continue;
            }
            int spaces=maxWidth-sum;
            int gap=spaces/(cnt-1),extra=spaces%(cnt-1);
            for(int k=i;k<j;k++){
                s+=words[k];
                if(k!=j-1){
                    s+=string(gap,' ');
                    if(extra>0){
                        s+=" ";
                        extra--;
                    }
                }
            }
            res.push_back(s);
            i=j-1;
        }
        return res;
    }
};