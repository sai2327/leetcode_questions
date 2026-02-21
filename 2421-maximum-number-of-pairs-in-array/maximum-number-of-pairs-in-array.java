class Solution {
    public int[] numberOfPairs(int[] nums) {
        int freq[]=new int[101];
        for(int i:nums){
            freq[i]++;
        }
        int ans[]=new int[2];
        for(int i:freq){
            if(i>0 && i%2==1) ans[1]++;
            ans[0]+=i/2;
        }
        return ans; 
    }
}