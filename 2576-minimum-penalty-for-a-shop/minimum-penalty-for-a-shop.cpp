class Solution {
public:
    int bestClosingTime(string customers) {
        int res=0,min=0,prefix=0;
        for(int i=0;i<customers.size();i++){
            prefix+=customers[i]=='Y' ? -1 :1;
            cout<<prefix<<" "<<min<<endl;
            if(prefix<min){
                res=i+1;
                min=prefix;
            }
        }
        return res;
    }
};
