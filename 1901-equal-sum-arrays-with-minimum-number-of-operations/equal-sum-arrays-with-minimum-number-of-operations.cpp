class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1=0,s2=0;
        for(int i=0;i<nums1.size();i++) s1+=nums1[i];
        for(int i=0;i<nums2.size();i++) s2+=nums2[i];
        priority_queue<int>pq;
        if(s1>s2){
            for(int i=0;i<nums1.size();i++) pq.push(nums1[i]-1);
            for(int i=0;i<nums2.size();i++) pq.push(6-nums2[i]);
        }
        else{
            for(int i=0;i<nums1.size();i++) pq.push(6-nums1[i]);
            for(int i=0;i<nums2.size();i++) pq.push(nums2[i]-1);
        }
        int cnt=0,diff=abs(s1-s2);
        while(diff>0 and pq.size()){
            int top=pq.top();
            pq.pop();
            diff-=min(diff,top);
            cnt++;
        }
        if(diff>0) return -1;
        return cnt;
    }
};