char* addBinary(char* a, char* b) {
    int num1=strlen(a),num2=strlen(b);
    int max=(num1>num2?num1:num2)+1;
    char* result=(char*)malloc(max+1);
    result[max]='\0';
    int carry=0,i=num1-1,j=num2-1,k=max-1;
    while (i>=0||j>=0||carry){ 
        int sum=carry;
        if(i>=0) sum+=a[i--]-'0';
        if(j>=0) sum+=b[j--]-'0';
        result[k--]=(sum % 2)+'0';
        carry=sum/2;
    }
    return result+k+1;
}