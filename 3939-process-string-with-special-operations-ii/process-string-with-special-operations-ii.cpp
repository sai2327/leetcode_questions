class Solution {
public:
    char processStr(string s, long long k) {
        long long cnt=0;
        for(char c:s){
            if(c>='a' and c<='z')cnt++;
            else if(c=='#')cnt*=2;
            else if(c=='*' and cnt>0)cnt--;
        }
        if(k>=cnt) return '.';
        cout<<cnt<<endl;
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            if(c>='a' and c<='z'){
                cnt--;
                if(cnt==k)return c;
            }
            else if(c=='%')k=cnt-k-1;
            else if(c=='#'){
                cnt/=2;
                if(k>=cnt)k-=cnt;
            }
            else if(c=='*' and cnt>0) cnt++;
        }
        return '.';
    }
};