class Solution {
public:
    bool judgeCircle(string moves) {
        int k=0,j=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') j--;
            if(moves[i]=='R') j++;
            if(moves[i]=='U') k++;
            if(moves[i]=='D') k--;
        }
        if(k==0 && j==0) return true;
        return false;
    }
};