/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * (*matrixColSize);
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int top=0,bottom=matrixSize-1,left=0,right=*matrixColSize-1,index=0;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++) result[index++]=matrix[top][i];
        top++;
        for(int i=top;i<=bottom;i++) result[index++]=matrix[i][right];
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--) result[index++]=matrix[bottom][i];
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--) result[index++]=matrix[i][left];
            left++;
        }
    }
    return result;
}