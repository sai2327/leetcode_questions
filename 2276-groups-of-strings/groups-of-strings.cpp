class Solution {
public:
    int findPar(int u,vector<int>& Par){
        if(u == Par[u])return u;
        return Par[u] = findPar(Par[u],Par);
    }
    void Union(int u,int v,vector<int>& Par,vector<int>& Rnk){
        int up = findPar(u,Par);
        int vp = findPar(v,Par);
        if(up == vp)return;
        if(Rnk[up] < Rnk[vp])Par[up] = vp;
        else if(Rnk[vp] < Rnk[up])Par[vp] = up;
        else{
            Par[vp] = up;
            Rnk[up]++;
        }
        return;
    }
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        vector<int>Mask(n),Par(n),Rnk(n);
        map<int,vector<int>>Idx;
        for(int i = 0; i < n; i++){
            Par[i] = i;
            for(int j = 0; j < words[i].size(); j++){
                Mask[i] |= 1 << (words[i][j] - 'a');
            }
            Idx[Mask[i]].push_back(i);
            int l = Idx[Mask[i]].size();
            if(l <= 1)continue;
            Union(Idx[Mask[i]][l - 2],i,Par,Rnk);
        }
        for(auto& b : Idx){
            int mask = b.first;
            for(int i = 0; i < 26; i++){
                if(mask & (1 << i)){
                    // delete
                    int temp = mask ^ (1 << i);
                    if(Idx.count(temp))Union(b.second[0],Idx[temp][0],Par,Rnk);
                    //replace
                    for(int j = 0; j < 26; j++){
                        if(!(mask & (1 << j))){
                            int val=temp |(1 << j);
                            if(Idx.count(val)){
                                Union(b.second[0],Idx[val][0],Par,Rnk);
                                cout << "Y";
                            }
                        }
                    }

                }else{
                    // add
                    int temp = mask | (1 << i);
                    if(Idx.count(temp))Union(b.second[0],Idx[temp][0],Par,Rnk);
                }

            }

        }


        for(int i = 0; i < n; i++){
            Par[i] = findPar(Par[i],Par);
        }
        map<int,int>mpp;
        for(int& p : Par)mpp[p]++;
        int maxi = 0;
        for(auto b : mpp)maxi = max(maxi,b.second);
        return {(int)mpp.size(),maxi};
    }
};