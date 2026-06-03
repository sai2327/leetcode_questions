class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int a=landStartTime[0]+landDuration[0];
        for(int i=0;i<landStartTime.size();i++){
            a=min(a,landStartTime[i]+landDuration[i]);
        }
        int b=waterStartTime[0]+waterDuration[0];
        for(int i=1;i<waterDuration.size();i++){
            b=min(b,waterStartTime[i]+waterDuration[i]);
        }
        int res1=INT_MAX,res2=INT_MAX;
        for(int i=0;i<landDuration.size();i++){
            int n=max(0,landStartTime[i]-b);
            res2=min(res2,landDuration[i]+n);
        }
        for(int i=0;i<waterDuration.size();i++){
            int n=max(0,waterStartTime[i]-a);
            res1=min(res1,waterDuration[i]+n);
        }
        a+=res1;
        b+=res2;

        return min(a,b);
    }
};