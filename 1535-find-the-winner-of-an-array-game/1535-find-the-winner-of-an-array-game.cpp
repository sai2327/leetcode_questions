class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()) return *max_element(arr.begin(),arr.end());
        int cur=arr[0],win=0;
        for(int i=1;i<arr.size();i++){
            if(cur>arr[i])win++;
            else{
                cur=arr[i];
                win=1;
            }
            if(win==k){
                return cur;
            }
        }
        return cur;
    }
};