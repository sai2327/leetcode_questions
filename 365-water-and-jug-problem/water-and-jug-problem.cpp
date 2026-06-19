class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target)return false;
        int d=gcd(x,y);
        return target%d==0;
    }
};