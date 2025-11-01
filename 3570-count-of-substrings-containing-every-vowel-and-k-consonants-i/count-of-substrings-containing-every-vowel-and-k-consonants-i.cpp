#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sub(string word,int k){
        string vowel="aeiou";
        int i=0,j=0,n=word.size();
        int cnt = 0;
        int c= 0;
        unordered_map<char, int> mp;

        while(j < n){
            if(vowel.find(word[j])!=string::npos){
                mp[word[j]]++;
            }else{
                c++;
            }
            while(c > k && mp.size() == 5){
                if(vowel.find(word[i])!=string::npos){
                    mp[word[i]]--;
                    if(mp[word[i]] == 0) mp.erase(word[i]);
                }else{
                    c--;
                }
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    int countOfSubstrings(string word, int k) {
        return sub(word,k) - sub(word,k-1);
    }
};
