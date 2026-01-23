class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0,mask=0;
        for(int b=31;b>=0;b--){
            mask|=(1<<b);
            unordered_set<int>st;
            for(int i:nums){
                st.insert((mask&i));
            }
            int temp=ans|(1<<b);
            for(int i:st){
                if(st.count(temp^i)){
                    ans=temp;
                    break;
                }
            }
        }
        return ans;
    }
};