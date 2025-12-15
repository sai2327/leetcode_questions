class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>m;
    int maxi;
    FreqStack() {
        maxi=0;
    }
    
    void push(int val) {
        maxi=max(maxi,++freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int ans=m[maxi].top();
        m[maxi].pop();
        freq[ans]--;
        if(!m[maxi].size()) maxi--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */