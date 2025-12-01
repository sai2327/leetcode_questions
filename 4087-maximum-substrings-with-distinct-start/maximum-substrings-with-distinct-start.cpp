class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char>s1;
        for(auto &i:s)
        {
            s1.insert(i);
        }
        return s1.size();
    }
};