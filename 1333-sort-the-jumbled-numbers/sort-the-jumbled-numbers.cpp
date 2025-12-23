class Solution {
public:
    int transform(int num,const vector<int>& mapping){
        if(num==0) return mapping[0];
        int res=0,place=1;
        while(num){
            res+=mapping[num%10]*place;
            num/=10;
            place*=10;
        }
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping,vector<int>& nums){
        struct Node{
            int val;
            int idx;
            int orig;
        };
        vector<Node> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({transform(nums[i],mapping),i,nums[i]});
        }
        sort(v.begin(),v.end(),[](const Node& a,const Node& b){
            if(a.val!=b.val)
                return a.val<b.val;
            return a.idx<b.idx;
        });
        for(int i=0;i<nums.size();i++){
            nums[i]=v[i].orig;
        }
        return nums;
    }
};
