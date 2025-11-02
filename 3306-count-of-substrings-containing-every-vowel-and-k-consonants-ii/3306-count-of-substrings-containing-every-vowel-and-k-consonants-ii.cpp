class Solution {
public:
    long long sub(string word,int k){
        string vowel="aeiou";
        long long i=0,j=0,n=word.size();
        long long cnt=0,c=0;
        unordered_map<char,long long> mp;
        while(j<n){
            if(vowel.find(word[j])!=string::npos)
                mp[word[j]]++;
            else
                c++;
            while(c>k && mp.size()==5){
                if(vowel.find(word[i])!=string::npos){
                    mp[word[i]]--;
                    if(mp[word[i]]==0) mp.erase(word[i]);
                }else c--;
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    long long countOfSubstrings(string word,int k){  // changed int → long long
        long long a=sub(word,k); 
        long long b=sub(word,k-1);
        return a-b;
    }
};
