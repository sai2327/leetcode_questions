class BrowserHistory {
public:
    stack<string >h;
    stack<string>f;
    BrowserHistory(string homepage) {
        while(!h.empty()) h.pop();
        while(!f.empty()) f.pop();
        h.push(homepage);
        
    }
    
    void visit(string url) {
        h.push(url);
        while(!f.empty()) f.pop();
    }
    
    string back(int steps) {
        while(steps and h.size()>1){
            f.push(h.top());
            h.pop();
            steps--;
        }
        return h.top();
    }
    
    string forward(int steps) {
        while(steps and !f.empty()){
            h.push(f.top());
            f.pop();
            steps--;
        }
        return h.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */