class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1,0),res;
        unordered_set<char>vowels={'a','e','i','o','u'}; 
        for (int i=0;i<n;i++){
            prefix[i+1]=prefix[i];
            if(vowels.count(words[i].front()) and vowels.count(words[i].back())){
                prefix[i+1]++; 
            }
        }
        for(auto i:queries){
            int l=i[0],r=i[1];
            res.push_back(prefix[r+1]-prefix[l]);
        }
        return res;
    }
};