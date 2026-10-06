class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(int i=0;i<asteroids.size();i++){
            bool flag=false;
            while(!st.empty() and asteroids[i]<0 and st.back()>0){
                if(st.back()<-asteroids[i]){
                    st.pop_back();
                    continue;
                }
                else if(st.back()==-asteroids[i]){
                    st.pop_back();
                }
                flag=true;
                break;
            }
            if(!flag){
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};