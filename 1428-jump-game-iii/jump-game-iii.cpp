class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return start>=0 and start<arr.size() and arr[start]>=0 and (!(arr[start]=-arr[start]) or canReach(arr,start-arr[start]) or canReach(arr,start+arr[start]));
    }
};