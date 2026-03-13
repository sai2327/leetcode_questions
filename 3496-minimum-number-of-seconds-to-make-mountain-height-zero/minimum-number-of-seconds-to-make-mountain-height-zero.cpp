class Solution {
public:
    long long minNumberOfSeconds(int n, vector<int>& workerTimes) {
        priority_queue<pair<pair<long long,int>,int>,vector<pair<pair<long long,int>,int>>,greater<pair<pair<long long,int>,int>>>A;

        for(int i=0;i<workerTimes.size();i++){
            A.push({{(long long)workerTimes[i],workerTimes[i]},1});
        }

        while(n>0){
            auto op=A.top();A.pop();
            op.second++;
            op.first.first += 1ll * op.first.second * op.second;
            A.push(op);
            // cout<<op.first.first<<" "<<op.first.second<<" "<<op.second<<endl;
            n--;
        }
        int m=A.size();
        vector<long long>b;
        while(m--){
            auto op=A.top();
            op.first.first-= 1ll* op.first.second * op.second;
            A.pop();
            b.push_back(op.first.first);
            cout<<op.first.first<<" "<<op.first.second<<" "<<op.second<<endl;
        }
        return *max_element(b.begin(),b.end());
    }
};