int gcd(int n,int m){
    if(m==0) return n;
    return gcd(m,n%m);
}
int findGCD(int* arr, int n) {
    int max=arr[0],min=arr[0];
    for(int i=1;i<n ;i++){
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
    }
    return gcd(max,min);
}