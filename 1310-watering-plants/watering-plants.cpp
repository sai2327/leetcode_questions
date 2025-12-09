class Solution {
public:
    int wateringPlants(vector<int>& p, int ca) {
        int i,ans=0,x=ca;
        for(i=0;i<p.size();i++){
            if(x >= p[i]){
                x -= p[i];
                ans += 1;
            }
            else{
                x = ca;
                ans += 2*i;
                x -= p[i];
                ans += 1;
            }
        }
        return ans;
    }
};