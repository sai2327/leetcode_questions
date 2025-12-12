class Solution {
public:
    struct event{
        string type;
        int time;
        string data;
    };
    static bool cmp(const event &a,const event &b){
        if(a.time!=b.time) return a.time<b.time;
        if(a.type!=b.type){
            if(a.type=="OFFLINE") return true;
            if(b.type=="OFFLINE") return false;
        }
        return false;
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>mentions(n,0),onlineUntil(n,0);
        
        vector<event>ev;
        for(auto e:events){
            ev.push_back({e[0],stoi(e[1]),e[2]});
        }
        sort(ev.begin(),ev.end(),cmp);
        for(auto e:ev){
            int currtime=e.time;
            for(int i=0;i<n;i++){
                if(onlineUntil[i]!=0 and currtime>=onlineUntil[i]) onlineUntil[i]=0;
            }
            if(e.type=="OFFLINE"){
                int id=stoi(e.data);
                onlineUntil[id]=currtime+60;
            }
            else{
                if(e.data=="ALL"){
                    for(int i=0;i<n;i++) mentions[i]++;
                }
                else if(e.data=="HERE"){
                    for(int i=0;i<n;i++){
                        if(onlineUntil[i]==0) mentions[i]++;
                    }
                }
                else{
                    stringstream ss(e.data);
                    string word;
                    while(ss>>word){
                        int id=stoi(word.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};