class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int c=0,s=0;
        for(int i=0;i<n;i++){
            if(s+costs[i]<=coins){
                s+=costs[i];
                c++;
            }
            else break;
        }
        return c;
    }
};