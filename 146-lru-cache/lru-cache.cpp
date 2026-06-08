class LRUCache {
public:
    int cap;
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()) {
            mp[key]->second=value;
            l.splice(l.begin(), l, mp[key]);
            return;
        }
        if(l.size()==cap) {
            int lruKey=l.back().first;
            mp.erase(lruKey);
            l.pop_back();
        }
        l.push_front({key,value});
        mp[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */