class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(t%2==1 or t<2*c or t>4*c) return{};
        return {(t-c*2)/2,(4*c-t)/2};
    }
};