class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1),st;
        for(int i=0;i<2*n;i++){
            int curr=nums[i%n];
            while(!st.empty() and nums[st.back()]<nums[i%n]){
                res[st.back()]=nums[i%n];
                st.pop_back();
            }
            st.push_back(i%n);
        }
        return res;
    }
};