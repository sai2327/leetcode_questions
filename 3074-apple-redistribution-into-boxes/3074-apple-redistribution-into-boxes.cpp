class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples=0;
    for(int app : apple) totalApples+=app;
    if (totalApples == 0) {
        return 0;
    }
    sort(capacity.begin(), capacity.end(),greater<int>());
    int currentCapacity = 0;
    int boxesUsed = 0;
    for (int cap : capacity) {
        currentCapacity += cap;
        boxesUsed++;
        if (currentCapacity >= totalApples) {
            return boxesUsed;
        }
    }
    return -1;
    
    }
};