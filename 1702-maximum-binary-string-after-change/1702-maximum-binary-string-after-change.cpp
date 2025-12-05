class Solution {
public:
    string maximumBinaryString(string binary) {
        int so=0,o=0,z=0;
        string res="";
        for(char i:binary){
            if(i=='1') so++;
            else break;
        }
        for(int i=so;i<binary.size();i++){
            if(binary[i]
            =='1') o++;
            else z++;
        }
        for(int i=0;i<so;i++) res+='1';
        for(int i=0;i<z-1;i++) res+='1';
        if(z>0) res+='0';
        for(int i=0;i<o;i++) res+='1';
        return res; 
    }
};