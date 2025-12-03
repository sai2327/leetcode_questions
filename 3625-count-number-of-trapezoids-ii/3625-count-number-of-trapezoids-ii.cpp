class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size(),inf=INT_MAX,ans=0;
        unordered_map<float,vector<float>> slopeintercept;
        map<pair<int,int>,vector<float>> slopemid;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int dx=(x2-x1);
                int dy=(y2-y1);
                float m,c;
                if(x2==x1){
                    m=inf;
                    c=x1;
                }
                else{
                    m=float(y2-y1)/(x2-x1);
                    c=(float)(y1*dx-x1*dy)/dx;
                }
                pair<int,int> mid={x1+x2,y1+y2};
                slopeintercept[m].push_back(c);
                slopemid[mid].push_back(m);
            }
        }
        for(auto i:slopeintercept){
            if(i.second.size()==1) continue;
            unordered_map<float,int>cnt;
            for(auto j:i.second) cnt[j]++;
            int sum=0;
            for(auto j:cnt){
                ans+=sum*j.second;
                sum+=j.second;
            }
        }
        for(auto i:slopemid){
            if(i.second.size()==1) continue;
            unordered_map<float,int> cnt;
            for(auto j:i.second) cnt[j]++;
            int sum=0;
            for(auto j:cnt){
                ans-=sum*j.second;
                sum+=j.second;
            }
        }
        return ans;
    }
};