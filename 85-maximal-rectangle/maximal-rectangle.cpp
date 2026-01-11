class Solution {
public:
    int st[201]={-1},top=0;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        if(row==1 and col==1) return matrix[0][0]=='1';
        int height[201]={0},maxArea=0;
        for(int i=0;i<row;i++){
            top=0;
            for(int j=0;j<=col;j++){
                height[j]=(j==col or matrix[i][j]=='0')?0:height[j]+1;
                while(top>0 and (j==col or height[j]<height[st[top]])){
                    int m=st[top--];
                    int w=j-st[top]-1;
                    int area=height[m]*w;
                    maxArea=max(maxArea, area);
                }
                st[++top]=j;
            }
        }
        return maxArea;
    }
};