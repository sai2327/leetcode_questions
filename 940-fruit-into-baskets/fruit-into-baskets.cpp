class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res=0;
        map<int,int>mp;
        int l=0,cnt=0;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++; 
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};