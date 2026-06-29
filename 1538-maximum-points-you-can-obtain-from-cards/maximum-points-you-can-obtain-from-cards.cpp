class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>nums;
        for(int i=cardPoints.size()-k;i<cardPoints.size();i++)nums.push_back(cardPoints[i]);
        int sum=0,res=0;
        for(int i=0;i<k;i++){
            nums.push_back(cardPoints[i]);
            sum+=nums[i];
        }
        res=sum;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            res=max(res,sum);
        }
        return res;
    }
};