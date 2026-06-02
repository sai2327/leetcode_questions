class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mini=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int a=landStartTime[i]+landDuration[i];
                int b=waterStartTime[j]+waterDuration[j];
                int m=max(b,landStartTime[i])+landDuration[i];
                int n=max(a,waterStartTime[j])+waterDuration[j];
                mini=min({mini,n,m});
            }
        }
        return mini;
    }
};