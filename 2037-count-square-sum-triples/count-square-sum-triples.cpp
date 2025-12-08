class Solution {
public:
    bool isTrue(int a, int b){
        int sum = a*a + b*b;

        int root = sqrt(sum);

        return root*root == sum;
    }
    int countTriples(int n) {

        int ans =0;

        for(int i=1 ; i<=n ; i++){
            for(int j= i+1 ; j<=n ; j++){
                if(isTrue(i, j) && sqrt(i*i + j*j)<=n){
                    ans+=2;
                }
            }
        }
        return ans;     
    }
};