class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n,0);
        stack<int>st;
        int prev=0;
        for(auto i:logs){
            int a=i.find(':');
            int b=i.find(':',a+1);
            int id=stoi(i.substr(0,a));
            string sore=i.substr(a+1,b-a-1);
            int time=stoi(i.substr(b+1));
            if(sore=="start"){
                if(!st.empty()){
                    ans[st.top()]+=(time-prev);
                }
                st.push(id);
                prev=time;
            }
            else{
                ans[st.top()]+=(time-prev+1);
                st.pop();
                prev=time+1;
            }
        }
        return ans;
    }
};