class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum<0){
            int i=1;
            while(find(nums.begin(),nums.end(),i)!=nums.end())i++;
            return i;
        }
        int avg=sum/nums.size();
        avg++;
        while(find(nums.begin(),nums.end(),avg)!=nums.end()) avg++;
        return avg;
    }
};