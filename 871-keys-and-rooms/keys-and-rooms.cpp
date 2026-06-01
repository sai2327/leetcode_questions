class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        q.push(0);
        unordered_set<int>st;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            st.insert(curr);
            for(int neighbour:rooms[curr]){
                if(st.count(neighbour)==0){
                    q.push(neighbour);
                    st.insert(neighbour);
                }
            }
        }
        return st.size()==rooms.size();
    }
};