class Solution {
public:
    int wave(vector<int>&a){
        if(a.size()<=2) return 0;
        int cnt=0;
        for(int i=1;i<a.size()-1;i++){
            if((a[i]>a[i-1] and a[i]>a[i+1]) or (a[i]<a[i-1] and a[i]<a[i+1]))cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int res=0;
        for(int i=num1;i<=num2;i++){
            int n=i;
            int cnt=0;
            vector<int>a;
            while(n){
                a.push_back(n%10);
                n/=10;
            }
            res+=wave(a);
        }
        return res;
    }
};